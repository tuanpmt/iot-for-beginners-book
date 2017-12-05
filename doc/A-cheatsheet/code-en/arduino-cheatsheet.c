/* BASIC STRUCTURE OF A SKETCH */
void setup() {
  /*
  This function is called at the starting point of sketch.
  Using to initialize variables, ports configuration, import libraries, etc.
  This code runs only one time(boots up or reset board)
  */
}
void loop() {
  // Infinitely repeated inside loop()
}

/* CONDITIONAL STATEMENTS */
if (x < 5)      // execute if x<5
 { code }
else if (x > 10)// execute if x>10
	{ code }
else { code }   // execute in other cases

switch (var) {  // execute the case which match the value of var
case 1:
...
break;
case 2:
...
break;
default:
...
}

/* LOOPS */
/* Execute if x<5 */
while (x < 5) { code };
/* Execute code, evaluate, if x<0 continue the code */
do { code } while(x < 0);
/* Initialize i, execute code then increase i if i < 10 */
for (int i = 0; i < 10; i++) { code };
/* Quit the loop (for, while, do-while) instantly */
break;
/* Jump to the next cycle of current loop */
continue;

/* FUNCTIONAL DEFINITIONS*/
<ret. type> <name>(<params>) { ... }
int func_name(int x) { return x*2; }
return x; // x must match the return type of the function
return;   // return type for void function

/* INCLUDE */
/* include standard library */
#include <stdio.h>
/* include user’s library */
#include "your-library.h"

/* STRING DATA TYPE */
/* String included the end of string character \0 (null) */
char str1[8] = {'A','r','d','u','i','n','o','\0'};
/* Compiler automatically add the character \0 into the end of string */
char str2[8] = {'A','r','d','u','i','n','o'};
/* String delcareation, without the number of children and assign the value*/
char str3[] = "Arduino";
/* Declare and assign the value for string */
char str4[8] = "Arduino";

/* ARRAY DATA TYPE */
/* Declare an array of int with 6 children and assign values for each */
int myPins[] = {2, 4, 8, 3, 6};
/* integer array of 6 children without values assignment */
int myInts[6];
myInts[0] = 42; // Assign the value of 42 for the first child
myInts[6] = 12; // FAILED ! array index is only from 0 to 5

/*Qualifiers*/
static    // Does not change the value
volatile  // In RAM (Usually used with interrupt)
const     // Constant (read only)
PROGMEM   /* Allow to save data in FLASH instead of SRAM */

/* OPERATOS, OPERATIONS */
/* Popular operators */
=   assignment operator
+   addition operator
-   subtraction operator
*   multiply operator
/   division operator
%   modulus operator
==  equality operator
!=  inequality operator (different)
<   less than operator
>   greater than operator
<=  less or equal operator
>=  greater or equal operator &&  logical AND operator (AND)
||  logical OR operator (OR)
!   logical NOT operator (NOT)

/* Compound assignment operators */
++ increment operator
-- subtraction operator
+= addition assignment operator
   ex: x = 5; x+= 1; //x = 6
-= subtraction assignment operator
   ex: x = 5; x-= 1; //x = 4
*= multiplication assignment operator
   ex: x = 5; x*= 3; //x = 15
/= division assignment operator
   ex: x = 6; x/= 2; //x = 3
&= logical AND assignment operator
   ex: x = 0b1010; x&= 0110; //x =0b0010
|= logical OR assignment operator
   ex: x = 0b1010; x&= 0110; //x =0b1110

/* Bitwise operators */
&   and          ^   xor
<<  bitwise left shift
>>  bitwise right shift
|  or           ~   not

/* Pointer operators */
&reference:  // address-of
*dereference:// value-of

/* CONSTANS AND DATA TYPES */
123     Decimal number
0b0111  Binary number
0173    Octal - base 8
0x7B    Hexal - base 16
123U    Unsigned integer
123L    Signed integer 4 bytes
123UL   Unsigned integer 4bytes
123.0   Real number
1.23e6  Real number with exponential
ex: 1.23*10^3 = 1230

/* DATA TYPE RANGE */
boolean       true | false
char          -128        - 127, 'a' '$' etc.
unsigned char 0           - 255
byte          0           - 255
int           -32768      - 32767
unsigned int  0           - 65535
word          0           - 65535
long          -2147483648 - 2147483647
unsigned long 0           - 4294967295
float         -3.4028e+38 - 3.4028e+38
double        -3.4028e+38 - 3.4028e+38
void          i.e., no return value

/* VARIABLES DECLARATION */
int       a;
int       a = 0b01111011, b = 0123, c = 1, d;
float     fa = 1.0f;
double    da = 1.0;
char      *pointer;
char      *other_pointer = NULL;

