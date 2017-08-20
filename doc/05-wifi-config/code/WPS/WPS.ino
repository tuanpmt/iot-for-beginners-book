#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("", "");
  delay(4000);
  // Check if WiFi is already connected and if not, begin the WPS process.
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("\nAttempting connection ...");
    WiFi.beginWPSConfig();
    delay(6000);
  }
  Serial.println("\nConnection already established.");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.macAddress());
}

void loop()
{
  // put your main code here, to run repeatedly:
}
