#ifndef QInt_h
#define QInt_h
#include <string>
#include <math.h>
#include <bitset>
#include <vector>
using namespace std;

typedef bitset<128> QIntBitset; //128 bit chứa các bit của số QInt
#define MAXBITS 127;
#define CONST QInt(2,"1");
class QInt
{
private:
	int data[4];
	int len = 0; //biến này để lưu trữ độ dài thực sự của chuỗi bit (không có dãy số 00000 ở đầu), dùng để chuẩn hóa chuỗi
	bool sign; //biến lưu trữ dấu
public:
	//Phuong thuc khoi tao va huy
	QInt();
	QInt(string Number);
	QInt(int kind, string str);
	QInt(QInt&);
	~QInt();


	//Các thao tác với dữ liệu bit trong số QInt
	string getBitString() const; //Chuyển các bit được lưu trữ trong mảng data thành chuỗi, chuẩn hóa nó(xóa bỏ những số 0 dư thừa)
	

	//Các thao tác xuất
	string toBinary(); //return về mảng nhị phân (thứ tự đúng) của số được lưu trong data
	string toDecimal();//tương tự như trên, chuyển về thập phân
	string toHex();//về hệ 16

	//Cac toan tu
	friend QInt operator - (QInt number1, QInt number2);
	friend QInt operator / (QInt number1, QInt number2);
	friend QInt operator+ (QInt  firstNum, QInt  secondNum);
	friend QInt operator* (QInt number1, QInt number2);
	QInt operator << (int number);
	QInt operator >> (int number);
	QInt operator ~();
	QInt operator |(QInt number);
	QInt operator &(QInt number);
	QInt operator= (QInt number);
	QInt operator^ (QInt number);
	QInt ror(); //Phép xoay phải 1 bit
	QInt rol(); //Phép xoay trái 1 bit
	int compare(QInt num); //So sánh 2 số dạng thập phân
	//Các hàm bạn thao tác với dữ liệu trong class
	
};
string Subtraction(string a, string b);
string multiply(string num1, string num2);// Nhân 2 số dạng thập phân, phục vụ cho việc chuyển từ nhị phân sang thập phân
string pow(string num, int exp); //Hàm tính số mũ
string addBin( string number1,  string number2); //cộng 2 số nhị phân, hàm phụ cho toán tử + kiểu QInt
string addDec(string number1, string number2);//cộng 2 số thập phân
int divideBy2(string&, bool&);//Hàm chia số thập phân cho 2 (chia 1 lần)
void decimalToBinary(string, string& binaryString, bool&);//Hàm chuyển thập phân về nhị phân (chia 2 nhiều lần)
string binaryToDecimal(string); //Chuyển từ nhị phân sang thập phân
string binaryToSecondComplement(string);//Chuyển sang dạng bù 2 của chuỗi nhị phân
string reverseBinaryString(string binaryString);// Trả về 1 chuỗi nhị phân là bù 1 của số hiện hành
string hexToBin(char c); //Hàm phụ chuyển từng 4bit sang nhị phân
string hexToBinary(string number); //Hàm chuyển chuỗi số hệ 16 sang 2, trả về chuỗi nhị phân thứ tự đúng
string binToHex(string number); //Chuyển hệ 2 sang hệ 16
void binaryStandardize(string& number, int len); //Hàm chuẩn hóa chuỗi, bỏ các sô 0 dư thừa
bool isSmaller(string num1, string num2);// Kiểm tra số thứ 1 có nhỏ hơn số thứ 2 không
string diff(string num1, string num2); // Khoảng cách giữa 2 số (chỉ dùng hàm này để chuyển số âm dạng bù 2 sang thập phân)
string shiftLeft(string num);//Dịch trái 1 lần
string shiftRight(string num);//Dịch phải 1 lần (số học)


int makeEqualLength(string &str1, string &str2); //hàm làm chiều dài 2 dãy bằng nhau

#endif
