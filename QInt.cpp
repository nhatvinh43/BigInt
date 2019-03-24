#include "QInt.h"
#include <iostream>

using namespace std;
QInt::QInt()
{
	this->len = 0;
	this->sign = 0;
}
QInt::QInt(QInt& number)
{
	this->len = number.len;
	this->sign = number.sign;
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = number.data[i];
	}
}
QInt::~QInt()
{
	this->sign = this->len = 0;
}
QInt QInt:: operator= (QInt number)
{
	QInt temp;
	temp.len = number.len;
	temp.sign = number.sign;
	for (int i = 0; i < 4; i++)
	{
		temp.data[i] = number.data[i];
	}
	return temp;
}
string reverseBinaryString(string binaryString)
{
	string result;
	int len = binaryString.length();
	for (int i = 0; i < len; i++)
	{
		if (binaryString[i] == '0')
		{
			result.push_back('1');
		}
		else
		{
			result.push_back('0');
		}
	}
	return result;
}

int divideBy2(string& a, bool& sign)
{
	int arr[4] = { 0 };
	int len = a.length();
	int i = 0;
	string newString;
	if (a[0] == '-')
	{
		i = 1;
		sign = 1;
		newString += '-';
	}
	if ((a == "-1"))
	{
		newString = '0';
		a = newString;
		return 1;
	}
	if ((a == "1"))
	{
		newString = '0';
		a = newString;
		return 1;
	}
	if ((a == "0"))
	{
		newString = '0';
		a = newString;
		return 0;
	}

	int tempString = (a[i] - 48);
	if (tempString < 2)
	{
		tempString = tempString * 10 + (a[i + 1] - 48);
		i++;
	}
	int bitCount = 0;
	for (i;; i++)
	{
		bitCount++;
		int soDu = tempString % 2;
		newString = newString + (char)((tempString / 2) + 48);
		tempString = tempString - (tempString / 2) * 2;
		if (i < len - 1)

		{
			tempString = tempString * 10 + (a[i + 1] - 48);
		}
		if (i == len - 1)
		{
			a = newString;
			return soDu;
		}
	}
}
void decimalToBinary(string a, string& binaryString, bool& sign)
{

	binaryString += (char)(divideBy2(a, sign) + 48);
	if (a == "0")
	{
		reverse(binaryString.begin(), binaryString.end());
		if (sign == 1)
		{
			//Chuyển sang bù 2
		}
		return;
	}
	decimalToBinary(a, binaryString, sign);
}


string hexToBin(char c)
{
	switch (c)
	{
	case '0':
		return "0000";
		break;
	case '1':
		return "0001";
		break;
	case '2':
		return "0010";
		break;
	case '3':
		return "0011";
		break;
	case '4':
		return "0100";
		break;
	case '5':
		return "0101";
		break;
	case '6':
		return "0110";
		break;
	case '7':
		return "0111";
		break;
	case '8':
		return "1000";
		break;
	case '9':
		return "1001";
		break;
	case 'A':
	case 'a':
		return "1010";
		break;
	case 'B':
	case 'b':
		return "1011";
		break;
	case 'C':
	case 'c':
		return "1100";
		break;
	case 'D':
	case 'd':
		return "1101";
		break;
	case 'E':
	case 'e':
		return "1110";
		break;
	case 'F':
	case 'f':
		return "1111";
		break;
	default:
		break;
	}

}

string hexToBinary(string hex){
	string result = "";
	for (int i = 0; i < hex.length(); i++)
	{
		result += hexToBin(hex[i]);
	}
	return result;
}

QInt::QInt(int kind, string str) //Hàm khởi tạo kiểu QInt với các hệ cơ số
{
	string binaryString;
	if (kind == 2)  //Nếu chuỗi là chuỗi nhị phân
	{
		binaryString = str;
		int n = str.length();
		this->len = n;
		if (str[0] == '1')
		{
			this->sign = 1;
		}
		else this->sign = 0;
	}
	if (kind == 10)  //Nếu chuỗi là chuỗi thập phân
	{
		bool negative = (str[0] == '-') ? true : false;

		// n?u âm
		if (negative)
		{
			this->sign = 1;
			str = str.substr(1);	// b? d?u tr?
		}
		else
		{
			this->sign = 0;
		}
		decimalToBinary(str, binaryString, this->sign);  //Chuyển về chuỗi nhị phân thứ tự đúng
		this->len = binaryString.length();
		if (negative) //Nếu là số âm thì cần chuyển tiếp binaryString về dạng bù 2
		{
			binaryString = reverseBinaryString(binaryString);				// bù 1
			*this = *this + CONST;	// bù 2
		}
	}
	if (kind == 16) //Nếu chuỗi là chuỗi hệ 16
	{
		binaryString = hexToBinary(str);
		this->sign = 0;
		this->len = binaryString.length();
	}

	for (int i = 0; i < 4; i++)
	{
		this->data[i] = (this->data[i] & 0);
	}
	int k = this->len - 1;

	for (int i = 0; i < this->len; i++)
	{
		int bitPosition;
		if (i + 1 <= 32)
		{
			bitPosition = 3;
		}
		else if (i + 1>32 && i + 1 <= 64)
		{
			bitPosition = 2;
		}
		else if (i + 1>64 && i + 1 <= 96)
		{
			bitPosition = 1;
		}
		else if (i + 1>96 && i + 1 <= 128)
		{
			bitPosition = 0;
		}
		this->data[bitPosition] = this->data[bitPosition] | ((int)(binaryString[k] - 48) << i);

		k--;
	}

}

