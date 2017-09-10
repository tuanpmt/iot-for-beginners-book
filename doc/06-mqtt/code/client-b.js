// tạo biến mqtt sử dụng các chức năng của module mqtt 
var mqtt = require('mqtt') 
// tạo biến client sử dụng thuộc tính connect để kết nối đến broket MQTT với hostname mqtt://iot.eclipse.org
var client = mqtt.connect('mqtt://iot.eclipse.org')
// function có chức năng subscribe 1 topic nếu đã kết nối thành công đến broker
client.on('connect', function() {
    console.log('Client B connected')
    // client subcribe topic /client-b/sub
    client.subscribe('/client-b/sub') 
    // publish gói tin 'Hello from client B' đến topic /client-a/sub 
    client.publish('/client-a/sub', 'Hello from client B')
})

client.on('message', function(topic, message) {
	// in ra màn hình console 1 message ở định dạng string
    console.log(message.toString())
    // đóng kết nối của client 
    client.end()
})
console.log('Client B started')
