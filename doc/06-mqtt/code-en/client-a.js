// declare a "mqtt" variable to use mqtt module's features.
var mqtt = require('mqtt')
// declare a "client" variable and use the "connect" attribute to connect to a MQTT broker with hostname mqtt://iot.eclipse.org
var client = mqtt.connect('mqtt://iot.eclipse.org')
// This function subscribes to a topic after successfully connecting to broker.
client.on('connect', function() {
    console.log('Client A connected')
    // subscribe to the topic /client-a/sub
    client.subscribe('/client-a/sub')
})
// This function sends a message to subscribed topic.
client.on('message', function(topic, message) {
    // print to console a "string" type message.
    console.log(message.toString())
    // publish the message 'Hello from client A' to topic /client-b/sub
    client.publish('/client-b/sub', 'Hello from client A')
    // disconnect from server
    client.end()
})
console.log('Client A started')