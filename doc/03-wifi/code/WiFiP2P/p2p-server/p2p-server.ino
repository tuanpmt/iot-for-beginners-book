#include <ESP8266WiFi.h>

#define PORT  23
// Gioi han so luong clients ket noi
#define MAX_CLIENTS 3

// Ten va mat khau cua ESP8266 AP se tao
const char *ssid = "yourSSID";
const char *password = "yourPassword";

//khoi tao IP adress
IPAddress local_IP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

// Khoi tao port de clients ket noi.
WiFiServer server(PORT);
WiFiClient clients[MAX_CLIENTS];

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Setting soft-AP configuration ... ");

  //Cau hinh acces point, cai dat soft AP de client ket noi vao.
  WiFi.softAPConfig(local_IP, gateway, subnet);
  WiFi.softAP(ssid, password);

  //In ra local_IP cua AP.
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  Serial.println("Telnet server started");
  server.begin();
}

void loop() {
  uint8_t i;
  // kiem tra co client moi ket noi khong
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
  // Kiem tra neu so client ket noi MAX_CLIENTS
  // co client, client duoc ket noi va o trang thai available
  // doc du lieu tu client, va gui lai du lieu cho client do.
  for (i = 0; i < MAX_CLIENTS; i++) {
    if (clients[i] && clients[i].connected()) {
      if (clients[i].available()) {
        String line = clients[i].readStringUntil('\r');
        Serial.print("Server receive from Client:");
        Serial.println(line);

        //Gui thong tin hoai dap cho client
        String resp = String(line.reserve(line.length() - 1));
        Serial.print(" Then, response back to client:");
        Serial.println(resp);
        clients[i].write(resp.c_str(), "aaaaaw");
        Serial.println();
      }
    }
  }
}
