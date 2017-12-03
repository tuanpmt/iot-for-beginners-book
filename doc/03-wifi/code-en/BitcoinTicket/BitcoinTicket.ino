#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h> //https://github.com/bblanchon/ArduinoJson
#include "SSD1306.h" //https://github.com/squix78/esp8266-oled-ssd1306

const char* ssid = ".....";
const char* password = "....";
SSD1306  display(0x3c, 4, 5);
/* xem thêm https://www.cryptocompare.com/api/ */
const char* host = "https://min-api.cryptocompare.com/data/price?fsym=BTC&tsyms=USD";
/*SHA1 fingerprint*/
const char* fingerprint = "61 DE E9 FF BB 6B AD AA E4 9A 38 95 DC EC 74 2C 61 4B 7D 07";

void getBitcoin()
{
  HTTPClient http;
  Serial.print("connecting to ");
  Serial.println(host);

  http.begin(host, fingerprint);
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    String payload = http.getString();
    Serial.println(payload);
    StaticJsonBuffer<512> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(payload);
    if (!root.success()) {
      Serial.println("parseObject() failed");
      return;
    }

    double priceUSD = root["USD"];
    display.clear();
    display.drawString(0, 0, "Bitcoin price");
    display.drawString(0, 18, String(priceUSD));
    display.display();
    Serial.println(priceUSD);
  }
  http.end();
}

void setup() {
  Serial.begin(115200);
  display.init();
  display.clear();
  display.setFont(ArialMT_Plain_16);
  display.drawString(0, 0, "Connecting to");
  display.drawString(0, 18, ssid);
  display.display();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  display.clear();
  display.drawString(0, 0, "Connected");
  display.display();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    getBitcoin();
  }
  delay(5000);
}
