#ifndef QInt_h
#define QInt_h
#include <string>
#include <math.h>
#include <bitset>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

typedef bitset<128> QIntBitset; //128 bit chứa các bit của số QInt
#define MAXBITS 127;
#define CONST QInt(2,"1");
#define N 128
class QInt
{
private:
	int data[4]; //Mảng dữ liệu chính
	int len = 0; //biến này để lưu trữ độ dài thực sự của chuỗi bit (không có dãy số 00000 ở đầu)
	bool sign; //biến lưu trữ dấu
public:
	//Phuong thuc khoi tao va huy
	QInt(); //Khởi tạo mặc định
	QInt(int kind, string str); //Khởi tạo theo cơ số
	QInt(QInt&); //Khởi tạo sao chép
	~QInt(); //Hủy


	//Các thao tác với dữ liệu bit trong số QInt
	string getBitString() const; //Chuyển các bit được lưu trữ trong mảng data thành chuỗi
	
	//Các thao tác xuất
	string toBinary(); //return về mảng nhị phân (thứ tự đúng) của số được lưu trong data
	string toDecimal();//tương tự như trên, chuyển về thập phân
	string toHex();//về hệ 16

	//Cac toan tu
	friend QInt operator - (QInt number1, QInt number2); //Trừ
	friend QInt operator / (QInt number1, QInt number2); //Chia
	friend QInt operator+ (QInt  firstNum, QInt  secondNum); //Cộng
	friend QInt operator* (QInt number1, QInt number2); //Nhân
	QInt operator << (int number); //Dịch trái
	QInt operator >> (int number); //Dịch phải số học
	QInt operator ~(); //Phép NOT
	QInt operator |(QInt number); //Phép OR
	QInt operator &(QInt number); //Phép AND
	QInt operator= (QInt number); //Toán tử =
	QInt operator^ (QInt number);//Phép XOR
	QInt ror(); //Phép xoay phải 1 bit
	QInt rol(); //Phép xoay trái 1 bit
	int compare(QInt num); //So sánh 2 số dạng thập phân
	//Các hàm bạn thao tác với dữ liệu trong class
};
#endif