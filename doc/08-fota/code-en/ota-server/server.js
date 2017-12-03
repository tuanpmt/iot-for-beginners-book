var fs = require('fs');
var url = require('url');
var http = require('http');
var querystring = require('querystring');
var crypto = require('crypto');
// function send request(response) from server side or receive the request from client
function requestHandler(request, response) {

    // Assume that firmware address http://192.168.1.7:8000/firmware.bin
    var uriData = url.parse(request.url);
    var pathname = uriData.pathname;          // /firmware.bin

    if (pathname == '/firmware.bin') {
        var ver = request.headers['x-esp8266-version'];
        console.log('Client request update, version ', ver);
        if(ver == '1.0') {
            console.log('Send firmware 2.0 to client');
            fs.readFile('./esp8266-firmware-2.0.bin', function(error, content) {
                response.writeHead(200, {
                    'Content-Type': 'binary/octet-stream',
                    'Content-Length': Buffer.byteLength(content),
                    'x-MD5': crypto.createHash('md5').update(content).digest("hex")
                });
                response.end(content);
            });
        } else {
            response.statusCode = 304;
            response.end();
        }
    }
}
var server = http.createServer(requestHandler);
server.listen(8000);
console.log('Server listening on port 8000');
