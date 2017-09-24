var mosca = require('mosca');
var mqtt = require('mqtt');
//Configure the pub/sub settings use mosquitto 
var pubsubsettings = {
	type: 'mqtt',
	json: false,
	mqtt: require('mqtt'),
	host: '192.168.1.7',
	port: 1883
};
// pass the pub/sub settings object to our server through the 'backend' key.
var moscaSettings = {
	port: 1883,		//mosca (mqtt) port
	backend: pubsubsettings, //pubsubsettings is the object we created above 
    persistence: {
        factory: mosca.persistence.Mongo,
        url: 'mongodb://localhost:27017/mqtt'
    }
};
var server = new mosca.Server(moscaSettings); //here we start mosca
console.log('server is running...');

var message = {
	topic: 'hello/esp8266',
	payload:'off',
	qos: 0,
	retain: false
};

server.publish(message, function() {
	console.log(message);
	console.log('done');
});

server.on('published', function(packet, client) {
  console.log('Published', packet.payload);
});

server.on('clientConnected', function(client){
	console.log('clientConnected', client.id);
});
server.on('clientDisconnected', function(client){
	console.log('clientDisconnected', client.id);
});

server.on('ready', setup);

function setup(){
	console.log('mosca server is up and running')
}
console.log('test running...');

