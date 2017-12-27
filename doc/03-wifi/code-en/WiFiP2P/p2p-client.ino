#include "ESP8266WiFi.h"
// Name and password of the ESP8266 AP acting as a server
const char *ssid = "yourSSID";
const char *password = "yourPassword";

IPAddress server_ip(192, 168, 4, 1);
#define PORT  23
// Port 23 is the ESP8266 AP port.
WiFiClient client;

void setup() {
  uint8_t i = 0;
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  Serial.print("\nConnecting to ");
  Serial.println(ssid);

  // Check the connection status, if none is established,
  // print out "connecting..." on the Serial Terminal.
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting...");
    delay(500);
  }
}

unsigned long previousMillis = 0;
void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    // Check client(STA) connection status.
    // Continously check connection using IP and port of the AP, 
    // if fail then print out "connection failed" on the Serial Terminal.
    while (!client.connected()) {
      if (!client.connect(server_ip, PORT)) {
        Serial.println("connection failed");
        delay(1000);
        return;
      }
    }
    // If client(STA) has connected to the server(AP) then read all data
    // until reaching \r and print out all received data.
    while (client.available()) {

      String line = client.readStringUntil('\r');
      Serial.print("Client receive from Server:");
      Serial.println(line);
    }
    //Send PING to server every 1000ms.
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 1000) {
      previousMillis = currentMillis;
      client.write("PING\r");
    }
  }
}
