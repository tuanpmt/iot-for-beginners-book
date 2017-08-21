#include "DHT.h"
#define DHTPIN 2     // what digital pin we're connected to ①

// Uncomment whatever type you're using! ②
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");

  dht.begin();    // initial DHT11 ③
}

void loop() {

  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature (°C) and  humidity ! ④
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again). ⑤
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // display on serial terminal humiduty value and temprature value ⑥
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
}
