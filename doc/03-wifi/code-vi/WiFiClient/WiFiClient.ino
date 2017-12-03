#include <ESP8266WiFi.h>

const char* ssid     = "your-ssid";
const char* password = "your-password";

void setup() {

  // Thiết lập truyền dữ liệu nối tiếp ở tốc độ 115200 bits/s
  Serial.begin(115200);
  delay(10);
  Serial.print("Connecting to ");

  // In ra tên mạng wifi sẽ kết nối đến
  Serial.println(ssid);

  // Thiết lập ESP8266 ở chế độ station và kết nối đến mạng wifi đã chỉ định
  WiFi.begin(ssid, password);
  // Đoạn code in ra dấu . nếu ESP8266 chưa được kết nối
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // In ra dòng "WiFi connected" và địa chỉ IP của ESP8266
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

}
