Thông số phần cứng
	- Giao tiếp ngoại vi :
	   * UART/HSPI/Ir Remote Contorl
	   * GPIO/PWM/I2C/I2S/
	- Điện áp hoạt động : 3.0~3.6V
	- Dòng điện hoạt động : ~ 80mA
	- Nhiệt độ hoạt động : -40°~125°

Thông số về WiFi 
	- Certificates : FCC/CE/ROSH
	- WiFi Protocles : 802.11 b/g/n
	- Frequency Range : 2.4GHz~2.5GHz
     
Thiết lập các chế độ khởi động
  - Serial programming:
      GPIO_15 = LOW, GPIO_0 = LOW, GPIO_2 = HIGH

  - Boot from flash :
      GPIO_15 = LOW, GPIO_0 = HIGH, GPIO_2 = HIGH

  - Boot from SD Card
      GPIO_15 = HIGH, GPIO_0 = ANY, GPIO_2 = ANY

Thông số phần mềm

  - Các chế độ Wifi:
      * Station
      * SoftAP
      * SoftAP + station

  - Bảo mật : WPA/WPA2

  - Cập nhật firmware :
      - UART Download
      - OTA(via network)
      - Download and write firmware via host

  - Các giao thức kết nối :
        IPv4, TCP/UDP/HTTP/FTP 

  User configuration:
      - AT Instruction Set
      - Cloud Server
      - Android/iOS App

=== Esp8266 with Arduino

/* I/O */
int analogRead(uint8_t pin); // Kết nối với chỉ chân A0
void analogWrite(uint8_t pin, int value);
/*
pin : GPIO_0 đến GPIO_16
value : Giá trị từ 0 đến 1023
*/

/* Utils */ 
void yield(); /* dùng khi chương trình cần thực thi nhiều
tác vụ cùng một lúc, thư viện hỗ trợ <Scheduler.h> */ 
void ESP.reset();// reset chip ESP
uint32_t ESP.getFreeHeap(); /* trả về kích thước vùng 
nhớ trống ở heap */
uint32_t ESP.getChipId(); // lấy ID của chip ESP

/* Các chế độ cấu hình Wifi */

 /* Station */
  WiFi.mode(WIFI_STA);// thiết lập chế độ station
  WiFi.begin(ssid, password); // kết nối đến AP 

  bool WiFi.disconnect(); /* ngắt kết nối wifi đến 
  network hiện tại */ 
  WiFi.localIP(); // địa chỉ IP của station 
  WiFi.status();  /* trả về trạng thái khi kết nối đến 
  AP*/ 
  WiFi.SSID(); /* trả về tên của netwwork WiFi đã kết 
  nối */
  WiFi.RSSI();// trả về cường độ của WiFi (đơn vị dBm)
  WiFi.beginWPSConfig();// bắt đầu thiết lập chế độ WPS
  beginSmartConfig();   /* bắt đầu thiết lập chế độ 
  smart config */
   
  /* Soft AP */
  WiFi.softAP(ssid, password);/* khởi tạo 1 network 
  AP */ 
  softAPConfig (local_ip, gateway, subnet); /* thiết lập
  cấu hình cho AP gồm địa chỉ IP, gateway và subnet */  
  WiFi.softAPgetStationNum(); /* trả về số station đã 
  kết nối đến */
  WiFi.softAPdisconnect(wifioff); /* ngắt kết nối của 
  các station */
  WiFi.softAPIP(); // trả về địa chỉ IP của AP
  WiFi.softAPmacAddress(mac); /* trả về địa chỉ MAC của 
  AP */

/* WiFi features */

  /* Scan */ 
  WiFi.mode(WIFI_STA); // thiết lập chế độ Station
  WiFi.scanNetworks(); /* scan và trả về số lượng các
  network ở trạng thái avalable */
  WiFi.SSID(num).c_str(); /* trả về tên của network
  (kiểu string) ở vị trí num */   
  WiFi.getNetworkInfo(networkItem,&ssid, 
  &encryptionType, &RSSI,*&BSSID, &channel, &isHidden)
  /* trả về thông tin của tất cả các network */

  /* Diagnostics */
  /*
  * Mục đích : chuẩn đoán, cung cấp thông tin và khắc
  * phục sự cố khi kết nối WiFi
  */ 
  WiFi.printDiag(Serial); /* in ra serial các chuẩn đoán
  thông tin của network */ 
  Serial.setDebugOutput(true) /* enable chế độ Wi-Fi 
  Diagnostic */

  /* WebServer */
  ESP8266WebServer server (80); /* máy chủ TCP tại 
  port 80 sẽ phản hồi các HTTP request được gửi lên từ 
  client */
  server.begin(); // server bắt đầu lắng nghe các client 
  server.write(buf, len) // Viết dữ liệu đến các client
  server.on ( "URL", handleRoot ) /* khởi tạo server ở 
  địa chỉ URL, handleRoot là nội dung hoặc hàm sẽ thực
  hiện */  
  server.handleClient(); /* server sẽ tương tác với 
  client để gửi và nhận dữ liệu */
  server.hasArg(val) /* kiểm tra biến val có tồn tại 
  trên server, trả về 1 hoặc 0 */ 
  server.arg(val); /* lấy giá trị của biến val trên 
  server */
  server.send (code, "text/html",content); /* gửi yêu 
  cầu cập nhật dữ liệu từ server:
  code : HTTP code
  text/html : định dạng trả về là file HTML
  content: nội dung sẽ trả về từ phía server */

  /* MQTT */
  /* 
  Các thư viện hỗ trợ giao thức MQTT dành cho ESP8266 
  trên arduino thường sử dụng là ESP8266MQTTClient
  và PubSubClient 
  */
  #include <ESP8266MQTTClient.h> //import thư viện 
  #include <ESP8266WiFi.h>
  MQTTClient mqtt; /* khai báo biến mqtt thuộc 
  lớp MQTTCLient */
  mqtt.onData([](String topic, String data, bool cont)
  //lấy dữ liệu nhận được từ topic đã subcribe
  mqtt.unSubscribe("/qos0");// hủy subcribe topic /qos0
  mqtt.onSubscribe([](int sub_id)
  mqtt.publish("/qos0", "qos0", 0, 0); /* publish dữ 
  liệu "qos0" lến topic /qos0 với QoS =0, Retain = 0 */ 
  mqtt.onConnect([]() /* */
  mqtt.subscribe("/qos0", 0)/* đăng kí nhận gói tin tại 
  topic /qos0 */ 
  mqtt.begin("mqtt://test.mosquitto.org:1883") /* bắt
  đầu truyền nhận dữ liệu với broker MQTT có url
  mqtt://test.mosquitto.org:1883 */
  mqtt.handle();