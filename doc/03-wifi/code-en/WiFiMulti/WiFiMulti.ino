#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
// Khai báo biến wifiMulti thuộc class ESP8266WiFiMulti để sử dụng các chức năng của class này.
ESP8266WiFiMulti wifiMulti;
// Biến connectioWasAlive nhằm kiểm tra kết nối của ESP8266 đến mạng wifi.
boolean connectioWasAlive = true;

void setup()
{
  Serial.begin(115200);
  Serial.println();
  // Add vào các mạng wifi mà ESP8266 được chỉ định sẽ kết nối
  wifiMulti.addAP("primary-network-name", "pass-to-primary-network");
  wifiMulti.addAP("secondary-network-name", "pass-to-secondary-network");
  wifiMulti.addAP("tertiary-network-name", "pass-to-tertiary-network");
}

void monitorWiFi()
{
  // Kiểm tra nếu chưa kết nối đến 1 mạng wifi nào sẽ cài đặt connectioWasAlive = false
  // đồng thời in ra dấu "." sau mỗi 500ms nếu chưa được kết nối.
  if (wifiMulti.run() != WL_CONNECTED)
  {
    if (connectioWasAlive == true)
    {
      connectioWasAlive = false;
      Serial.print("Looking for WiFi ");
    }
    Serial.print(".");
    delay(500);
  }
  // Nếu đã kết nối đến 1 trong các mạng wifi sẽ in ra tên mạng wifi và set connectioWasAlive = true
  // để khi mất kết nối chương trình sẽ vào phần if (connectioWasAlive == true) nhằm thông báo đang
  // tìm kiếm mạng wifi
  else if (connectioWasAlive == false)
  {
    connectioWasAlive = true;
    Serial.printf(" connected to %s\n", WiFi.SSID().c_str());
  }
}

void loop()
{
  monitorWiFi();
}
