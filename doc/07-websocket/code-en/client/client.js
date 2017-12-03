//Basic steps to create a websocket:

var ws = new WebSocket('ws://domain.com:8000/'); // create a websocket
ws.onopen = function() //
{
   // callback when websocket is successfully opened
};

ws.onmessage = function(evt)
{
    // callback when client received data from server
};
ws.onclose = function() {
    // callback when websocket is closed
};
