// tạo biến mqtt sử dụng các chức năng của module mqtt
var mqtt = require('mqtt') 	 
// tạo biến client sử dụng thuộc tính connect để kết nối đến broket MQTT với hostname mqtt://iot.eclipse.org
var client = mqtt.connect('mqtt://iot.eclipse.org') 
// function có chức năng subscribe 1 topic nếu đã kết nối thành công đến broker 
client.on('connect', function() { 
    console.log('Client A connected') 
    // client subcribe topic /client-a/sub
    client.subscribe('/client-a/sub') 
})
// function có chức năng gửi 1 gói tin đễn đến topic đã đăng kí  
client.on('message', function(topic, message) { 
	// in ra màn hình console 1 message ở định dạng string
    console.log(message.toString()) 
    // publish gói tin 'Hello from client A' đến topic /client-b/sub 		
    client.publish('/client-b/sub', 'Hello from client A') 
    // đóng kết nối của client 
    client.end()  
})
console.log('Client A started')
