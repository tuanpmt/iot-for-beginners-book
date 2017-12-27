// declare a "mqtt" variable to use mqtt module's features.
var mqtt = require('mqtt')
// declare a "client" variable and use the "connect" attribute to connect to a MQTT broker with hostname mqtt://iot.eclipse.org
var client = mqtt.connect('mqtt://iot.eclipse.org')
// This function will subscribe to a topic after successfully connecting to broker.
client.on('connect', function() {
    console.log('Client B connected')
    // subscribe to the topic /client-b/sub
    client.subscribe('/client-b/sub')
    // publish the message 'Hello from client B' to topic /client-a/sub
    client.publish('/client-a/sub', 'Hello from client B')
})
client.on('message', function(topic, message) {
    // print to console a "string" type message.
    console.log(message.toString())
    // disconnect from server
    client.end()
})
console.log('Client B started')