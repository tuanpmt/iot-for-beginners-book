#include <ESP8266WiFi.h>

#include <ESPAsyncTCP.h>

#include <ESPAsyncWebServer.h>



const char* ssid = "*****";

const char* password = "*******";

const char *html = "<html>"

   "<head>"
      "<title>TEst</title>"
   "</head>"
   
"<INPUT type='radio' name='LED' value='1'checked >OFF"
 "<INPUT type='radio' name='LED' value='0'>ON</li></ul>"


   "<body>"
   
      "<div id=\"sse\">"
         "<a href=\"#\"onclick=\"WebSocketTest()\">Run WebSocket</a>"
      "</div>"
      "<script type=\"text/javascript\">"
      
         "console.log(\"start\")"

         "function WebSocketTest()"
         
         "{"
            "if (\"WebSocket\" in window)"
            "{"
         
               "var host = window.location.hostname;"
               "console.log(host)"
               "var ws = new WebSocket(\"ws://\"+host+\":8000\");"
               
               "ws.onopen = function()"
               
               "{"
                  "ws.send(\"Message to send\");"
               "};"
      
               "ws.onmessage = function (evt)"
               "{"
                  "var received_msg = evt.data;"
               "};"
      
               "ws.onclose = function()"
               "{"
               "};"
            "}"
            "else"
            "{"
               
            "}"
         "}"
      "</script>"
   "</body>"
   
"</html>";




void setup()
{ 
  void onEvent(AsyncWebSocket * server, AsyncWebSocketClient * client);


 AsyncWebServer server(8000);


 pinMode(16, INPUT);
  Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println(" connected");

  server.begin();
  
  Serial.printf("Web server started, open %s in a web browser\n",  WiFi.localIP().toString().c_str());
  
}


void loop()
{ 
  AsyncWebSocketClient * client;

client->text((char*)html);
               
}
