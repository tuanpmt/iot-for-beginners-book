#include <ESP8266WiFi.h>

void setup()
{
  // Cài đặt các thông số ban đầu
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  // Kết nối với AP cũ đã vào trước đó, SSID và password được lưu trong bộ nhớ flash của thiết bị
  WiFi.begin("", "");
  delay(4000);

  // Kiểm tra xem wifi đã được kết nối chưa, nếu chưa, bắt đầu kết nối bằng WPS
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("\nAttempting connection ...");
    WiFi.beginWPSConfig();
    delay(6000);
  }
  // Khi kết nối thành công, in thông báo ra màn hình cùng với các thông số của Wifi vừa kết nối.
  Serial.println("\nConnection already established.");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.SSID());
  Serial.println(WiFi.macAddress());
}

void loop()
{
  // chương trình chính
}
