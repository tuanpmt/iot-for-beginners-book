/* CẤU TRÚC CƠ BẢN */
Viết chú thích trên 1 dòng dùng //
      ex: x++ ; // tăng x 1 đơn vị
/* */ Viết chú thích trên nhiều dòng.
ex : /*************************
      * Chú thích được viết   *
      *    trên nhiều dòng    *
      ************************/
/* CẤU TRÚC 1 CHƯƠNG TRÌNH */
#include <stdio.h>//include thư viện chuẩn của C
#include "iLib.h" //include thư viện tạo bởi người dùng
int global_var;   //biến được dùng  trong chương trình
/* Khai báo hàm bắt đầu của 1 chương trình C với kiểu
trả về là integer. Đối số arg kiểu int được truyền vào
hàm */
int main (int arg){
 float local_var ; // Biến chỉ được dùng trong hàm main
 Lệnh 1
 ...
 Lệnh n ;
return 0; //chương trình thực hiện thành công và thoát
}

/*KIỂU DỮ LIỆU VÀ PHẠM VI */
boolean       true \| false
char          -128         -  127, 'a' '$' etc.
unsigned char 0            -  255
byte          0            -  255
int           -32768       -  32767
unsigned int  0            -  65535
word          0            -  65535
long          -2147483648  -  2147483647
unsigned long 0            -  4294967295
float         -3.4028e+38  -  3.4028e+38
double        -3.4028e+38  -  3.4028e+38
void          i.e., no return value

/* ĐẶT TÊN BIẾN */
/* Đặt tên đúng */
int x;            // Một biến
int x = 1;        // Biến được khai báo và khởi tạo
float x, y, z;    // Nhiều biến cùng kiểu dữ liệu
const int x = 88; // Biễn tĩnh, không ghi được
int tenBien1ok;   // Đặt tên biến này đúng
int ten_bien_nay_ok;
/* Đặt tên sai */
int 2001_tensai;  // Vì số ở đầu
int ten-sai;      // Dấu '-' không phải là alphanumberic
int while;        // Sai, vì dùng từ khóa vòng lặp while

/* HẰNG SỐ VÀ KIỂU DỮ LIỆU */
123      Số thập phân
0b0111   Số nhị phân
0173     Số Octal - base 8
0x7B     Số thập lục phân base 16
123U     Số nguyên không dấu
123L     Số nguyên có dấu 4 bytes
123UL    Số nguyên không dấu 4bytes
123.0    Số thực
1.23e6   Số thực dùng cơ số mũ ex: 1.23*10^3 = 1230
/* định nghĩa hằng số a kiểu nguyên, có giá trị là 1 */
const int a = 1;
/* Định nghĩa hằng số x kiểu thực, có giá trị là 4.0 */
const float x = 4;
/* Định nghĩa hằng số c kiểu integer có giá trị 49 */
const c = ‘1’; // Kí tự 1 trong mã ASCII là 49
/* Định nghĩa str là hằng số kiểu con trỏ, trỏ tới
chuỗi “Cheasheet C” */
const char * str = “Cheasheet C”;

/* KHAI BÁO BIẾN */
/* Khai báo biến a kiểu nguyên và không gán giá trị */
int a;
/* khai báo a kiểu binary, b kiểu base8, c kiểu số
nguyên, d kiểu số nguyên và không gán giá trị */
int a = 0b01111011, b = 0123, c = 1, d;
/* Khai báo biến fa thuộc kiểu số thực float */
float fa = 1.0f;
/* Khai báo biến da thuộc kiểu số thực double */
double da = 1.0;
/* Khai báo biến con trỏ và trỏ đến 1 vùng nhớ không
xác định */
char *pointer;
/* Khai báo biến con trỏ và trỏ về NULL (0)*/
char *other_pointer = NULL;

/* CHUỖI KÍ TỰ */
/* Chuỗi bao gồm kí tự kết thúc chuỗi \0 (null) */
char str1[8] = {'A','r','d','u','i','n','o','\0'};
/* Trình biên dịch tự động thêm kí tự \0 vào cuối
chuỗi */
char str2[8] = {'A','r','d','u','i','n','o'};
/* Khai báo chuỗi ,không khai báo số phần tử và gán giá
trị chuỗi */
char str3[] = "Arduino";
/* Khai báo và gán giá trị cho chuỗi */
char str4[8] = "Arduino";

