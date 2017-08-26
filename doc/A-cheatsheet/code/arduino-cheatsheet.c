/* Cấu trúc cơ bản của 1 Sketch */

void setup() {
  /* 
  Hàm được gọi khi bắt đầu sketch. Dùng để khởi tạo 
  biến, cấu hình chân, khởi tạo thư viện...  
  Code trong setup chỉ chạy 1 lần (khi khởi động hoặc reset board)
  */
}
void loop() {
  /* Nội dung trong loop() lặp lại liên tục*/
}

/* Lệnh rẻ nhánh */
if (x < 5) { code } //thực thi code nếu x<5
else if (x > 10) { code } // thực thi code nếu x>10
else { code } //thực thi code các trường hợp còn lại 
//-------------------------------------
switch (var) { //Thực thi case có giá trị var 
case 1:
...
break;
case 2:
...
break;
default: 
...
}
/* Các kiểu vòng lặp */

// thực hiện code nếu x<5	
while (x < 5) { code };

// thực hiện code, so sánh, nếu x<0 tiếp tục thực hiện code
do { code } while(x < 0);

// khởi tạo i, vẫn thực hiện code và tăng i nếu i <10  
for (int i = 0; i < 10; i++) { code };


break;    // Thoát ra vòng lặp (for, while, do...while) ngay lập tức
continue; // Đi đến chu kì lặp tiếp theo của vòng lặp hiện tại.



/* Các định nghĩa về hàm */
/* <ret. type> <name>(<params>) { ... } */
int func_name(int x) { return x*2; }

return x; // x phải trùng khớp với kiểủ trả về của hàm
return;   // loại return dành cho hàm void

/* Include */
#include <stdio.h>        //include thư viện chuẩn
#include "your-library.h" //include thư viện tạo bởi người dùng

/* Strings */
/* Chuỗi bao gồm kí tự kết thúc chuỗi \0 (null)*/
char str1[8] = {'A','r','d','u','i','n','o','\0'};

/*trình biên dịch sẽ tự động thêm kí tự \0 vào cuối chuỗi*/
char str2[8] = {'A','r','d','u','i','n','o'};
//Khai báo mảng (không khai báo số phần tử)và gán giá trị
char str3[] = "Arduino"; 
//Khai báo và gán giá trị cho mảng char 8 phần tử
char str4[8] = "Arduino"; 

/*Arrays*/
//Mảng kiểu int có 6 phần tử và gán giá trị cho mỗi phần tử 
int myPins[] = {2, 4, 8, 3, 6};

//Mảng kiểu int 6 phần tử và không gán giá trị
int myInts[6];

// Gán giá trị 42 cho phần tử đầu tiên
myInts[0] = 42; 

myInts[6] = 12; // LỖI ! chỉ số của mảng chỉ từ 0 đến 5

/*Qualifiers*/
static    //không thay đổi giá trị ở các lần gọi 
volatile  //in RAM (Thường dùng trong ngắt)
const     //không đổi (chỉ đọc)
PROGMEM   //cho phép lưu trữ dữ liệu trong bộ nhớ FLASH thay vì SRAM 

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

/* Các toán tử hợp nhất */
++ tăng 1 đơn vị
-- giảm 1 đơn vị
+= compound addition
ex: x = 5; x+= 1; //x = 6 
-= compound subtraction
ex: x = 5; x-= 1; //x = 4
*= compound multiplication
ex: x = 5; x*= 3; //x = 15
/= compound division
ex: x = 6; x/= 2; //x = 3 
&= compound bitwise and
ex: x = 0b1010; x&= 0110; //x =0b0010
\|= compound bitwise or
ex: x = 0b1010; x&= 0110; //x =0b1110
/* Các toán tử trên bit */
& and         \| or
^ xor         ~  not
<< dịch trái  >> dịch phải 

/* Thực thi với con trỏ */
& reference:   // lấy địa chỉ của biến mà con trỏ trỏ tới 
* dereference: // lấy giá trị của biến mà con trỏ trỏ tới

/*Hằng số và kiểu dữ liêu*/
123         //số thập phân
0b01111011  //số nhị phân
0173        //octal - base 8
0x7B        //số thập lục phân base 16
123U        //số nguyên không dấu
123L        //số nguyên có dấu 4 bytes
123UL       //số nguyên không dấu 4bytes 
123.0       //số thực 
1.23e6      //1.23*10^6 = 1230000

