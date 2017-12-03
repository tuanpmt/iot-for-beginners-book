#include <DHT.h>            // Include the DHT library to read DHT11 sensor data.
#include <ESP8266WiFi.h>    // Include this library to configure ESP8266 as a client.
#define DHTPIN 4            // Define the GPIO 4 to receive data from DHT11.
#define DHTTYPE DHT11       // Define the type of DHT sensor. In this case, DHT11.

DHT dht(DHTPIN, DHTTYPE);
WiFiClient client;                        // Declare the "client" variable of "WiFiClient" type.
const char* ssid = "YOUR-WIFI-SSID";      // Declare the SSID or your WiFI Access Point's name.
const char* password = "YOUR-WIFI-PASS";  // Declare the WiFi password of the above WiFi AP.
const char* server = "Your-local-IP";     // Declare your web server IP or your PC's IP.
const int port = 8000;                    // Declare the port on server to be opened for listening.
const int sendingInterval = 2 * 1000;     // Declare the interval time in microseconds between two successive measurements.

void setup() {
  Serial.begin(115200);
  dht.begin();                            // Initiate the DHT11 sensor.
  Serial.println("Connecting");


  // Configure ESP8266 as a Station and connect to a WiFi AP. Continuously print . on the terminal if it hasn't successfully connected to our WiFi AP.
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("\r\nWiFi connected");
}

void loop() {

// Read the temperature (in Celsius Scale) and humidity. If the sensor fails to read, print out an error message and skip the current loop.
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  if (isnan(temp) || isnan(humi)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  if (client.connect(server, port)) {           // Initiate a connection to a server with a given IP and PORT.
  //---------------------------------------------------------------------------------------
    String req_uri = "/update?temp=" + String(temp, 1) + "&humd=" + String(humi, 1);
    client.print("GET " + req_uri + " HTTP/1.1\n" + "Host: "+ server +"\n" + "Connection: close\n" + "Content-Length: 0\n" +"\n\n");   // <1>
  //---------------------------------------------------------------------------------------

  // Convert the temp and humi from float to string and print it on Arduino serial terminal
    Serial.printf("Nhiet do %s - Do am %s\r\n", String(temp, 1).c_str(), String(humi, 1).c_str());
  }
  client.stop();                          // Disconnect from server.

  delay(sendingInterval);
}
