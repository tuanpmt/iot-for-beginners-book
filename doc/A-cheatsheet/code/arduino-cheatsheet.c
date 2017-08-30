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

while (x < 5) { code };// thực hiện code nếu x<5	

/* thực hiện code, so sánh, nếu x<0 tiếp tục thực hiện code */
do { code } while(x < 0);

/* khởi tạo i, thực hiện code và tăng i nếu i <10 */ 
for (int i = 0; i < 10; i++) { code };

break; // Thoát ra vòng lặp (for, while, do...while) ngay lập tức
continue; // Đi đến chu kì lặp tiếp theo của vòng lặp hiện tại.

/* Các định nghĩa về hàm */
<ret. type> <name>(<params>) { ... }
int func_name(int x) { return x*2; }

return x; // x phải trùng khớp với kiểủ trả về của hàm
return;   // loại return dành cho hàm void

/* Include */
#include <stdio.h>        //include thư viện chuẩn
#include "your-library.h" //include thư viện tạo bởi người dùng



/* Strings */
/* Chuỗi bao gồm kí tự kết thúc chuỗi \0 (null) */
char str1[8] = {'A','r','d','u','i','n','o','\0'};

/* Trình biên dịch tự động thêm kí tự \0 vào cuối chuỗi */
char str2[8] = {'A','r','d','u','i','n','o'};
/*Khai báo mảng (không khai báo số phần tử)và gán giá trị */
char str3[] = "Arduino"; 
/* Khai báo và gán giá trị cho mảng char 8 phần tử */
char str4[8] = "Arduino"; 

/*Arrays*/
/* Khai báo mảng kiểu int có 6 phần tử và gán giá trị cho mỗi phần tử */
int myPins[] = {2, 4, 8, 3, 6};

int myInts[6];  // Mảng kiểu int 6 phần tử và không gán giá trị
myInts[0] = 42; // Gán giá trị 42 cho phần tử đầu tiên
myInts[6] = 12; // LỖI ! chỉ số của mảng chỉ từ 0 đến 5

/*Qualifiers*/
static    //không thay đổi giá trị ở các lần gọi 
volatile  //in RAM (Thường dùng trong ngắt)
const     //không đổi (chỉ đọc)
PROGMEM   //cho phép lưu trữ dữ liệu trong bộ nhớ FLASH thay vì SRAM 

/* Các toán tử thường dùng */
=   toán tử bằng
+   toán tử cộng
-   toán tử trừ
*   toán tử nhân
/   toán tử chia lấy phần nguyên
%   toán tử chia lấy phần dư
==  phép so sánh bằng
!=  phép so sánh không không bằng (khác)
<   phép so sánh nhỏ hơn 
>   phép so sánh lớn hơn
<=  phép so sánh nhỏ hơn hoặc bằng
>=  phép so sánh lớn hơn hoặc bằng
&&  phép toán logic (AND) 
\|\|phép toán logic (OR)
!   phép toán logic (NOT)




/* Các toán tử hợp nhất */
++ tăng 1 đơn vị
-- giảm 1 đơn vị
+= phép toán cộng và gán giá trị
ex: x = 5; x+= 1; //x = 6 
-= phép toán trừ và gán giá trị
ex: x = 5; x-= 1; //x = 4
*= phép toán nhân và gán giá trị
ex: x = 5; x*= 3; //x = 15
/= phép toán chia lấy phần nguyên và gán giá trị
ex: x = 6; x/= 2; //x = 3 
&= phép toán logic AND và gán giá trị 
ex: x = 0b1010; x&= 0110; //x =0b0010
\|= phép toán logic OR và gán giá trị
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
1.23e6      //số thực dùng cơ số mũ ex: 1.23*10^6 = 1230000

/*Kiểu dữ liệu và phạm vi của dữ liệu*/
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

