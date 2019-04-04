#ifndef OutterFunctions_h
#define OutterFunctions_h
#include "QInt.h"
string Subtraction(string a, string b); //Trừ 2 số thập phân

string multiply(string num1, string num2);// Nhân 2 số dạng thập phân, phục vụ cho việc chuyển từ nhị phân sang thập phân

string pow(string num, int exp); //Hàm tính số mũ

string addBin(string number1, string number2); //cộng 2 số nhị phân, hàm phụ cho toán tử + kiểu QInt

string addDec(string number1, string number2);//cộng 2 số thập phân

int divideBy2(string&, bool&);//Hàm chia số thập phân cho 2 (chia 1 lần)

void decimalToBinary(string, string& binaryString, bool&);//Hàm chuyển thập phân về nhị phân (chia 2 nhiều lần)

string binaryToDecimal(string); //Chuyển từ nhị phân sang thập phân

string binaryToSecondComplement(string);//Chuyển sang dạng bù 2 của chuỗi nhị phân

string reverseBinaryString(string binaryString);// Trả về 1 chuỗi nhị phân là bù 1 của số hiện hành

string hexToBin(char c); //Hàm phụ chuyển từng 4bit sang nhị phân

string hexToBinary(string number); //Hàm chuyển chuỗi số hệ 16 sang 2, trả về chuỗi nhị phân thứ tự đúng

string binToHex(string number); //Chuyển hệ 2 sang hệ 16

string binaryStandardize(string number); //Hàm chuẩn hóa chuỗi, bỏ các sô 0 dư thừa

bool isSmaller(string num1, string num2);// Kiểm tra số thứ 1 có nhỏ hơn số thứ 2 không

string diff(string num1, string num2); // Khoảng cách giữa 2 số (chỉ dùng hàm này để chuyển số âm dạng bù 2 sang thập phân)

string shiftLeft(string num);//Dịch trái 1 lần

string shiftRight(string num);//Dịch phải 1 lần (số học)

int sign(string n1, string n2); //Xác định dấu của kết quả trong phép nhân

string Multiplication(string n1, string n2); //Nhân 2 số thập phân

int makeEqualLength(string &str1, string &str2); //hàm làm chiều dài 2 dãy bằng nhau
#endif