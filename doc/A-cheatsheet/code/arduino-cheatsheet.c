/* Cấu trúc cơ bản của 1 Sketch */
void setup() {
  /*
  Hàm được gọi khi bắt đầu sketch. Dùng để khởi tạo
  biến, cấu hình chân, khởi tạo thư viện...
  Code trong setup chỉ chạy 1 lần (khi khởi động hoặc
  reset board)
  */
}
void loop() {
  /* Nội dung trong loop() lặp lại liên tục*/
}

/* Lệnh rẻ nhánh */
if (x < 5)      // thực thi code nếu x<5
 { code }
else if (x > 10)// thực thi code nếu x>10
	{ code }
else { code }   // thực thi code các trường hợp còn lại

switch (var) {  // thực thi case có giá trị var
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

/* thực hiện code, so sánh, nếu x<0 tiếp tục thực hiện
code */
do { code } while(x < 0);

/* khởi tạo i, thực hiện code và tăng i nếu i <10 */
for (int i = 0; i < 10; i++) { code };

break;    /* Thoát ra vòng lặp (for, while, do...while)
ngay lập tức */
continue; /* Đi đến chu kì lặp tiếp theo của vòng lặp
hiện tại. */

/* Các định nghĩa về hàm */
<ret. type> <name>(<params>) { ... }
int func_name(int x) { return x*2; }
return x; // x phải trùng khớp với kiểủ trả về của hàm
return;   // loại return dành cho hàm void

/* Include */
#include <stdio.h>        //include thư viện chuẩn
#include "your-library.h" /*include thư viện tạo bởi
người dùng*/

/* Strings */
/* Chuỗi bao gồm kí tự kết thúc chuỗi \0 (null) */
char str1[8] = {'A','r','d','u','i','n','o','\0'};

/* Trình biên dịch tự động thêm kí tự \0 vào cuối chuỗi */
char str2[8] = {'A','r','d','u','i','n','o'};
/* Khai báo mảng, không khai báo số phần tử và gán giá
trị cho mảng */
char str3[] = "Arduino";
/* Khai báo và gán giá trị cho mảng char 8 phần tử */
char str4[8] = "Arduino";

/*Arrays*/
/* Khai báo mảng kiểu int có 6 phần tử và gán giá trị cho
mỗi phần tử */
int myPins[] = {2, 4, 8, 3, 6};
// Mảng kiểu int 6 phần tử và không gán giá trị
int myInts[6];
myInts[0] = 42; // Gán giá trị 42 cho phần tử đầu tiên
myInts[6] = 12; // LỖI ! chỉ số của mảng chỉ từ 0 đến 5

/*Qualifiers*/
static    // Không thay đổi giá trị ở các lần gọi
volatile  // In RAM (Thường dùng trong ngắt)
const     // Không đổi (chỉ đọc)
PROGMEM   /* Cho phép lưu trữ dữ liệu trong bộ nhớ FLASH
thay vì SRAM */

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
\|\|  phép toán logic (OR)
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
&   and          ^   xor
<<  dịch trá     >>  dịch phảii
\|  or           ~   not

/* Thực thi với con trỏ */
& reference:   // lấy địa chỉ của biến mà con trỏ trỏ tới
* dereference: // lấy giá trị của biến mà con trỏ trỏ tới

/*Hằng số và kiểu dữ liêu*/
123     // Số thập phân
0b0111  // Số nhị phân
0173    // Octal - base 8
0x7B    // Số thập lục phân base 16
123U    // Số nguyên không dấu
123L    // Số nguyên có dấu 4 bytes
123UL   // Số nguyên không dấu 4bytes
123.0   // Số thực
1.23e6  // Số thực dùng cơ số mũ ex: 1.23*10^6 = 1230000

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

<<<<<<< HEAD
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
// Thiết lập cấu hình chân
pinMode(pin,[INPUT, OUTPUT, INPUT_PULLUP])
// Đọc giá trị của pin_6 và gán cho a
int a = digitalRead(pin_6);
// Cài đặt mức HIGH/LOW cho pin_5
digitalWrite(pin_5, [HIGH, LOW])
// Đọc giá trị của pin và gán cho a, pin từ A0-->A5
int a = analogRead(pin)

/* PWM ngõ ra - pins 3 5 6 9 10 11
 * ESP8266: pin 0..16, range = 0..1023, 1KHz default
 */
// Đặt giá trị PWM cho pin
analogWrite(pin, value)
// ESP8266: thay đổi RANGE PWM output
analogWriteRange(new_range)
// ESP8266: Tần số PWM output
analogWriteFreq(new_frequency)

/* Advanced I/O */
// Tạo sóng vuông tần số freq_Hz với duty cycle=50%
tone(pin, freq_Hz)
// Tạo sóng vuông tần số freq_Hz, duration mili giây
tone(pin, freq_Hz, duration_ms)
// Ngừng việc tạo sóng vuông khi dùng tone()
noTone(pin)
// Dịch 1 byte, mỗi lần dịch 1 bit, bắt đầu từ bit cao
shiftOut(dataPin, clockPin,[MSBFIRST, LSBFIRST], value)
// Trả về (ms) của xung HIGH/LOW trên chân pin
unsigned long pulseIn(pin,[HIGH, LOW])

/* External Interrupts */

// Thiết lập chức năng ngắt ở các chân digital
attachInterrupt(interrupt, func, mode)
/*
interrupt: số ngắt (thường là chân sử dụng chức năng
ngắt)
func : hàm sẽ được gọi khi ngắt xảy ra (lưu ý : hàm
không có tham số đầu vào cũng như kiểu trả về)
mode : gồm các chế độ LOW,CHANGE, RISING, FALLING. Ngắt
sẽ được kích hoạt khi chân ngắt ở mode tương ứng
*/
// Vô hiệu hóa ngắt interrupt
detachInterrupt(interrupt)
// Vô hiệu hóa tấ cả các ngắt
noInterrupts()
// Cho phép tái ngắt sau khi dùng noInterrupts()
interrupts()

/*************************************************
 *            THƯ VIỆN PHỔ BIẾN                 *
 *************************************************/

/*************************************************
 *                     Serial                    *
 *Thư viện giao tiếp với PC hoặc thông qua RX/TX*
 *************************************************/
// Thiết lập giao tiếp serial - UART với tốc độ speed
begin(long speed)
// Vô hiệu hóa giao tiếp serial
end()
// Trả về số bytes có sẵn để đọc
int available()
/* đọc dữ liệu đến từ serial (trả về byte đầu tiên của
dữ liệu từ serial hoặc -1 nếu dữ liệu không có */
int read()
// Chờ quá trình truyền dữ liệu serial hoàn tất
flush()
/* In ra serial port dữ liệu data (với bất kì kiểu dữ
liệu nào được thiết lập */
print(data)
/* Tương tự như print(data) nhưng sau khi in ra serial-
port, con trỏ sẽ xuống dòng tiếp theo */
println(data)
// Gửi dữ liệu value/string/array đến serial port
write(byte)
// Hàm được gọi khi có dữ liệu đến từ chân RX (hardware)
SerialEvent()

/*************************************************
 *                  Servo.h                      *
 * Thư viện hỗ trợ điều khiển động cơ servo     *
**************************************************/
/*
 Thiết lập chân kết nối với servo và độ rộng xung
 pin : Chân kết nối với
 servo, [min_uS, max_uS] : Độ rộng xung tính theo us tương
 ứng với góc xoay từ 0 đến 180
*/
attach(pin, [min_uS, max_uS])
// Ghi dữ liệu góc xoay cho động cơ angle từ 0~180
write(angle)
/* Viết giá trị để điều khiển góc quay cho servo, giá trị
từ 700 ~2300 */
writeMicroseconds(uS)
// Đọc giá trị góc xoay (0 đến 180 độ)
int read()
// Trả về true nếu biến servo đã được kết nối đến pin
bool attached()
// Gỡ bỏ biến servo ra khỏi chân đã kết nối
detach()

/*************************************************
 *                       Wire.h                  *
 *               Dùng trong giao tiếp I2C        *
 *************************************************/
 // Master khởi tạo thư viện Wire với giao tiếp bus I2C
begin()
/* Slave tham gia vào kết nối i2C, addr là 7 bits địa chỉ
của slave */
begin(addr)
/*
Master yêu cầu 1 số byte từ slave
address: 7bits địa chỉ của slave.
count: Số lượng byte master yêu cầu
stop: Kiểu boolean, nếu true, master tín hiệu stop sau
khi yêu cầu và giải phóng bus I2C, nếu false, master gửi
yêu cầu restart để giữ kết nối
*/
requestFrom(address, count, stop)
/* Gửi tín hiệu bắt đầu truyền dữ liệu đến slave có địa
chỉ addr */
beginTransmission(addr)
// Gửi dữ liệu (1 byte)đến slave
send(byte)
// Gửi dữ liệu (string) đến slave
send(char * string)
// Gửi dữ liệu (1 mảng )với số byte là size
send(byte * data, size)
// Gửi tín hiệu kết thúc việc truyền dữ liệu tới slave
endTransmission()
// Trả về số byte availabe sau khi đọc được với read()
int available()
/* truy xuất đến 1 byte đã truyền từ slave đến master
hoặc truyền ở chiều ngược lại khi nhận được requestFrom
. Trả về byte tiếp theo đã nhận được */
byte receive()
// Hàm handler sẽ được gọi khi slave nhận được dữ liệu
onReceive(handler)
// Hàm handler sẽ được gọi khi master yêu cầu dữ liệu
onRequest(handler)

/*************************************************
 *                    ESP8266                   *
 *************************************************/

/* Dùng khi chương trình cần thực thi nhiều tác vụ cùng
một lúc, thư viện hỗ trợ <Scheduler.h> */
void yield();
// Reset chip ESP
void ESP.reset();
// Trả về kích thước vùng nhớ trống ở heap
uint32_t ESP.getFreeHeap();
// Trả về ID của chip ESP
uint32_t ESP.getChipId();

/* Chế độ cấu hình Wifi Station */

// Thiết lập chế độ station
WiFi.mode(WIFI_STA);
// Kết nối đến AP
WiFi.begin(ssid, password);
// Ngắt kết nối đến network wifi hiện tại
bool WiFi.disconnect();
// Trả về địa chỉ IP của station
WiFi.localIP();
// Trả về trạng thái khi kết nối đến AP
WiFi.status();
// Trả về tên của netwwork WiFi đã kết nối
WiFi.SSID();
// Trả về cường độ của WiFi (đơn vị dBm)
WiFi.RSSI();
// Bắt đầu thiết lập chế độ WPS
WiFi.beginWPSConfig();
// Bắt đầu thiết lập chế độ smart config
WiFi.beginSmartConfig();

/* Chế độ cấu hình Wifi Soft Acess Point (AP) */

// Khởi tạo 1 AP với tên và password
WiFi.softAP(ssid, password);
/* Khởi tạo 1 AP và thiết lập cấu hình cho AP gồm địa chỉ
IP, gateway và subnet */
WiFi.softAPConfig (local_ip, gateway, subnet);
// Trả về số station đã kết nối đến AP
WiFi.softAPgetStationNum();
// Ngắt kết nối của các station
WiFi.softAPdisconnect(wifioff);
// Trả về địa chỉ IP của AP
WiFi.softAPIP();
// Trả về địa chỉ MAC của AP
WiFi.softAPmacAddress(mac);

/* WiFi features */

/* Scan */
// Thiết lập chế độ Station
WiFi.mode(WIFI_STA);
// Scan và trả về số lượng network ở trạng thái avalable
WiFi.scanNetworks();
// Trả về tên của network (kiểu string) ở vị trí num
WiFi.SSID(num).c_str();
// Trả về thông tin của tất cả các network
WiFi.getNetworkInfo(networkItem,&ssid,
&encryptionType, &RSSI,*&BSSID, &channel, &isHidden)


/* Diagnostics */
/*
* Mục đích : chuẩn đoán, cung cấp thông tin và khắc
* phục sự cố khi không kết nối đến net work WiFi
*/
// In ra serial các chuẩn đoán thông tin của network
WiFi.printDiag(Serial);
// Enable chế độ debug
Serial.setDebugOutput(true);

/* WebServer */

/* máy chủ TCP tại port 80 sẽ phản hồi các HTTP request
được gửi lên từ client */
ESP8266WebServer server (80);
// Server bắt đầu lắng nghe các client
server.begin();
// Viết dữ liệu đến các client
server.write(buf, len)
/* Khởi tạo server ở địa chỉ URL, handleRoot là nội dung
hoặc hàm sẽ thực hiện */
server.on ( "URL", handleRoot );
// Server sẽ tương tác với client để gửi và nhận dữ liệu
server.handleClient();
// Trả về 1 nếu biến val có tồn tại trên server
server.hasArg(val)
// Lấy giá trị của biến val trên server
server.arg(val);
/* Gửi yêu cầu cập nhật dữ liệu từ server:
code : HTTP code
text/html : Định dạng trả về là file HTML
content: Nội dung sẽ trả về từ phía server */
server.send (code, "text/html",content);

/* MQTT */
/*
Các thư viện hỗ trợ giao thức MQTT dành cho ESP8266
trên arduino thường sử dụng là ESP8266MQTTClient
và PubSubClient. Phần này giải thích các hàm của thư viện
*/

/* Các hàm của thư viện ESP8266MQTTClient*/

// Khai báo 1 biến mqtt thuộc class MQTTClient
MQTTClient mqtt;
// Lấy dữ liệu nhận được từ topic đã subcribe
mqtt.onData([](String topic, String data, bool cont)
// Hủy subcribe topic /qos0
mqtt.unSubscribe("/qos0");
 // Thực hiện subscribe topic và publish các message
mqtt.onSubscribe([](int sub_id)
/* Publish 1 message "qos0" đến topic /qos0 với QoS =0,
và Retain = 0 */
mqtt.publish("/qos0", "qos0", 0, 0);
// Kết nối đến server MQTT
mqtt.onConnect([]()
// Subscribe topic và nhận message tại topic /qos0
mqtt.subscribe("/qos0", 0)
/* Bắt đầu truyền nhận dữ liệu với broker MQTT có url
mqtt://test.mosquitto.org tại port 1883 */
mqtt.begin("mqtt://test.mosquitto.org:1883")
/* Hàm được gọi trong loop() nhằm khởi tạo MQTT, kiểm tra
xử lí các dữ liệu từ các topic, kiểm tra các thuộc tính
của giao thức như gói keep-a-live, gói tin QoS... */
mqtt.handle();

/* Các hàm của thư viện PubSubClient*/

PubSubClient client(espClient);
 // publish gói tin "Connected!" đến topic ESP8266/connection/board
client.publish("ESP8266/connection/board", "Connected!");
 // đăng kí nhận gói tin tại topic ESP8266/LED_GPIO16/status
client.subscribe("ESP8266/LED_GPIO16/status");
// cài đặt server là broker.mqtt-dashboard.com và lắng nghe client ở port 1883
client.setServer(mqtt_server, 1883);
// gọi hàm callback để thực hiện các chức năng publish/subcribe
client.setCallback(callback);
 client.loop();