/* Các hàm xử lí chuỗi thường dùng */
/* Nối các kí tự từ chuỗi source tiếp vào vị trí cuối
của chuỗi dest */
strcat(dest, source)
/* Tìm vị trí xuất hiện đầu tiên của kí tự c trong
source, trả về con trỏ chỉ tới vị trí đó hoặc null nếu
không tìm thấy c trong source */
strchr(source, c)
/* Hàm trả về độ dài của chuỗi st */
strlen(st)
/* copy và thay các kí tự của chuỗi soure vào dest */
strcpy(dest, source)
/* chép kí tự từ đầu đến n từ chuỗi source vào dest */
strncpy(dest, source, n)

/* MẢNG */
/* Khai báo mảng 1 chiều 6 phần tử kiểu integer và gán
giá trị cho mỗi phần tử */
int myPins[] = {2, 4, 8, 3, 6};
/* Khai báo mảng 1 chiều 6 phần tử kiểu integer và
không gán giá trị */
int myInts[6];
myInts[0] = 42; // Gán giá trị 42 cho phần tử đầu tiên
myInts[6] = 12; // LỖI ! chỉ số của mảng chỉ từ 0 đến 5
/* Lấy giá trị của phần tử thứ 3 trong mảng myInts */
int c = myInts[2]; // Có thể dùng *(myInts + 2)
/* Lấy địa chỉ của phần tử thứ 3 trong mảng myInts */
int c = &myInts[2]; // Có thể dùng int c = myInts + int
/* Trả về chiều dài của mảng myInts */
int length = sizeof(myInts) / sizeof(myInts[0]);
/* Khai báo 2 mảng kiểu float, arr1 có 5 phần tử, arr2
có 10 phần tử */
float arr1[5], arr2[10];
/* Khai báo mảng số nguyên arr có 2 dòng, 5 cột. Tổng
cộng có 10 phần tử */
int a[2][5];

/* KHỐI LỆNH VÀ CÁC LỆNH DÙNG TRONG VÒNG LẶP */
{} // bao gồm nhiều lệnh, thường được sử dụng trong hàm
/* Goto : chương trình sẽ nhảy đến nhãn (nhãn phải có
mặt trong câu lệnh chứa goto) */
goto nhãn;
/* Continue : Chỉ dùng trong các lệnh có vòng lặp sẽ
chuyển qua chu kì mới của vòng lặp trong cùng nhất */
continue; /*
/* Break : Dùng với các vòng lặp thoát khỏi vòng lặp
trong cùng nhất, hoặc dùng trong cấu trúc switch..case
để thoát ra khỏi case tương ứng */
break; /*
/* Return */
/* Dùng cho hàm không có kiểu trả về (void) */
return;
/* Value có thể là hằng số, biến, biểu thức hoặc gọi
đến 1 hàm khác để trả về giá trị */
return <value>;

/* LỆNH RẺ NHÁNH */
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

/* CÁC KIỂU VÒNG LẶP */
/* While: Thực hiện code nếu x<5 */
while (x < 5) { code };
/* Do-While : Thực hiện code, so sánh, nếu x<0 tiếp tục
thực hiện code */
do { code } while(x < 0);
/* for : Khởi tạo và gán giá trị cho i, thực hiện code
tăng i nếu i < 10 */
for (int i = 0; i < 10; i++) { code };

/* PHÉP TOÁN VÀ TOÁN TỬ THƯỜNG DÙNG
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
++   tăng 1 đơn vị
--   giảm 1 đơn vị
+=   phép toán cộng và gán giá trị
     ex: x = 5; x+= 1; //x = 6
-=   phép toán trừ và gán giá trị
     ex: x = 5; x-= 1; //x = 4
*=   phép toán nhân và gán giá trị
     ex: x = 5; x*= 3; //x = 15
/=   phép toán chia lấy phần nguyên và gán giá trị
     ex: x = 6; x/= 2; //x = 3
&=   phép toán logic AND và gán giá trị
     ex: x = 0b1010; x&= 0110; //x =0b0010
\|=   phép toán logic OR và gán giá trị
     ex: x = 0b1010; x&= 0110; //x =0b1110

/* Các toán tử trên bit */
&   and          ^   xor
<<  dịch trái    >>  dịch phảii
\|  or           ~   not