/**
 * BUILT-IN FUNCTIONS
 * Pin Input/Output
 * Digital I/O - pins 0-13 A0-A5
 */
/* Ports configuration */
pinMode(pin,[INPUT, OUTPUT, INPUT_PULLUP])
/* Read the value of port pin_6 and assign to a */
int a = digitalRead(pin_6);
/* Configure the HIGH/LOW level for pin_5 */
digitalWrite(pin_5, [HIGH, LOW])
/* Read values of pins and assign to a, pin A0-->A5 */
int a = analogRead(pin)

/* PWM output - pins 3 5 6 9 10 11
 * ESP8266: pin 0..16, range = 0..1023, 1KHz default
 */
/* Assign PWM for pin */
analogWrite(pin, value)
/* ESP8266: change the PWM RANGE output */
analogWriteRange(new_range)
/* ESP8266: PWM frequency output */
analogWriteFreq(new_frequency)

/* ADVANCED I/O */
/* Generate the square wave with frequency freq_Hz and duty cycle=50% */
tone(pin, freq_Hz)
/* Generate the square wave with frequency freq_Hz, duration mili second */
tone(pin, freq_Hz, duration_ms)
/* Stop generate the square wave with frequency tone() */
noTone(pin)
/* Shift 1 byte, 1 bit each, left end first */
shiftOut(dataPin, clockPin,[MSBFIRST, LSBFIRST], value)
/* Return (ms) of pulse HIGH/LOW on port */
unsigned long pulseIn(pin,[HIGH, LOW])

/* INTERRUPT FUNCTION */
/* Configure interrupt function on ports */
attachInterrupt(interrupt, func, mode)
/*
interrupt: number of interruption (normally interrupt ports)
func : called on interrupt (notice : there is no attributes and return type)
mode : including LOW,CHANGE, RISING, FALLING. Interruption will be triggered when the interrupt ports match the corresponding mode
*/
/* Disable interrupt */
detachInterrupt(interrupt)
/* Disable all interrupts */
noInterrupts()
/* Allow interrupt after unsigned noInterrupts() */
interrupts()

/*************************************************
 *            POPULAR LIBRARIES                 *
 *************************************************/

/*************************************************
 *                     Serial                    *
 *Library to communicate with PC or via RX/TX*
 *************************************************/
/* Configure the connection serial-UART with speed */
begin(long speed)
/* Disable serial connection */
end()
/* Return number of bytes to read */
int available()
/* read data from serial (return the first byte of serial data or -1 if there is no data */
int read()
/* Wait for the completion of serial data transfer */
flush()
/* Output data to serial port (with any type of configured data */
print(data)
/* Same with print(data) but after print serial-port, cursor jump to the next line */
println(data)
/* Send data value/string/array to serial port */
write(byte)
/* Function called when there is data comes from RX pin */
SerialEvent()

/*************************************************
 *                  Servo.h                      *
 *     Library support to control servo motor *
 *************************************************/
/*
Setup port to connect with servo and the pulse’s width
pin : Port to connect with servo
[min_uS, max_uS] : Pulse’s width by us accompany with rotation angle from 0 to 180
*/
attach(pin, [min_uS, max_uS])
/* Write rotation angle data 0~180 */
write(angle)
/* Write the value to control rotation angle for servo, value from 700 ~ 2300 */
writeMicroseconds(uS)
/* Read the value of rotation angle (0 to 180) */
int read()
/* Return true if servo connected to pin */
bool attached()
/* Detach servo variable from the connected pin */
detach()

/*************************************************
 *                       Wire.h                  *
 *               Used with I2C connection        *
 *************************************************/
 /* Master initialize the Wire library with I2C connection */
begin()
/* Slave join the i2C connection, addr is the 7 address bits of slave */
begin(addr)
/*
Master request some bytes from slave:
address: 7bits of address of slave.
count: Number of requested bytes from master
stop: Boolean, if true, master stop after request and release I2C bus, if false, master request to restart to keep the connection
*/
requestFrom(address, count, stop)
/* Send the begin signal, data send to the slave with address addr */
beginTransmission(addr)
/* Send data (1 byte) to slave */
send(byte)
/* Send data (string) to slave */
send(char * string)
/* Send data (an array )with number of byte is size */
send(byte * data, size)
/* Send stop signal to slave */
endTransmission()
/* Return available byte after read by read() */
int available()
/* Access to 1 byte transmitted from slave to master
Or in the reverse direction when received the requestFrom. Return the next received byte */
byte receive()
/* handler function is called when slave received data */
onReceive(handler)
/* Handler is called when master request data */
onRequest(handler)

/*************************************************
 *                    ESP8266                   *
 *************************************************/