QInt operator+( QInt  firstNum,  QInt  secondNum)
{
	
	string tempString1 = firstNum.getBitString(), tempString2 = secondNum.getBitString();
	string result;
	int n1 = tempString1.length(), n2 = tempString2.length();
	int startPos = (n1 >= n2 ? n1 : n2);
	if (n1 > n2)
	{
		string temp;
		for (int i = 0; i < (n1 - n2); i++)
		{
			temp += '0';
		}
		temp += tempString2;
		tempString2 = temp;
	}
	else if (n1 < n2)
	{
		string temp;
		for (int i = 0; i < (n2 - n1); i++)
		{
			temp += '0';
		}
		temp += tempString1;
		tempString1 = temp;
	}
	int carry = 0; // kh?i t?o
	for (int i = startPos-1; i >= 0; i--)
	{
		int firstBit = tempString1.at(i) - '0';
		int secondBit = tempString2.at(i) - '0';

		int sum = (firstBit ^ secondBit ^ carry) + '0';
		result = char(sum) + result;


		carry = (firstBit & secondBit) | (secondBit & carry) | (firstBit & carry);
	}
	return QInt(2, result);
}

string binToHex(string bin){
	string result;
	string tmp, chr = "0000";
	int len = bin.length() / 4;
	chr = chr.substr(0, len);
	bin = chr + bin;
	for (int i = 0; i<bin.length(); i += 4)
	{
		tmp = bin.substr(i, 4);
		if (!tmp.compare("0000"))
		{
			result = result + "0";
		}
		else if (!tmp.compare("0001"))
		{
			result = result + "1";
		}
		else if (!tmp.compare("0010"))
		{
			result = result + "2";
		}
		else if (!tmp.compare("0011"))
		{
			result = result + "3";
		}
		else if (!tmp.compare("0100"))
		{
			result = result + "4";
		}
		else if (!tmp.compare("0101"))
		{
			result = result + "5";
		}
		else if (!tmp.compare("0110"))
		{
			result = result + "6";
		}
		else if (!tmp.compare("0111"))
		{
			result = result + "7";
		}
		else if (!tmp.compare("1000"))
		{
			result = result + "8";
		}
		else if (!tmp.compare("1001"))
		{
			result = result + "9";
		}
		else if (!tmp.compare("1010"))
		{
			result = result + "A";
		}
		else if (!tmp.compare("1011"))
		{
			result = result + "B";
		}
		else if (!tmp.compare("1100"))
		{
			result = result + "C";
		}
		else if (!tmp.compare("1101"))
		{
			result = result + "D";
		}
		else if (!tmp.compare("1110"))
		{
			result = result + "E";
		}
		else if (!tmp.compare("1111"))
		{
			result = result + "F";
		}
		else
		{
			continue;
		}
	}
	return result;
}

void binaryStringStandardize(string& number, int len)
{
	string res;
	res = number.substr(number.length() - len);
	number = res;
}

string QInt::getBitString()
{
	string res;
	bitset<32> bit;
	int n = ((this->len) / 32)+1; //Xác định số phần tử trong mảng đã dùng
	int totalBit = this->len;
	int k = 3;
	for (int i = 1; i <= n; i++)
	{
		string temp;
		bit = bitset<32>(data[k]);
		temp = bit.to_string();
		k--;
		if (i == n) //Chuẩn hóa chuỗi bit tạm rồi mới đưa vào string trả về
		{
			binaryStringStandardize(temp, totalBit - (n-1)*32);
		}
		res += temp;
	}
	return res;
}

void main()
{
	string a = "101";
	string b = "102";
	string c = "203";
	int arr[4] = { 0 };
	bool sign = 0;
	string binaryString("000001010101010");

	//decimalToBinary(a,binaryString, sign);
	//addToArr(arr, binaryString);
	/*decimalToBinary(a, binaryString, sign);
	cout << binaryString  << endl;
	cout << reverseBinaryString(binaryString) << endl;*/
	
	QInt x(10, a);
	QInt y(10, b);
	QInt z(10, c);
	cout << (x+y).getBitString() << endl;
	cout << z.getBitString() << endl;
	


}