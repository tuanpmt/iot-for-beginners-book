/* BASIC STRUCTURE */
Comment on one line using //
      ex: x++ ; // increase x by 1
/* */ Comment on multiple lines.
ex : /*************************
      * Comment on   *
      *    multiple lines *
      ************************/
/* PROGRAM STRUCTURE */
#include <stdio.h>//include the C standard library #include "iLib.h" //include user’s library
int global_var;   //global variable
/* Declare begin function, return type is integer. Attribute arg of type integer */
int main (int arg){
 float local_var ; // Local variable for main function
 Statement 1
 ...
 Statement n ;
return 0; //program successfully run then return
}

/*DATA TYPE AND RANGE */
boolean       true | false
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

/* VARIABLE NAMING */
/* Correct naming */
int x;            // A variable
int x = 1;        // Variable declared and initialized
float x, y, z;    // Multiple variables with the same type
const int x = 88; // Constant variable, can not override
int tenBien1ok;   // Correct naming
int ten_bien_nay_ok;
/* Incorrect naming */
int 2001_tensai;  // Incorrect, starting with number character
int ten-sai;      // '-' is not alphanumberic
int while;        // Wrong, using keyword while

/* CONSTANTS AND DATA TYPES */
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
/* Define integer constant a, with value 1 */
const int a = 1;
/* Define float constant x, with value 4.0 */
const float x = 4;
/* Define integer constant c with value 49 */
const c = ‘1’; // Character 1 in the ASCII table has value 49
/* Define str  as a pointer constant, pointed to string “Cheasheet C” */
const char * str = “Cheasheet C”;

/* VARIABLE DECLAREATION */
/* Declare integer variable a without assign value */
int a;
/* Declare binary variable a, base8 b, integer c, integer without assign value d */
int a = 0b01111011, b = 0123, c = 1, d;
/* Declare float variable fa */
float fa = 1.0f;
/* Declare double variable da */
double da = 1.0;
/* Declare pointer variable point to an undefined memory address */
char *pointer;
/* Declare pointer variable pointed to NULL (0)*/
char *other_pointer = NULL;

/* CHARACTERS */
/* String include the end of string character \0 (null) */
char str1[8] = {'A','r','d','u','i','n','o','\0'};
/* Compiler automatically add the character \0 to the end */
char str2[8] = {'A','r','d','u','i','n','o'};
/* String declaration, without the number of children and assign the value*/
char str3[] = "Arduino";
/* Declare and assign the value for string */
char str4[8] = "Arduino";
/* Common functions to process string of characters */
/* Connect source string to the end of dest string */
strcat(dest, source)
/* Find the position of first c in source, return pointer to c or null if there is no c in source */
strchr(source, c)
/* Return length of st string */
strlen(st)
/* copy and replace characters of source into dest */
strcpy(dest, source)
/* copy characters from begin to n from source to dest */
strncpy(dest, source, n)

/* ARRAY */
/* Declare an array of integer with 6 children and assign values for each */
int myPins[] = {2, 4, 8, 3, 6};
/* integer array of 6 children without values assignment */
int myInts[6];
myInts[0] = 42; // Assign the value of 42 for the first child
myInts[6] = 12; // FAILED ! array index is only from 0 to 5
/* Get the value of 3rd child in myInts array */
int c = myInts[2]; // Can use *(myInts + 2)
/* Get the address of 3rd child in myInts array */
int c = &myInts[2]; // Can use c = myInts + int
/* Return the length of myInts array */
int length = sizeof(myInts) / sizeof(myInts[0]);
/* Declare 2 float arrays, arr1 has 5 children, arr2 has 10 */
float arr1[5], arr2[10];
/* Declare integer array has 2 rows and 5 columns. Totally, 10 children */
int a[2][5];

/* CODE BLOCK AND LOOP'S COMMANDS */
{} // Include a block of code, usually used in functions
/* Goto : programs jump to the label (label must be included in goto command) */
goto label;
/* Continue : Only used in loops. Program jump to the next cycle of the most deep loop */
continue; /*
/* Break : Used to quit the most deep loop, or use with switch..case loop to quit the corresponding case */
break; /*
/* Return */
/* Used for void functions */
return;
/* Value can be a constant, a variable, a formula, or call to an other method which returns the value */
return <value>;

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
/* While: Execute if x<5 */
while (x < 5) { code };
/* Do-While : Execute code, evaluate, if x<0 continue the code */
do { code } while(x < 0);
/* for : Initialize i, execute code then increase i if i < 10 */
for (int i = 0; i < 10; i++) { code };

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

/* POINTER OPERATORS */
&reference:  // address-of
*dereference:// value-of
/* declare a pointer variable points to integer variable a */
int a = 5; int *pointer = &a;

/* CONTROLLING CHARACTERS AND SPECIAL CHARACTERS */
\n  Jump to the first column of the next line
\t  Jump to the next horizontal tab
\r  Jump to the start to current line
\a  Bip
\\  Print out the \ character
\"  Print out the " character
\'  Print out the ' character
%%: Print out the % character
\b ~ backspace (delete the right before character)

/* FUNCTIONS AND RELATED PROBLEMS */
/* Declare prototype of max function, which has 2 integer input parameters
a and b, it's return type is also integer */
int max(int a, int b);
/* Declare the variable c, which is the return value of max function */
int c = max(5,4);
/* Declare prototype of non-parameter, non-return function (void) */
void none();

/* TYPEDEF- Definition of data type */
/* Define the type of unsigned char is BYTE, declare BYTE type variables a, b */
typedef unsigned char BYTE;  BYTE  a, b;

/* LIST DATA TYPE - ENUMERATION (enum) */
/* Declare enum data type weekdays */
enum daysOfWeek { sunday, monday, tuesday, wednesday };
/* Declare the variable toDay belongs to daysOfWeek data type and assign the value */
daysOfWeek toDay = wednesday;

/* STRUCT - DATA TYPE DEFINED BY USER */
/* Define struct student */
struct student{
  char studentName;
  char studentID;
  int studentAge;
};
/* Access to the parameter studentID in student struct */
student.studentID;
/* Rename the struct student to a variable named STUDENT */
typedef struct student STUDENT;
/* Declare a variable studentA belongs to struct STUDENT */
STUDENT studentA;

/* FILE PROCESSING COMMANDS (#include <stdio.h>) */
/* Declare a pointer variable is a file path */
const char *filePath = "file/path/document.txt";
/* Declare a pointer variable of FILE type */
FILE *file;
/* Open a file at filePath and read the data */
file = fopen(filePath, "r");// Return NULL if failed
/* Close the opened file, return 0 if success, otherwise return EOF */
fclose(file);
/* Write the c character onto opening file, return OEF if failed, return ASCII code of c if success */
int fputc(int c, FILE *f);
/* Write the string "hello" onto opening file */
int c = fputs("hello", file);
/* Read (255-1) characters on opening file, the result will be saved into str array, reading process will be closed if meet the '\n' or EOL character */
fgets(str, 255, file);
/* Change the position of cursor in file, internal file position indicator jump to the starting point of file */
int fseek(file, 0, SEEK_SET);
/* Return the size of file's content */
ftell(file);
