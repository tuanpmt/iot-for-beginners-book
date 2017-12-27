int pin_led = 16;
/* put your setup code here, to run once */
void setup() {

  pinMode(pin_led, OUTPUT);    // initialize digital pin pin_led as an output
}

/* put your main code here, to run repeatedly */
void loop() {
  digitalWrite(pin_led, HIGH); // LED OFF (HIGH level)
  delay(1000);                 // delay 1s
  digitalWrite(pin_led, LOW);  // bLED ON (LOW level)
  delay(1000);                 // delay 1s
}
