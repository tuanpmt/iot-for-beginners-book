#include <ESP8266WiFi.h>          //https://github.com/esp8266/Arduino

//các thư viện cần thiết
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "WiFiManager.h"          //https://github.com/tzapu/WiFiManager

void configModeCallback (WiFiManager *myWiFiManager)
{
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

  // Cài đặt thông số ban đầu
void setup()
{
  Serial.begin(115200);

  //Khai báo wifiManager thuộc class WiFiManager, được quy định trong file WiFiManager.h
  WiFiManager wifiManager;
  //có thểreset các cài đặt cũ bằng cách gọi hàm:
  //wifiManager.resetSettings();

  //Cài đặt callback, khi kết nối với wifi cũ thất bại, thiết bị sẽ gọi hàm callback
  //và khởi động chế độ AP với SSID tự động là "ESP"
  wifiManager.setAPCallback(configModeCallback);
  if (!wifiManager.autoConnect())
  {
    Serial.println("failed to connect and hit timeout");
  //Nếu kết nối thất bại, thử kết nối lại bằng cách reset thiết bị
    ESP.reset();
    delay(1000);
  }
  //Nếu kết nối wifi thành công, in thông báo ra màn hình
  Serial.println("connected...yeey :)");

}

void loop()
{
  // Chương trình chính
}
