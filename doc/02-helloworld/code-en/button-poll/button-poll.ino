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
  digitalWrite(ledPin, ledState); //Đảo trạng thái LED & in ra serial
  Serial.println("Pressed, value=" + String(ledState));
}

bool isPressed()
{
  return (digitalRead(btnPin) == 0);
}
void setup()
{
  pinMode(ledPin, OUTPUT);       // Cấu hình LED là ngõ ra
  pinMode(btnPin, INPUT_PULLUP); // Cấu hình nút nhấn là ngõ vào pull-up

  Serial.begin(115200);
}

void loop()
{
  if (isPressed()) {
    blink();
  }
}