/* THỰC THI VỚI CON TRỎ */
&reference:  // lấy địa chỉ của biến mà con trỏ trỏ tới
*dereference:// lấy giá trị của biến mà con trỏ trỏ tới
/* khai báo biến con trỏ kiểu int trỏ tới địa chỉ của
biến a */
int a = 5; int *pointer = &a;

/* CÁC KÍ TỰ ĐIỀU KHIỂN VÀ KÍ TỰ ĐẶC BIỆT */
\n  Nhảy xuống dòng kế tiếp canh về cột đầu tiên
\t  Canh cột tab ngang.
\r  Nhảy về đầu hàng, không xuống hàng.
\a  Tiếng kêu bip.
\\  In ra dấu \
\"  In ra dấu "
\'  In ra dấu '
%%: In ra dấu %
\b ~ backspace (xóa 1 ký tự ngay trước)

/* HÀM VÀ CÁC VẤN ĐỀ LIÊN QUAN */
/* Khai báo prototype của hàm max, có 2 đối số đầu vào
là a và b thuộc kiểu số nguyên, kết quả trả về của hàm
kiểu số nguyên */
int max(int a, int b);
/* Khai báo biến c là giá trị trả về của hàm max */
int c = max(5,4);
/* Khai báo prototype của hàm không có đối số và không
có kiểu trả về (void) */
void none();

/* TYPEDEF- Định nghĩa kiểu dữ liệu */
/* Định nghĩa kiểu unsigned char là BYTE, khai báo các
biến a, b thuộc kiểu BYTE */
typedef unsigned char BYTE;  BYTE  a, b;

/* KIỂU LIỆT KÊ - ENUMERATION (enum) */
/* khai báo kiểu dữ liệu enum là các ngày trong tuần */
enum daysOfWeek { sunday, monday, tuesday, wednesday };
/* Tạo biến toDay thuộc daysOfWeek và gán giá trị */
daysOfWeek toDay = wednesday;

/* STRUCT - KIỂU DỮ LIỆU DO NGƯỜI DÙNG ĐỊNH NGHĨA */
/* Khai báo struct sinhVien */
struct sinhVien{
  char tenSinhVien;
  char MSSinhVien;
  int tuoiSinhVien;
};
/* Truy xuất đến thành phần MSSinhVien trong struct
sinhVien */
sinhVien.MSSinhVien;
/* Đổi tên struct sinhVien thành 1 biến duy nhất là
SINHVIEN */
typedef struct sinhVien SINHVIEN;
/* Khai báo biến sinhVienA thuộc struct SINHVIEN */
SINHVIEN sinhVienA;

/* CÁC LỆNH XỬ LÝ TẬP TIN (#include <stdio.h>) */
/* Khai báo 1 biến con trỏ là đường dẫn của 1 file */
const char *filePath = "Đường/dẫn/file/document.txt";
/* Tạo 1 biến con trỏ thuộc kiểu FILE */
FILE *file;
/* Mở 1 file ở đường dẫn filePath và đọc dữ liệu */
file = fopen(filePath, "r");// Trả về NULL nếu thất bại
/* Đóng 1 file đã mở, trả về 0 nếu thành công , ngược
lại trả về EOF */
fclose(file);
/* Viết kí tự c lên file đang mở, trả về EOF nếu ghi
thất bại, trả về mã ASCII của c nếu thành công */
int fputc(int c, FILE *f);
/* Viết chuỗi "hello" lên file đang mở */
int c = fputs("hello", file);
/* Đọc (255-1) kí tự từ file đang mở, kết quả đọc được
sẽ lưu vào mảng str, việc đọc bị dừng nếu gặp kí tự
'\n' hoặc EOL */
fgets(str, 255, file);
/* Thay đổi vị trí trỏ đến trong file của con trỏ
internal file position indicator về lại đầu file */
int fseek(file, 0, SEEK_SET);
/* Trả về kích thước của nội dung có trong file */
ftell(file);
