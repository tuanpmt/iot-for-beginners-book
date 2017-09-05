#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>

const char* ssid = "...";
const char* password = "...";
const char *currentVersion = "1.0"; //<1>
const char *serverUrl = "http://192.168.0.106:8000/firmware.bin"; //<2>
void setup() {

  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("ESP8266 http update, current version: ");
  Serial.println(currentVersion);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  t_httpUpdate_return ret = ESPhttpUpdate.update(serverUrl, currentVersion);
  switch (ret) {
    case HTTP_UPDATE_FAILED:
      Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
      break;

    case HTTP_UPDATE_NO_UPDATES:
      Serial.println("HTTP_UPDATE_NO_UPDATES");
      break;
    case HTTP_UPDATE_OK:
      Serial.println("HTTP_UPDATE_OK");
      break;
  }

}

void loop() {
}

