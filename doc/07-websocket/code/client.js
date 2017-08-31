 function WebSocketTest()
         {
               var ws = new WebSocket("ws://localhost:8000/echo"); // mở 1 websocket
				
               ws.onopen = function() // 
               {
                  
                  ws.send("Message to send"); // truyền dữ liệu khi websocket đã được mở
                
               };
				
               ws.onmessage = function (evt) // sự kiện xảy ra khi client nhận dữ liệu từ server
               { 
                  var received_msg = evt.data;
                  
               };
				
               ws.onclose = function()
               { 

               }; // đóng websocket
            }
         }