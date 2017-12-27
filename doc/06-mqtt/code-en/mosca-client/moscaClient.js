// declare a "mqtt" variable to use mqtt module's features.
var mqtt = require('mqtt');
// Connect to port 1883 on 192.168.1.7 using MQTT protocol
var client = mqtt.connect('mqtt://192.168.1.7:1883');
// When a "connect" event arrives at server, client will subscribe the topic "MQTTlens/test/3"
// and publish a message "on" to topic "hello/world" to turn on LED on ESP8266 WiFi Uno.
client.on('connect', function() {
    client.subscribe('Broker/app');
    client.publish('esp8266/GPIO16', 'on');
})
// When a message is delivered to a client, client will convert data in buffer to string
// and print the content to console and close connection.
client.on('message', function(topic, message) {
    // message is Buffer
    console.log(message.toString());
    //client.end();
})