int pin_led = 16;
/* hàm này được gọi 1 lần duy nhất khi khởi động */
void setup() {

  pinMode(pin_led, OUTPUT);    // cấu hình pin 16 là ngõ ra
}

/* hàm loop sẽ được gọi liên tục */
void loop() {
  digitalWrite(pin_led, HIGH); // tắt LED (HIGH - có nghĩa là mức cao)
  delay(1000);                 // chờ 1 giây
  digitalWrite(pin_led, LOW);  // bật LED bởi mức điện áp LOW
  delay(1000);                 // chờ 1 giây
}
