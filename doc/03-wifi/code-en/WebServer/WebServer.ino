#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "........";
const char* password = "........";
const int led = 16; //LED pin = gpio16
/* HTML sent to the clien */
const char *html = \
"<html>\
  <head>\
    <title>ESP8266 Webserver</title>\
  </head>\
  <body>\
    <a href=\"/on\">ON</a>\
    <a href=\"/off\">OFF</a>\
  </body>\
</html>";

/* Web Server listening on port 80 */
ESP8266WebServer server(80);

/* The function is called when the browser queries '/on'
 * turn on the LED (0 = on), the redirect the browser
 * back to the main page '/'
 */
void handleOn() {
  digitalWrite(led, 0);
  server.sendHeader("Location","/");
  server.send(301);
}

/* The function is called when the browser queries '/off'
 * turn off the LED (1 = off), the redirect the browser
 * back to the main page '/'
 */
void handleOff() {
  digitalWrite(led, 1);
  server.sendHeader("Location","/");
  server.send(301);
}

/* The function is called when the browser queries the main page '/'
 * send the HTML content, providing the options to toggle the LED
 */
void handleRoot() {
  server.send(200, "text/html", html);
}

void setup(void){
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");

   /* We can scan for ESP8266's IP
   * using the following function
   */
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/on", handleOn);
  server.on("/off", handleOff);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
