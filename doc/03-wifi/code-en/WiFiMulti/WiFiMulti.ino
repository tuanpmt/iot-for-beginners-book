#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
// Declare wifiMulti variable of class ESP8266WiFiMulti to use functions of this class.
ESP8266WiFiMulti wifiMulti;
// connectioWasAlive variable to check for ESP8266 wifi connection.
boolean connectioWasAlive = true;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  // Add the pre-defined networks for ESP8266
  wifiMulti.addAP("primary-network-name", "pass-to-primary-network");
  wifiMulti.addAP("secondary-network-name", "pass-to-secondary-network");
  wifiMulti.addAP("tertiary-network-name", "pass-to-tertiary-network");
}

void monitorWiFi()
{
  // Check if there is no WiFi connection then set connectioWasAlive = false
  // while print out "." every 500ms when there is no connection.
  if (wifiMulti.run() != WL_CONNECTED)
  {
    if (connectioWasAlive == true)
    {
      connectioWasAlive = false;
      Serial.print("Looking for WiFi ");
    }
    Serial.print(".");
    delay(500);
  }
   // If a connection is established then set connectioWasAlive = true
  // so when the connection is terminated the program will jump into if (connectioWasAlive == true),
  // annoucing the WiFi scanning process
  else if (connectioWasAlive == false)
  {
    connectioWasAlive = true;
    Serial.printf(" connected to %s\n", WiFi.SSID().c_str());
  }
}

void loop()
{
  monitorWiFi();
}
