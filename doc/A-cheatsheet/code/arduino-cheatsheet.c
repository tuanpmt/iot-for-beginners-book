/* Basic Program Structure */

void setup() {
  /* Runs once when sketch starts */
}
void loop() {
  /* Runs repeatedly */
}

/* condition */
if (x < 5) { ... }
else if (x > 10) { ... } //option
else { ... }             //option

/* loop */
while (x < 5) { ... }

do { ... } while(x < 0);

for (int i = 0; i < 10; i++) { ... }


break;    // Exit a loop immediately
continue; // Go to next iteration

switch (var) {
case 1:
...
break;
case 2:
...
break;
default:
...
}

/* Function Definitions */
/* <ret. type> <name>(<params>) { ... } */
int func_name(int x) { return x*2; }

return x; // x must match return type
return;   // For void return type

/* Include */
#include <stdio.h>        //standard library
#include "your-library.h" //Custom library

/* Strings */
/* Includes \0 null termination */
char str1[8] = {'A','r','d','u','i','n','o','\0'};

/* Compiler adds null termination */
char str2[8] = {'A','r','d','u','i','n','o'};
char str3[] = "Arduino";
char str4[8] = "Arduino";

/*Arrays*/
int myPins[] = {2, 4, 8, 3, 6}; // Array of 6 ints
int myInts[6];
myInts[0] = 42; // Assigning first
myInts[6] = 12; // ERROR! Indexes, are 0 though 5

/*Qualifiers*/
static       persists between calls
volatile     in RAM (nice for ISR)
const        read-only
PROGMEM      in flash

/* General Operators */
=   assignment
+   add
-   subtract
*   multiply
/   divide
%   modulo
==  equal to
!=  not equal to
<   less than
>   greater than
<=  less than or equal to
>=  greater than or equal to
&&  and
\|\|  or
!   not

/* Compound Operators */
++ increment
-- decrement
+= compound addition
-= compound subtraction
*= compound multiplication
/= compound division
&= compound bitwise and
\|= compound bitwise or

/* Bitwise Operators */
& bitwise and  \|  bitwise or
^ bitwise xor  ~  bitwise not
<< shift left  >> shift right
/* Pointer Access */
& reference: get a pointer
* dereference: follow a pointer

/*Numeric Constants*/
123         decimal
0b01111011  binary
0173        octal - base 8
0x7B        hexadecimal base 16
123U        force unsigned
123L        force long
123UL       force unsigned long
123.0       force floating point
1.23e6      1.23*10^6 = 1230000

/* Data types */
boolean       true \| false
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

/* Variable declare */
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
pinMode(pin,
[INPUT, OUTPUT, INPUT_PULLUP])
int digitalRead(pin)
digitalWrite(pin, [HIGH, LOW])

/*Analog In - pins A0-A5*/
int analogRead(pin)
analogReference(
[DEFAULT, INTERNAL, EXTERNAL])

/*PWM Out - pins 3 5 6 9 10 11 */
analogWrite(pin, value)

/*Advanced I/O*/
tone(pin, freq_Hz)
tone(pin, freq_Hz, duration_ms)
noTone(pin)
shiftOut(dataPin, clockPin,
[MSBFIRST, LSBFIRST], value)
unsigned long pulseIn(pin,
[HIGH, LOW])

/*Time*/
unsigned long millis() // Overflows at 50 days
unsigned long micros() // Overflows at 70 minutes
delay(msec)
delayMicroseconds(usec)

/*Math*/
min(x, y)    max(x, y)
abs(x)       sin(rad)
cos(rad)     tan(rad)
sqrt(x)      pow(base, exponent)
constrain(x, minval, maxval)
map(val, fromL, fromH, toL, toH)

/*Random Numbers*/
randomSeed(seed) // long or int
long random(max) // 0 to max-1
long random(min, max)

/*Bits and Bytes*/
lowByte(x)
highByte(x)
bitRead(x, bitn)
bitWrite(x, bitn, bit)
bitSet(x, bitn)
bitClear(x, bitn)
bit(bitn) // bitn: 0=LSB 7=MSB

/*Type Conversions*/
char(val)   byte(val)
int(val)    word(val)
long(val)   float(val)

/*External Interrupts*/
attachInterrupt(interrupt, func,
[LOW, CHANGE, RISING, FALLING])
detachInterrupt(interrupt)
interrupts()
noInterrupts()

/**LIBRARIES**/

/* Serial - comm. with PC or via RX/TX */
begin(long speed) // Up to 115200
end()
int available() // #bytes available
int read() // -1 if none available
int peek() // Read w/o removing
flush()
print(data)
println(data)
write(byte)
write(char * string)
write(byte * data, size)
SerialEvent() // Called if data rdy

/* Servo.h - control servo motors */
attach(pin, [min_uS, max_uS])
write(angle) // 0 to 180
writeMicroseconds(uS) //1000-2000; 1500 is midpoint
int read() // 0 to 180
bool attached()
detach()

/*Wire.h - I2C communication*/
begin() // Join a master

begin(addr) // Join a slave @ addr
requestFrom(address, count)
beginTransmission(addr) // Step 1
send(byte) // Step 2
send(char * string)
send(byte * data, size)
endTransmission() // Step 3
int available() // #bytes available
byte receive() // Get next byte
onReceive(handler)
onRequest(handler)
