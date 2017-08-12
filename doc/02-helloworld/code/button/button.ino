int ledPin = 16;                 // LED nối vào chân 16
int btnPin = 0;                  // Nút nhấn nối vào chân 0
int ledState = LOW;

void blink()
{
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(ledPin, ledState);
  Serial.println("Pressed, value=" + String(ledState));
}
void setup()
{
  pinMode(ledPin, OUTPUT);      // sets the digital pin as output
  pinMode(btnPin, INPUT_PULLUP); // Cấu hình nút nhấn là ngõ vào pull-up
  attachInterrupt(btnPin, blink, FALLING); //cài đặt ngắt cho chân LED
  Serial.begin(115200);
}

void loop()
{
  //Không phải làm gì
}
