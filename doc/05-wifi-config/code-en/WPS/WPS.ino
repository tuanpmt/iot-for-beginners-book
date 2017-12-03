#include <ESP8266WiFi.h>

void setup()
{
  // Set up the initial condition
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  // Connect to a known WiFi AP, whose SSID and password is stored on ESP8266's FLASH memory.
  WiFi.begin("", "");
  delay(4000);


  // Check the WiFi connection. If not connected yet, use WPS to connect.
  // Your router should be in WPS mode during these commands.
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("\nAttempting connection ...");
    WiFi.beginWPSConfig();
    delay(6000);
  }
  // After successful connection, print out the local IP, SSID and MAC address of your device.
  Serial.println("\nConnection already established.");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.macAddress());
}

void loop()
{
  // Main program
}
