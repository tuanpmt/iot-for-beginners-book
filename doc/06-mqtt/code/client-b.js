var mqtt = require('mqtt')
var client = mqtt.connect('mqtt://iot.eclipse.org')

client.on('connect', function() {
    console.log('Client B connected')
    client.subscribe('/client-b/sub')
    client.publish('/client-a/sub', 'Hello from client B')
})

client.on('message', function(topic, message) {
    // message is Buffer
    console.log(message.toString())
    client.end()
})
console.log('Client B started')
