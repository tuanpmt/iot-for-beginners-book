#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <Ticker.h>
#include <time.h>

#define PIN_LED 16
#define PIN_BUTTON 0

#define LED_ON() digitalWrite(PIN_LED, HIGH)
#define LED_OFF() digitalWrite(PIN_LED, LOW)
#define LED_TOGGLE() digitalWrite(PIN_LED, digitalRead(PIN_LED) ^ 0x01)

Ticker ticker;

/// Xét trạng thái hiện tại của button
bool longPress()
{
  static int lastPress = 0;
  if (millis() - lastPress > 3000 && digitalRead(PIN_BUTTON) == 0) {   // Nếu button được nhấn và giữ trong 3s thì
    return true;                                                       // trả về "true".
  } else if (digitalRead(PIN_BUTTON) == 1) {                           // Nếu button không nhấn và giữ đủ 3s
    lastPress = millis();                                              // thì gán biến lastPress bằng thời điểm khi
  }                                                                    // gọi hàm, và trả về "false"
  return false;                                                        //
}

void tick()
{
  int state = digitalRead(PIN_LED);               // Lấy trạng thái hiện tại của LED (GPIO16)
  digitalWrite(PIN_LED, !state);                  // Đảo trạng thái LED.
}

bool in_smartconfig = false;                      // biến trạng thái kiểm tra thiết bị có đang trong chế độ
                                                  // smartconfig hay không.

/// Vào chế độ Smartconfig
void enter_smartconfig()
{
  if (in_smartconfig == false) {                  // Nếu thiết bị không ở trong chế độ smartconfig
    in_smartconfig = true;                        // Gán biến trạng thái là đang trong chế độ smartconfig
    ticker.attach(0.1, tick);                     // Nhấp nháy led chu kì 0.1s.
    WiFi.mode(WIFI_STA);                          // Thiết lập kết nối cho thiết bị ở chế độ Station mode
    WiFi.beginSmartConfig();                      // Bắt đầu chế độ smartconfig
    Serial.println("Enter smartconfig");          // in thông báo "Enter smartconfig" ra màn hình
  }
}

// Thoát chế độ smartconfig
void exit_smart()
{
  ticker.detach();                                // Ngừng nháy led
  LED_ON();                                       // Bật LED
  in_smartconfig = false;                         // Gán biến trạng thái trở về ban đầu.
  Serial.println("Connected, Exit smartconfig");  // In thông báo ra màn hình.
}

// Cài đặt các thông số ban đầu
void setup() {
  Serial.begin(115200);                           // Tốc độ baud = 115200
  Serial.setDebugOutput(true);                    // hiển thị các thông tin debug hệ thống lên màn hình qua serial

  pinMode(PIN_LED, OUTPUT);                       // Cấu hình GPIO cho các chân LED và button
  pinMode(PIN_BUTTON, INPUT);                     // Chớp tắt led chu kì 1s
  Serial.println("Setup done");                   // In thông báo đã cài đặt xong
}

// Chương trình chính
void loop() {
  if (longPress()) {                              // Gọi hàm longPress kiểm tra trạng thái button
    enter_smartconfig();                          // Nếu button được nhấn giữ trong 3s thì vào trạng thái smartconfig
  }
  if (WiFi.status() == WL_CONNECTED && in_smartconfig && WiFi.smartConfigDone()) { // Kiểm tra trạng thái kết nối wifi,
                                                  // các thông số cấu hình cũng như trạng thái smartconfig
    exit_smart();                                 // khi thiết bị đã hết nối wifi thành công, thoát chế độ smartconfig
  }
  if (WiFi.status() == WL_CONNECTED) {
    //do something
  }
}
