#include <ESP8266WiFi.h>

const char* ssid     = "your-ssid";
const char* password = "your-password";

void setup() {

  // Initiate a serial connection at 115200 bits/s
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");

  // Print out the name fo the WiFi (SSID)
  Serial.println(ssid);

 // Configure the ESP8266 in station mode and connect to a pre-defined WiFi network
  WiFi.begin(ssid, password);
  // Print out . when ESP8266 trying to connect to the network
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print out "WiFi connected" and IP of ESP8266
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

}
