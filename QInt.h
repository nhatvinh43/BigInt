﻿#ifndef QInt_h
#define QInt_h
#include <string>
#include <math.h>
#include <bitset>


typedef std::bitset<128> QIntBitset; //128 bit chứa các bit của số QInt
#define MAXBITS 127;
#define CONST QInt(10,"1");
class QInt
{
private:
	int data[4];
	int len = 0; //biến này để lưu trữ độ dài thực sự của chuỗi bit (không có dãy số 00000 ở đầu), dùng để chuẩn hóa chuỗi
	bool sign; //biến lưu trữ dấu
public:
	//Phuong thuc khoi tao va huy
	QInt();
	QInt(std::string Number);
	QInt(int kind, std::string str);
	QInt(QInt&);
	~QInt();


	//Các thao tác với dữ liệu bit trong số QInt
	std::string getBitString(); //Chuyển các bit được lưu trữ trong mảng data thành chuỗi, chuẩn hóa nó(xóa bỏ những số 0 dư thừa)
	

	//Các thao tác xuất
	std::string toBinary(); //return về mảng nhị phân (thứ tự đúng) của số được lưu trong data
	std::string toDecimal();//tương tự như trên, chuyển về thập phân
	std::string toHex();//về hệ 16

	//Cac toan tu
	std::string operator - (QInt number);
	std::string operator * (QInt number);
	std::string operator / (QInt number);
	QInt operator= (QInt number);
	friend std::ostream& operator << (std::ostream& os, QInt&);
	friend std::istream& operator >> (std::istream& os, QInt&);

	//Các hàm bạn thao tác với dữ liệu trong class
	friend QInt operator+ ( QInt  firstNum,  QInt  secondNum);
	friend int divideBy2(std::string&, bool&);
	friend void decimalToBinary(std::string, std::string& binaryString, bool&);
	friend std::string binaryToDecimal(std::string);
	friend std::string addQIntDecimal(std::string number1, std::string number2);
	friend std::string addQIntBinary(std::string number1, std::string number2);
	friend std::string reverseBinaryString(std::string binaryString);// Trả về 1 chuỗi nhị phân là bù 1 của số hiện hành

	friend std::string hexToBin(char c); //Hàm phụ chuyển từng 4bit sang nhị phân
	friend std::string hexToBinary(std::string number); //Hàm chuyển chuỗi số hệ 16 sang 2, trả về chuỗi nhị phân thứ tự đúng
	friend std::string binToHex(std::string number); //Chuyển hệ 2 sang hệ 16

	friend void binaryStandardize(std::string& number, int len); //Hàm chuẩn hóa chuỗi, bỏ các sô 0 dư thừa
};




#endif