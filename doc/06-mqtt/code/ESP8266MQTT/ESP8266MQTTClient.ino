#include <ESP8266MQTTClient.h>
#include <ESP8266WiFi.h>

#define ledPin 16

MQTTClient mqtt;

const char* ssid = "your SSID";
const char* password = "your password";

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);

  // OFF led GPIO16 khi bắt đầu chương trình
  digitalWrite(ledPin, HIGH);

  // Thiết lập ESP8266 ở chế độ STA và kết nối Wifi
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

  // Kết nối đến server MQTT, in ra id của topic "hello/esp8266" đồng thời đăng kí nhận message với gói QoS 0,
  // và subcribe các topic "hello/esp8266", "MQTTlens/test/#"
  mqtt.onConnect([]() {
    Serial.printf("MQTT: Connected\r\n");
    Serial.printf("Subscribe id: %d\r\n", mqtt.subscribe("hello/esp8266", 0));
    mqtt.subscribe("MQTTlens/test/#", 0);
  });

  // Thực hiện chức năng subscribe topic và publish các message
  mqtt.onSubscribe([](int sub_id) {
    //in ra id của các topic đã subscribe là "hello/esp8266" và "MQTTlens/test/#"
    Serial.printf("Subscribe topic id: %d ok\r\n", sub_id);

    //publish các message đến các topic với gói QoS 0 và cờ retain 0
    mqtt.publish("hello/esp8266", "hello server", 0, 0);
    mqtt.publish("MQTTlens/test/3", "hello server", 0, 0);
  });

  // Xử lí dữ liệu nhận được của các topic đã subscribe
  mqtt.onData([](String topic, String data, bool cont) {
    Serial.printf("Data received, topic: %s, data: %s\r\n", topic.c_str(), data.c_str());

    // Nếu chuỗi nhận được là 'on' sẽ ON led trên board ESP8266 WiFi Uno, chuỗi 'off' sẽ OFF led
    if (topic == "hello/esp8266" && data[0] == 'o' && data[1] == 'n' && data[2] == '\0') {
      digitalWrite(ledPin, LOW);
      Serial.println("Turn on the led on board");
    } else if (topic == "hello/esp8266" && data[0] == 'o' && data[1] == 'f' && data[2] == 'f' && data[3] == '\0' ) {
      digitalWrite(ledPin, HIGH);
      Serial.println("Turn off the led on board");
    }
  });
  // khởi tạo broker MQTT là iot.eclipse.org, port 1883
  mqtt.begin("mqtt://iot.eclipse.org:1883");
}

void loop() {
  // Hàm khởi tạo MQTT, kiểm tra và xử lí các dữ liệu từ các topic, kiểm tra các thuộc tính của giao
  // thức như gói keep-a-live, gói tin QoS, id của topic...,
  mqtt.handle();
}
