int ledPin = 16;                 // LED is connected to pin GPIO16
int btnPin = 0;                  // Push button is connected to pin GPIO0
int ledState = LOW;

void blink()
{
  if (ledState == LOW) {
    ledState = HIGH;
  } else {
    ledState = LOW;
  }
  digitalWrite(ledPin, ledState); // Reverse state of led & and print out serial terminal
  Serial.println("Pressed, value=" + String(ledState));
}

bool isPressed()
{
  return (digitalRead(btnPin) == 0);
}
void setup()
{
  pinMode(ledPin, OUTPUT);       // Sets the digital pin as OUTPUT
  pinMode(btnPin, INPUT_PULLUP); // The push button is configured as a pull-up input

  Serial.begin(115200); // Sets the data rate in bits per second (baud) 115200 for serial data transmission
}

void loop()
{
  if (isPressed()) {
    blink();
  }
}
