#include <ESP8266WiFi.h>

const char *password = "password";

void setup() {
	Serial.begin(115200);
	Serial.print("Configuring access point...");
  char ssid[64];
  sprintf(ssid, "AP-%06X", ESP.getChipId());
	WiFi.softAP(ssid, password);

	IPAddress myIP = WiFi.softAPIP();
	Serial.print("AP IP address: ");
	Serial.println(myIP);
}

void loop() {
}
