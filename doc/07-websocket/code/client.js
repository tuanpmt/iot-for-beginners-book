//Trình tự mở một websocket cơ bản:

var ws = new WebSocket('ws://domain.com:8000/'); // mở 1 websocket
ws.onopen = function() //
{
   // sự kiện khi websocket được mở thành công
};

ws.onmessage = function(evt)
{
    // sự kiện xảy ra khi client nhận dữ liệu từ server
};
ws.onclose = function() {
    // sự kiện khi websocket bị đóng
};
