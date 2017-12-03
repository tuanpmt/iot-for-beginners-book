
var mosca = require('mosca');   // Khai báo biến mosca sử dụng các thuộc tính của module mosca
// Sử dụng thư viện ascoltatore nhằm hỗ trợ publish message, subscribe topic đến  từ các Broker/Protocol
var ascoltatore = {

  type: 'mongo',
  url: 'mongodb://localhost:27017/mqtt', // url: địa chỉ url của mongodb, server sẽ lắng nghe các client ở địa
                                         // chỉ localhost:27017
  pubsubCollection: 'ascoltatori',       // pubsubCollection: Nơi để lưu trữ các message của mongodb
  mongo: {}                              // mongo: Cài đặt dành cho kết nối của mongo. Không sử dụng
};
var settings = {
  port: 1883,          // port kết nối đến server
  backend: ascoltatore // ascoltatore sẽ được gọi và thực thi khi tạo server được tạo để thiết lập các kết nối
};

// Lệnh tạo server sử dụng mosca
var server = new mosca.Server(settings);

// Thực hiện hàm setup, in ra màn hình console nếu có sự kiện ready của server
server.on('ready', setup);
function setup() {
  console.log('Mosca server is up and running');
}

// In ra dòng chữ client connected và id của client khi có sự kiện client kết nối thành công đến server
server.on('clientConnected', function(client) {
    console.log('client connected', client.id);
});

// In ra dòng chữ client disconnected và id của client khi có sự kiện client ngắt kết nối với server
server.on('clientDisconnected', function(client) {
    console.log('client disconnected', client.id);
});

// In ra message của client gửi ở dạng string khi có sự kiện client publish 1 message
server.on('published', function(packet, client) {
  console.log('Published', packet.payload.toString());
});