/*Khai báo biến*/
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
/* thiết lập cấu hình chân */
pinMode(pin,[INPUT, OUTPUT, INPUT_PULLUP])
/* đọc giá trị của pin_6 và gán cho a */
int a = digitalRead(pin_6);
/* set mức HIGH/LOW cho pin_5 */
digitalWrite(pin_5, [HIGH, LOW])

/*Ngõ vào analog, từ chân A0-->A5*/
/* đọc giá trị của pin và gán cho a */ 
int a = analogRead(pin)
/* cấu hình điện áp tham chiếu cho ngõ vào analog */
analogReference([DEFAULT, INTERNAL, EXTERNAL])

/*PWM ngõ ra - pins 3 5 6 9 10 11 */
/* cài đặt giá trị điện áp cho pin sử dụng PWM */
analogWrite(pin, value)

/*Advanced I/O*/
/* Tạo sóng vuông tần số freq_Hz với duty cycle = 50% */ 
tone(pin, freq_Hz)
/* Tạo sóng vuông tần số freq_Hz trong duration_ms mili giây */ 
tone(pin, freq_Hz, duration_ms)
/* Ngừng việc tạo sóng vuông khi dùng tone() */
noTone(pin)
/* dịch 1 byte dữ liệu, mỗi lần dịch 1 bit, bắt đầu từ bit cao */
shiftOut(dataPin, clockPin,[MSBFIRST, LSBFIRST], value)
/* Trả về chiều dài (microseconds) của xung HIGH/LOW trên chân muốn đọc */  
unsigned long pulseIn(pin,[HIGH, LOW])

/*Các hàm về thời gian*/
/* Đếm thời gian từ lúc cấp nguồn (mili giây, tràn trong khoảng 50 ngày */
unsigned long millis()
/* Đếm thời gian từ lúc cấp nguồn (micro giây), tràn trong khoảng 70 phút */
unsigned long micros()
/* tạo thời gian trễ theo mili giây */
delay(msec)
/* tạo thời gian trễ theo mili giây */
delayMicroseconds(usec)

/*Các hàm toán học*/
min(x, y) // lấy giá trị nhỏ nhất của x và y
max(x, y) // lấy giá trị lớn nhất của x và y
abs(x)    // Lấy giá trị tuyệt dodojois của a
sin(rad)  // trả về góc kiểu double (-1 đến 1)
cos(rad)  
tan(rad)
sqrt(x)   // lấy căn bậc 2 của x
pow(base, exponent) // hàm lấy số mũ 
constrain(x, minval, maxval) // giới hạn x từ minval đến maxval
/* ánh xạ giá trị fromL đến toL, fromH từ toH */ 
map(val, fromL, fromH, toL, toH)

/*Tạo số ngẫu nhiên */
randomSeed(seed) // Tạo số ngẫu nhiên dùng kiểu int/long 
long random(max) // tạo giá trị ngẫu nhiên từ 0 đến max-1
long random(min, max) // tạo giá trị ngẫu nhiên từ min đến max -1

/*Bits và Bytes*/
/* trả về byte thấp nhất của 1 biến kiểu bất kì */
lowByte(x) 
/* trả về byte cao nhât của biến kiểu word, hoặc byte thấp thứ 2 của kiểu dữ liệu lớn hơn 2 bytes */
highByte(x)
/* đọc bit từ vị trí bitn ( 0 bắt đầu ở bên phải) trả về giá trị 0 hoặc 1 */
bitRead(x, bitn)
/* ghi giá trị X  vào bit thứ bitn (từ phải sang trái) của 1 biến x */
bitWrite(x, bitn, bit) 
/* viết giá trị 1 vào bit thứ bitn (từ phải sang trái) của biến x */
bitSet(x, bitn)
/* viết giá trị 1 vào bit thứ bitn (từ phải sang trái) của biến x */
bitClear(x, bitn)
/* tính giá trị của bit thứ bitn (ex bit0 =1; bit1 = 2; bit 3 = 8...) */
bit(bitn)

/*Ép kiểu*/
/* chuyển đổi gía trị của biến val thành kiểu dữ liệu tương ứng */ 
char(val)   byte(val)
int(val)    word(val)
long(val)   float(val)

