#include <ESP8266WiFi.h>

#define PORT  23
// Limit the maximum clients
#define MAX_CLIENTS 3

// Name and passwork of the ESP8266 AP
const char *ssid = "yourSSID";
const char *password = "yourPassword";

// Creating IP address
IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

// Creating port for client connection.
WiFiServer server(PORT);
WiFiClient clients[MAX_CLIENTS];

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Setting soft-AP configuration ... ");

  // Configure acces point and soft AP to allow client connection.
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);

  // Print out local_IP of the AP.
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("Telnet server started");
  server.begin();
}

void loop() {
  uint8_t i;
  // Check the status of the new client connection
  if (server.hasClient())  {
    for (i = 0; i < MAX_CLIENTS; i++) {
      if (!clients[i] || !clients[i].connected())
      { if (clients[i]) clients[i].stop();
        clients[i] = server.available();
        Serial.print("New client: "); Serial1.print(i);
        continue;
      }
    }
    WiFiClient serverClient = server.available();
    serverClient.stop();
  }
   // Compare the number of existing clients with MAX_CLIENTS
  // including connected clients and available clients
  // read data from the clients, and then respond.
  for (i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i] && clients[i].connected()) {
      if (clients[i].available()) {
        String line = clients[i].readStringUntil('\r');
        Serial.print("Server receive from Client:");
        Serial.println(line);

        // Send the resonse back to the client
        String resp = String(line.reserve(line.length() - 1));
        Serial.print(" Then, response back to client:");
        Serial.println(resp);
        clients[i].write(resp.c_str());
        Serial.println();
      }
    }
  }
}
