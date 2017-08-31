#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
const char* ssid = "*****";
const char* password = "*******";
const int LED = 16;
const int BTN = 0;
const char index_html[] PROGMEM = ""
"<!DOCTYPE HTML>"
"<html>"
"<head>"
"    <title>ESP8266 WebSocket</title>"
"</head>"
"<body>"
"    <div> Webscoket status <span id=\"status\" style=\"font-weight: bold;\"> disconnected </span> </div>"
"    <div> ESP8266 Button Status <input type=\"checkbox\" id=\"btn\" name=\"btn\" /> </div>"
"    <div> Control LED <input type=\"checkbox\" id=\"led\" name=\"led\" disabled=\"true\" /> </div>"
"    <script type=\"text/javascript\">"
"        var button = document.getElementById('btn');"
"        var led = document.getElementById('led');"
"        var status = document.getElementById('status');"
"        var url = window.location.host;"
"        var ws = new WebSocket('ws://' + url + ':8000/ws');"
"        ws.onopen = function()"
"        {"
"            status.text = 'Connected';"
"            led.disabled = false;"
"        };"
"        ws.onmessage = function(evt)"
"        {"
"            if(evt.data == 'BTN_PRESSED') {"
"                button.checked = true;"
"            } else if(evt.data == 'BTN_RELEASE') {"
"                button.checked = false;"
"            }"
"        };"
"        ws.onclose = function() {"
"            led.disabled = true;"
"            status.text = 'Disconnected';"
"        };"
"        led.onchange = function() {"
"            var status = 'LED_OFF';"
"            if (led.checked) {"
"                status = 'LED_ON';"
"            }"
"            ws.send(status)"
"        }"
"    </script>"
"</body>"
"</html>";

AsyncWebServer server(8000);
AsyncWebSocket ws("/ws");

void onWsEvent(AsyncWebSocket * server, AsyncWebSocketClient * client, AwsEventType type, void * arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_DATA && len > 0) {
    data[len] = 0;
    String data_str = String((char*)data);
    if (data_str == "LED_ON") {
      digitalWrite(LED, 0);
    } else if (data_str == "LED_OFF") {
      digitalWrite(LED, 1);
    }
  }

}
void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  if (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.printf("STA: Failed!\n");
    WiFi.disconnect(false);
    delay(1000);
    WiFi.begin(ssid, password);
  }
  ws.onEvent(onWsEvent);
  server.addHandler(&ws);
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send_P(200, "text/html", index_html);
  });
}


void loop()
{
  static bool isPressed = false;
  if (!isPressed && digitalRead(BTN) == 0) { //PRESSED
    isPressed = true;
    ws.textAll("BTN_PRESSED");
  } else if (isPressed && digitalRead(BTN)) { //RELEASE
    isPressed = false;
    ws.textAll("BTN_RELEASE");
  }
}
