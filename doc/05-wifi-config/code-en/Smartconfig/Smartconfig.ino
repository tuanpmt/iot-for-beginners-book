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

/* Button state check function*/
bool longPress()
{
  static int lastPress = 0;
  if (millis() - lastPress > 3000 && digitalRead(PIN_BUTTON) == 0) { // If button is pressed in more than 3 seconds then...
    return true;
  } else if (digitalRead(PIN_BUTTON) == 1) {                         //  If button is pressed in lest than 3 seconds then...
    lastPress = millis();                                            // `lastPress` variable is assigned when this condition is true.
  }
  return false;
}

void tick()
{
  int state = digitalRead(PIN_LED); // Get current LED's state (on GPIO 16)
  digitalWrite(PIN_LED, !state);    // Invert LED's state.
}

bool in_smartconfig = false;        // This variable stores the state of smartconfig mode.
                                    // "True" means this mode is running and vice versa.
//

/* Start Smartconfig mode */
void enter_smartconfig()
{
  if (in_smartconfig == false) {          // If smartconfig state variable is "false" i.e the smartconfig mode is currently off, then
    in_smartconfig = true;                // Assign "true" value to smartconfig state variable.
    ticker.attach(0.1, tick);             // Blinking in 0.1 seconds period.
    WiFi.mode(WIFI_STA);                  // Configure ESP8266 as Station mode.
    WiFi.beginSmartConfig();              // Start Smartconfig mode.
    Serial.println("Enter smartconfig");  // Print message "Enter smartconfig" to terminal's screen.
  }
}

/* Exit Smartconfig mode*/
void exit_smart()
{
  ticker.detach();                                // Stop blinking LED.
  LED_ON();                                       // Turn LED ON.
  in_smartconfig = false;                         // Reset button's state variable..
  Serial.println("Connected, Exit smartconfig");  // Print message to terminal.
}

/* Set up the serial connection, input and output */
void setup() {
  Serial.begin(115200);           // Baudrate = 115200
  Serial.setDebugOutput(true);    // Use this to enable printing debug log to terminal via serial connection.
  pinMode(PIN_LED, OUTPUT);       // Configure the OUTPUT mode for LED's GPIO. .
  pinMode(PIN_BUTTON, INPUT);     // Configure the INPUT mode for the built-in BUTTON's GPIO.
  Serial.println("Setup done");   // Print message "Setup done" to the terminal.
}

/* Main program */
void loop() {
  if (longPress()) {              // Call longPress() to check button's state
    enter_smartconfig();          // If "true", enter smartconfig mode
  }
  if (WiFi.status() == WL_CONNECTED && in_smartconfig && WiFi.smartConfigDone()) {
                                  // Check WiFi connection status and smartconfig's state
    exit_smart();                 // When your device has successfully connected to WiFi, exit smartconfig mode.
  }
  if (WiFi.status() == WL_CONNECTED) {
    //Your program will be executed here when your device has been connected to WiFi.
  }
}
