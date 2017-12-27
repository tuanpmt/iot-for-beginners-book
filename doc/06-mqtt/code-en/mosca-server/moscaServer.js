// declare a "mosca" variable to use mosca module's features.
var mosca = require('mosca');
// Using ascoltatore library to publish a message, subscribe to a topic on Broker/Protocol.
var ascoltatore = {
    type: 'mongo',
    url: 'mongodb://localhost:27017/mqtt', // url of MongoDB, server will listen for
    // client's request at localhost:27017
    pubsubCollection: 'ascoltatori', // pubsubCollection: Store MongoDB's message
    mongo: {} // mongo: MongoDB connection setting. Don't use this parameter in this project.
};
var settings = {
    port: 1883, // Server's port
    backend: ascoltatore // "ascoltatore" will be called and executed to initiate connections when a server is created.
};
// Declare "server" variable using mosca.
var server = new mosca.Server(settings);
// This function setups and prints message to console when the Mosca server is ready.
server.on('ready', setup);

function setup() {
    console.log('Mosca server is up and running');
}
// This function prints "Client connected" and client's id to console when a client successfully connects to a server.
server.on('clientConnected', function(client) {
    console.log('client connected', client.id);
});
// This function prints "Client disconnected" and client's id to console when a client disconnects from server.
server.on('clientDisconnected', function(client) {
    console.log('client disconnected', client.id);
});
// This function prints the content of client's message to console in "string" when a client published a message.
server.on('published', function(packet, client) {
    console.log('Published', packet.payload.toString());
});