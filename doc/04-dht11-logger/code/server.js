var http = require('http');
var url = require('url');
var querystring = require('querystring');

//Query: http://localhost:8000/update?temp=30.5&hum=80
function requestHandler(request, response) {
  var uriData = url.parse(request.url);
  var pathname = uriData.pathname;          // /update
  var query = uriData.query;                // temp=30.5&hum=80
  var queryData = querystring.parse(query); // queryData.temp = 30.5
                                            // queryData.hum = 80
  if(pathname == '/update') {
    console.log(queryData);
  }
  response.end('ok')
}
var server = http.createServer(requestHandler);
server.listen(8000);
console.log('Server listening on port 8000');
