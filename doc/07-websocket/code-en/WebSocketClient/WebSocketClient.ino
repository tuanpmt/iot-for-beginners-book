#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <WebSocketsClient.h> //https://github.com/Links2004/arduinoWebSockets
WebSocketsClient webSocket;

const char* ssid = "...";
const char* password = "...";
const int LED = 16;
const int BTN = 0;

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[WSc] Disconnected!\n");
      break;
    case WStype_CONNECTED:
      {
        Serial.printf("[WSc] Connected to url: %s\n",  payload);
      }
      break;
    case WStype_TEXT:
      Serial.printf("[WSc] get text: %s\n", payload);
      if(strcmp((char*)payload, "LED_ON") == 0) {
        digitalWrite(LED, 0); // When client trigger event"LED_ON" server turn on the LED
      } else if(strcmp((char*)payload, "LED_OFF") == 0) {
        digitalWrite(LED, 1); // When client trigger event "LED_OFF" server turn off the LED
      }
      break;
    case WStype_BIN:
      Serial.printf("[WSc] get binary length: %u\n", length);
      break;
  }
}

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  Serial.begin(115200);
  Serial.println("ESP8266 Websocket Client");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  webSocket.begin("192.168.0.106", 8000);
  webSocket.onEvent(webSocketEvent);

}

void loop() {
  webSocket.loop();
  static bool isPressed = false;
  if (!isPressed && digitalRead(BTN) == 0) { // GPIO0 button pressed
    isPressed = true;
    webSocket.sendTXT("BTN_PRESSED");
  } else if (isPressed && digitalRead(BTN)) { // GPIO0 button released
    isPressed = false;
    webSocket.sendTXT("BTN_RELEASE");
  }
}
