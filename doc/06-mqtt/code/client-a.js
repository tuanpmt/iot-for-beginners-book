var mqtt = require('mqtt')
var client = mqtt.connect('mqtt://iot.eclipse.org')

client.on('connect', function() {
    console.log('Client A connected')
    client.subscribe('/client-a/sub')

})

client.on('message', function(topic, message) {
    // message is Buffer
    console.log(message.toString())
    client.publish('/client-b/sub', 'Hello from client A')
    client.end()
})
console.log('Client A started')