/* Use when the program need to executes multiple tasks at the same time, support library <Scheduler.h> */
void yield();
/* Reset ESP */
void ESP.reset();
/* Return the size of free memory in heap */
uint32_t ESP.getFreeHeap();
/* Return ID of ESP chip */
uint32_t ESP.getChipId();

/*  WIFI STATION CONFIGURATION MODE */
/* Station mode configuration */
WiFi.mode(WIFI_STA);
/* Connect to AP */
WiFi.begin(ssid, password);
/* Disconnect to the current network wifi */
bool WiFi.disconnect();
/* Return IP address of current station */
WiFi.localIP();
/* Return connection status when connected to AP */
WiFi.status();
/* Return the name of connected network WiFi */
WiFi.SSID();
/* Return strength of WiFi (dBm) */
WiFi.RSSI();
/* Begin configure WPS mode */
WiFi.beginWPSConfig();
/* Begin configure the smart configure mode */
WiFi.beginSmartConfig();

/* WIFI SOFT ACCESS POINT (AP) MODE */
/* Declare an AP with name and password */
WiFi.softAP(ssid, password);
/* Declare an AP and set up the AP with IP address, gateway and subnet */
WiFi.softAPConfig (local_ip, gateway, subnet);
/* Return the number of stations connected to AP */
WiFi.softAPgetStationNum();
/* Disconnect stations */
WiFi.softAPdisconnect(wifioff);
/* Return IP address of AP */
WiFi.softAPIP();
/* Return MAC address of AP */
WiFi.softAPmacAddress(mac);

/* WIFI FEATURES */
/* SCAN */
/* Set up station mode */
WiFi.mode(WIFI_STA);
/* Scan and return the number of available network */
WiFi.scanNetworks();
/* Return name of network (string format) at position num */
WiFi.SSID(num).c_str();
/* Return information of all networks */
WiFi.getNetworkInfo(networkItem,&ssid,
&encryptionType, &RSSI,*&BSSID, &channel, &isHidden)

/* DIAGNOSTICS */
/*
* Objectives : Analyze, provide information an repair when there is no connection to WiFi network
*/
/* Print out serially diagnostic result of network */
WiFi.printDiag(Serial);
/* Enable debug mode */
Serial.setDebugOutput(true);

/* WEBSERVER */
/* Host TCP at port 80 response HTTP requests from client */
ESP8266WebServer server (80);
/* Server begins to listen clients */
server.begin();
/* Write data to clients */
server.write(buf, len)
/* Set up server at URL, handleRoot is the content or function will be executed */
server.on ( "URL", handleRoot );
/* Server react with clients to send, receive data */
server.handleClient();
/* Return 1 if val is exist on server */
server.hasArg(val)
/* Get value of variable val on server */
server.arg(val);
/* Request update data from server:
code : HTTP code
text/html : Returned format is HTML
content: Content returned from server */
server.send (code, "text/html",content);

/* MQTT */
/*
Libraries which support MQTT prototype for ESP8266
on arduino usually used is ESP8266MQTTClient and PubSubClient. Bellow content explain functions of libraries
*/
/* Functions of ESP8266MQTTClient library*/
/* Declare a MQTTClient variable mqtt */
MQTTClient mqtt;
/* Get data from subscribed topic */
mqtt.onData([](String topic, String data, bool cont)
/* Unsubscribe topic /qos0 */
mqtt.unSubscribe("/qos0");
/*Subscribe topic and publish messages */
mqtt.onSubscribe([](int sub_id)
/* Publish a message "qos0" to topic /qos0 with QoS =0,
and Retain = 0 */
mqtt.publish("/qos0", "qos0", 0, 0);
/* Connect to server MQTT */
mqtt.onConnect([]()
/* Subscribe topic and receive message at topic /qos0 */
mqtt.subscribe("/qos0", 0)
/* Begin to transfer data with broker MQTT at url
mqtt://test.mosquitto.org port 1883 */
mqtt.begin("mqtt://test.mosquitto.org:1883")
/* Function called inside loop() to initialize MQTT, check and process data from topics, check attributes of prototypes such as keep-a-live, QoS... */
mqtt.handle();

/* Functions of PubSubClient library*/
/* Declare PubSubClient variable espClient */
PubSubClient client(espClient);
/* Publish data pack "Connected!" to topic ESP8266 */
client.publish("ESP8266", "Connected!");
/* Subscribe to receive messages from topic ESP8266 */
client.subscribe("ESP8266");
/* Set up server to listen client at port 1883 */
client.setServer(url_server, 1883);
/* Callback function to publish/subscribe */
client.setCallback(callback);
/* Function called inside loop() to initialize MQTT, check and process data from topics, check attributes of prototypes such as keep-a-live, QoS data pack... */
client.loop();