/*External Interrupts*/
/* Thiết lập chức năng ngắt đối với các chân digital
 * interrupt: số ngắt (thường là chân sủ dụng chức năng ngắt)
 * func : hàm sẽ được gọi khi ngắt xảy ra (lưu ý : hàm không có tham số
   đầu vào cũng như kiểu trả về)
 * mode : gồm các chế độ LOW,CHANGE, RISING, FALLING. Ngắt sẽ được kích hoạt khi chân ngắt rơi 
   vào mode tương ứng
 */
attachInterrupt(interrupt, func,mode)
/* Stop ngắt đã được kích hoạt từ trước */
detachInterrupt(interrupt)
/* vô hiệu hóa tấ cả các ngắt */
noInterrupts()
/* cho phép tái ngắt sau khi dùng noInterrupts() */
interrupts()

/*Thư viện*/

/* Serial - giao tiếp với PC hoặc thông qua RX/TX */
begin(long speed) // thiết lập giao tiếp serial - UART với tốc độ speed 
end()
int available() // trả về số bytes có sẵn để đọc 
/* đọc dữ liệu đến từ serial (trả về byte đầu tiên của dữ liệu từ serial hoặc -1 nếu dữ liệu không có */
int read() 
flush() // Chờ quá trình truyền dữ liệu serial hoàn tất 
print(data) // in data ra serial port (với bất kì kiểu dữ liệu nào được thiết lập) 
println(data) // tương tự như print(data) nhưng sau khi in con trỏ sẽ xuống dòng tiếp theo
write(byte) // gửi dữ liệu value/string/array đến serial port 
SerialEvent() // hàm được gọi khi có dữ liệu đến từ chân RX (hardware)

/* Servo.h - thư viện hỗ trợ điều khiển động cơ servo */
attach(pin, [min_uS, max_uS]) /* pin : chân kết nối với servo, 
[min_uS, max_uS] độ rộng xung tính bằng us tương ứng với góc xoay từ 0 đến 180 */
write(angle) // ghi dữ liệu góc xoay cho động cơ (0~180)
writeMicroseconds(uS) //1000-2000; 1500 is midpoint
int read() // đọc giá trị góc xoay (0 to 180)
bool attached() // trả về true nếu biến servo đã được kết nối đến pin
detach() // gỡ bỏ biến servo ra khỏi chân đã kết nối

/*Wire.h - Dùng trong giao tiếp I2C */
/* Master khởi tạo thư viện Wire với giao tiếp bus I2C */
begin() 
/* slave tham gia vào kết nối i2C, addr là 7 bits địa chỉ của slave */ 
begin(addr) 
/* Master yêu cầu 1 số byte từ slave 
 		address: 7bits địa chỉ của slave 
 		count: số lượng byte master yêu cầu
 		stop: kiểu boolean, nếu true, master tín hiệu stop sau khi yêu cầu và giải phóng bus I2C  
			nếu false, master gửi yêu cầu restart để giữ kết nối 
*/
requestFrom(address, count, stop)
beginTransmission(addr) // step1 : Gửi tín hiệu bắt đầu truyền dữ liệu đến slave có địa chỉ addr 
send(byte) // Step 2 : gửi dữ liệu (1 byte) đến slave 
send(char * string) // gửi dữ liệu (string) đến slave
send(byte * data, size) // gửi dữ liệu (1 mảng )với số byte là size 
endTransmission() // Step 3 : gửi tín hiệu kết thúc truyền dữ liệu tới slave 
int available() // trả về số byte availabe sau khi đọc được với read()
byte receive() /* truy xuất đến 1 byte đã truyền từ slave đến master, hoặc truyền theo chiều 
ngược lại khi nhận được requestFrom/ trả về byte tiếp theo đã nhận được */
onReceive(handler) // function handler sẽ được gọi khi slave nhận được dữ liệu 
onRequest(handler) // function handler sẽ được gọi khi master yêu cầu dữ liệu