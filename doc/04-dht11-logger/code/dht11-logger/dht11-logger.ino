#include <DHT.h>
#include <ESP8266WiFi.h>
#define DHTPIN 4     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;
const char* ssid = "YOUR-WIFI-SSID"; // your wireless network name (SSID)
const char* password = "YOUR-WIFI-PASS"; // your Wi-Fi network password
const char* server = "192.168.1.100";
const int port = 8000;
const int postingInterval = 2 * 1000; // post data every 2 seconds

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Connecting");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("\r\nWiFi connected");
}

void loop() {

  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  if (isnan(temp) || isnan(humi)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  if (client.connect(server, port)) {
    String req_uri = "/update?field1=" + String(temp, 1) + "&field2=" + String(humi, 1);
    client.print("GET " + req_uri + "HTTP/1.1\n");
    client.print("Host: "+server+"\n");
    client.print("Connection: close\n");
    client.print("Content-Length: 0\n");
    client.print("\n\n");
    Serial.printf("Nhiet do %s - Do am %s\r\n", String(temp, 1).c_str(), String(humi, 1).c_str());
  }
  client.stop();

  delay(postingInterval);
}
