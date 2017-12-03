#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//Include neccessary libraries.
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "WiFiManager.h"          //https://github.com/tzapu/WiFiManager

void configModeCallback (WiFiManager *myWiFiManager)
{
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

  // Initialize the serial communication and connect to wifi using WiFiManager.
void setup()
{
  Serial.begin(115200);

  // Declare the "wifiManager" variable. It is a 'WiFiManager' class and is defined in "WiFiManager.h".
  WiFiManager wifiManager;

  // Uncomment this command to reset settings to default.
  // wifiManager.resetSettings();

  // Set up a callback. When your device fails to connect to a known AP, it calls this callback
  // and starts its own AP station with a default SSID "ESP+chipID".
  wifiManager.setAPCallback(configModeCallback);
  if (!wifiManager.autoConnect())
  {
    Serial.println("failed to connect and hit timeout");
  // If failed to connect, reset your device and re-connect.
    ESP.reset();
    delay(1000);
  }
  // Print this message to terminal screen when your device has successfully connected to WiFi.
  Serial.println("connected...yeey :)");

}

void loop()
{
  // Main program.
}