/* Kiểu dữ liệu và phạm vi của dữ liệu*/
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

/* Khai báo biến */
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
//Thiết lập cấu hình chân
pinMode(pin,
[INPUT, OUTPUT, INPUT_PULLUP])

//đọc giá trị của pin_6 và gán cho a
int a = digitalRead(pin_6);

//set mức HIGH/LOW cho pin_5
digitalWrite(pin_5, [HIGH, LOW])

/*Ngõ vào analog, từ chân A0-->A5*/

//Đọc giá trị của pin và gán cho a 
int a = analogRead(pin)
//cấu hình điện áp tham chiếu cho ngõ vào analog
analogReference(
[DEFAULT, INTERNAL, EXTERNAL])

/*PWM ngõ ra - pins 3 5 6 9 10 11 */
// cài đặt giá trị điện áp cho pin sử dụng PWM 
analogWrite(pin, value)

/*Advanced I/O*/
//Tạo sóng vuông tần số freq_Hz với duty cycle = 50% 
tone(pin, freq_Hz)

//Tạo sóng vuông tần số freq_Hz trong duration_ms mili giây 
tone(pin, freq_Hz, duration_ms)
// Ngừng việc tạo sóng vuông khi dùng tone()
noTone(pin)
//dịch 1 byte dữ liệu, mỗi lần dịch 1 bit, bắt đầu từ bit cao
shiftOut(dataPin, clockPin,
[MSBFIRST, LSBFIRST], value)

unsigned long pulseIn(pin,
[HIGH, LOW])

/*Time*/
//Đếm thời gian từ lúc cấp nguồn (mili giây, tràn trong khoảng 50 ngày
unsigned long millis()
//Đếm thời gian từ lúc cấp nguồn (micro giây), tràn trong khoảng 70 phút
unsigned long micros()
//tạo thời gian trễ theo mili giây
delay(msec)
//tạo thời gian trễ theo mili giây
delayMicroseconds(usec)

/*Các hàm toán học */
min(x, y) // lấy giá trị nhỏ nhất của x và y
max(x, y) // lấy giá trị lớn nhất của x và y
abs(x)    // Lấy giá trị tuyệt dodojois của a
sin(rad)  // trả về góc kiểu double (-1 đến 1)
cos(rad)  
tan(rad)
sqrt(x)   // lấy căn bậc 2 của x
pow(base, exponent) // hàm lấy số mũ 
constrain(x, minval, maxval) // giới hạn x từ minval đến maxval
// thực hiện ánh xạ giá trị fromL đến toL, fromH từ toH 
map(val, fromL, fromH, toL, toH)

/*Tạo số ngẫu nhiên */
randomSeed(seed) // Tạo số ngẫu nhiên dùng kiểu int/long 
long random(max) // tạo giá trị ngẫu nhiên từ 0 đến max-1
long random(min, max) // tạo giá trị ngẫu nhiên từ min đến max -1

/*Bits and Bytes*/
lowByte(x) // trả về byte thấp nhất của 1 biến kiểu bất kì
highByte(x)//trả về byte cao nhât của biến kiểu word, hoặc byte thấp thứ 2 của kiểu dữ liệu lớn hơn 2 bytes
bitRead(x, bitn)//đọc bit từ vị trí bitn ( 0 bắt đầu ở bên phải) trả về giá trị 0 hoặc 1
bitWrite(x, bitn, bit) // ghi giá trị X  vào bit thứ bitn (từ phải sang trái) của 1 biến x   
bitSet(x, bitn) // viết giá trị 1 vào bit thứ bitn (từ phải sang trái) của biến x
bitClear(x, bitn)//viết giá trị 10vào bit thứ bitn (từ phải sang trái) của biến x

bit(bitn) // tính giá trị của bit thứ bitn (ex bit0 =1; bit1 = 2; bit 3 = 8...) 

/*Ép kiểu*/
// chuyển đổi gía trị của biến val thành kiểu dữ liệu tương ứng  
char(val)   byte(val)
int(val)    word(val)
long(val)   float(val)

/*External Interrupts*/
attachInterrupt(interrupt, func,
[LOW, CHANGE, RISING, FALLING])
detachInterrupt(interrupt)
interrupts()
noInterrupts()

/**Thư viện**/

/* Serial - comm. with PC or via RX/TX */
begin(long speed) // thiết lập giao tiếp serial - UẢT với tốc độ speed 
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

/*Wire.h - Dùng trong giao tiếp I2C */
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
