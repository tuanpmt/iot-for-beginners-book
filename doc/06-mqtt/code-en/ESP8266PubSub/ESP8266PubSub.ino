#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "........";
const char* password = ".........";
const char* mqtt_server = "broker.mqtt-dashboard.com";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(16, OUTPUT);
  Serial.begin(115200);
  // Setup wifi connection and print the ESP8266's IP to terminal.
  setup_wifi();
  // Setup MQTT server "broker.mqtt-dashboard.com" and listen to client on port 1883.
  client.setServer(mqtt_server, 1883);
  // Call "callback" function to publish/subscribe
  client.setCallback(callback);
  // Call "reconnect()" function to restart the connection to server when it losts connection.
  reconnect();
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  // Connect to a given WiFi
  WiFi.begin(ssid, password);
  // Print . during WiFi connecting process
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print "WiFi connected" and ESP8266's IP to terminal
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Print the topic's header and content published from MQTT lens
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  // Verify the data from topic "ESP8266/LED_GPIO16/status".
  // If the string is "ON", turn on the LED. And vice versa
  if ((char)payload[0] == 'o' && (char)payload[1] == 'n') //on
    digitalWrite(16, LOW);
  else if ((char)payload[0] == 'o' && (char)payload[1] == 'f' && (char)payload[2] == 'f') //off
    digitalWrite(16, HIGH);
  Serial.println();
}

void reconnect() {
  // Keep attempting to connect to MQTT broker until the connection is recovered.
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266")) {
      Serial.println("connected");
      // publish "Connected!" message to topic ESP8266/connection/board
      client.publish("ESP8266/connection/board", "Connected!");
      // Subscribe to topic ESP8266/LED_GPIO16/status
      client.subscribe("ESP8266/LED_GPIO16/status");

    } else {
      // Print the client's state if it can't connect to MQTT broker.
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // delay 5 seconds
      delay(5000);
    }
  }
}

void loop() {
  // Check the ESP8266 connection. Reconnect to broker if connection isn't ready yet
  if (!client.connected()) {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}
