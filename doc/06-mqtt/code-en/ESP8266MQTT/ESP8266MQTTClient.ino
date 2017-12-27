#include <ESP8266MQTTClient.h>
#include <ESP8266WiFi.h>

#define ledPin 16   //Led on board ESP8266 WiFi Uno

MQTTClient mqtt;

const char* ssid = "Your SSID";
const char* password = "Your password";

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // Turn off LED at the beginning
  digitalWrite(ledPin, HIGH);

  // Configure ESP8266 as a Station and connect to wifi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("\nConnecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Connect to the MQTT server, print the "esp8266/GPIO16" topic's id
  // and subscribe to "hello/esp8266" topic with QoS 0
  mqtt.onConnect([]() {
    Serial.printf("MQTT: Connected\r\n");
    Serial.printf("Subscribe id: %d\r\n", mqtt.subscribe("esp8266/GPIO16", 0));
    mqtt.subscribe("esp8266/GPIO16", 0);
  });

   // Publish a message to subscriber's
  mqtt.onSubscribe([](int sub_id) {
   // Print the subscribed topic's id: "hello/esp8266" and "MQTTlens/test/#"
    Serial.printf("Subscribe topic id: %d ok\r\n", sub_id);

    // Publish "hello app" message to "Broker/app" topic with QoS0 and retain flag 0
    mqtt.publish("Broker/app", "hello app", 0, 0);
  });

  // Handle the received data from subscribed's topic
  mqtt.onData([](String topic, String data, bool cont) {
    Serial.printf("Data received, topic: %s, data: %s\r\n", topic.c_str(), data.c_str());

    // If the received string is 'ON', the LED on ESP8266 WiFI Uno will turn on. And vice versa.
    if (topic == "esp8266/GPIO16" && data[0] == 'o' && data[1] == 'n' && data[2] == '\0') {
      digitalWrite(ledPin, LOW);
      Serial.println("Turn on the led on board");
    } else if (topic == "esp8266/GPIO16" && data[0] == 'o' && data[1] == 'f' && data[2] == 'f' && data[3] == '\0' ) {
      digitalWrite(ledPin, HIGH);
      Serial.println("Turn off the led on board");
    }
  });
  // Begin the MQTT broker "iot.eclipse.org" using WebSocket and listen to client's request at port 80.
  mqtt.begin("ws://iot.eclipse.org:80/ws");
}

void loop() {
  // Initiate MQTT, verify and handle data from the topics,
  // verify the protocol's attributes: keep-a-live packet, QoS packet, topic's id,...
  mqtt.handle();
}
