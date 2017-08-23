var fs = require('fs');
var url = require('url');
var http = require('http');
var querystring = require('querystring');
var db = []; //database

function requestHandler(request, response) {
  var uriData = url.parse(request.url);
  var pathname = uriData.pathname;          // /update
  var query = uriData.query;                // temp=30.5&hum=80
  var queryData = querystring.parse(query); // queryData.temp = 30.5
  if(pathname == '/update') {
    var newData = {
        temp: queryData.temp,
        humd: queryData.humd,
        time: new Date()        //current time
    };
    db.push(newData);
    console.log(newData);
    response.end();             // return status 200 OK
  } else if(pathname == '/get'){
    response.writeHead(200, { 'Content-Type': 'application/json' });
    response.end(JSON.stringify(db));
    db = [];
  } else{
    fs.readFile('./index.html', function(error, content) {
        response.writeHead(200, {'Content-Type': 'text/html' });
        response.end(content);
    });
  }
}

var server = http.createServer(requestHandler);
server.listen(8000);
console.log('Server listening on port 8000');
