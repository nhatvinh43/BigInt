#include "QInt.h"
#include "OutterFunctions.h"

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

QInt operator+( QInt  firstNum,  QInt  secondNum)
{
	string result = "";
	string n1 = firstNum.toDecimal(), n2 = secondNum.toDecimal();

	int x = n1.find_first_of('-'), y = n2.find_first_of('-');
	char sign1 = n1.at(0), sign2 = n2.at(0);
	if (sign1 != '-' && sign2 != '-'){  //Hai số dương thì cộng bình thường
		result = addDec(n1, n2);
	}
	if (n1.find_first_not_of('-') == 0 && y == 0){  // Số đầu dương, số thứ 2 âm
		string n2_ = n2.erase(0, 1);
		result = Subtraction(n1, n2_);
	}
	else if (x == 0 && y == -1) //Số 1 âm, số 2 dương
	{
		result = Subtraction(n2, n1.erase(0, 1));
	}
	else if (x == 0 && y == 0)
	{
		string n1New = n1.erase(0, 1);
		string n2New = n2.erase(0, 1);
		result = '-' + addDec(n1New, n2New);
	}
	return QInt(10, result);
}



string QInt::getBitString() const
{
	string res;
	bitset<32> bit;
	int k = 3;
	for (int i = 1; i <= 4; i++)
	{
		string temp;
		bit = bitset<32>(data[k]);
		temp = bit.to_string();
		k--;
		res = temp + res;
	}
	return res;
}

string QInt::toBinary()
{
	if (this->toDecimal() == "0")
	{
		return "0";
	}
	string temp = this->getBitString();
	int pos = 0;
	while (temp.at(pos) == '0')
	{
		pos++;
	}
	return temp.substr(pos);
}

string QInt::toDecimal()
{
	string temp = this->getBitString();
	string res = binaryToDecimal(temp);
	return res;
}

string QInt::toHex()
{
	if (this->toDecimal() == "0")
	{
		return "0";
	}
	string temp = this->getBitString();
	
	string res = binToHex(temp);
	int pos = 0;
	while (res.at(pos) == '0')
	{
		pos++;
	}
	return res.substr(pos);
}
QInt QInt:: operator >> (int number)
{
	string res = this->getBitString();
	for (int i = 1; i <= number; i++)
	{
		res = shiftRight(res);
	}
	QInt temp(2, res);
	return temp;
}
QInt QInt:: operator << (int number)
{
	string res = this->getBitString();
	for (int i = 1; i <= number; i++)
	{
		res = shiftLeft(res);
	}
	QInt temp(2, res);
	return temp;
}
QInt QInt::operator~()
{
	string res = this->getBitString();
	res = reverseBinaryString(res);
	return QInt(2, res);
}
QInt operator- (QInt num1, QInt num2)
{
	string res = num2.getBitString();
	res = binaryToSecondComplement(res);
	QInt temp(2, res);
	return (num1 + temp);
}
int QInt::compare(QInt number)
{
	string temp1 = this->toDecimal();
	string temp2 = number.toDecimal();
	int signCheck = 0;
	
	if (this->sign == 0 && number.sign == 1)
	{
		return 1;
	}
	if (this->sign == 1 && number.sign == 0)
	{
		return -1;
	}
	if (this->sign == 1 && number.sign == 1)
	{
		temp1.erase(temp1.begin());
		temp2.erase(temp2.begin());
		signCheck = 1;
	}
	int n1 = temp1.length();
	int n2 = temp2.length();
	if (n1 < n2)
	{
		if (signCheck == 1)
		{
			return 1;
		}
		else
			return -1;
	}
	else if (n1>n2)
	{
		if (signCheck == 1)
		{
			return -1;
		}
		else return 1;
	}
	else if (n1 == n2)
	{
		
		if (signCheck == 1)
		{
			if (temp1 < temp2)
			{
				return 1;
			}
			else if (temp1>temp2)
			{
				return -1;
			}
			else if (temp1 == temp2)
			{
				return 0;
			}
		}
		else
		{
			return temp1.compare(temp2);
		}
	}
}
QInt QInt::ror()
{
	string res = this->getBitString();
	int len = res.length();
	char c = res.at(len - 1);
	res.pop_back();
	res = c + res;
	return QInt(2, res);
}
QInt QInt::rol()
{
	string res = this->getBitString();
	int len = res.length();
	char c = res.at(0);
	res.erase(res.begin());
	res = res + c;
	return QInt(2, res);
}
QInt QInt::operator |(QInt number)
{
	string binaryString1 = this->getBitString();
	string binaryString2 = number.getBitString();

	QInt temp;
	int len = makeEqualLength(binaryString1, binaryString2);


	for (int i = 3; i >= 0; i--)
	{
		temp.data[i] = this->data[i] | number.data[i];
	}
	temp.len = len;
	if (temp.getBitString().at(0) == '1')
	{
		temp.sign = 1;
	}
	else temp.sign = 0;
	return temp;
}

QInt QInt::operator & (QInt number)
{
	string binaryString1 = this->getBitString();
	string binaryString2 = number.getBitString();

	QInt temp;
	int len = makeEqualLength(binaryString1, binaryString2);


	for (int i = 3; i >= 0; i--)
	{
		temp.data[i] = this->data[i] & number.data[i];
	}
	temp.len = len;
	if (temp.getBitString().at(0) == '1')
	{
		temp.sign = 1;
	}
	else temp.sign = 0;
	return temp;
}

QInt QInt::operator ^ (QInt number)
{
	string binaryString1 = this->getBitString();
	string binaryString2 = number.getBitString();

	QInt temp;
	int len = makeEqualLength(binaryString1, binaryString2);


	for (int i = 3; i >= 0; i--)
	{
		temp.data[i] = this->data[i] ^ number.data[i];
	}
	temp.len = len;
	if (temp.getBitString().at(0) == '1')
	{
		temp.sign = 1;
	}
	else temp.sign = 0;
	return temp;
}


QInt operator/ (QInt number1, QInt number2)
{
	if (number1.toDecimal()=="0")
	{
		return QInt(10, "0");
	}
	if (number1.compare(number2) == 0)
	{
		return QInt(10, "1");
	}
	if (number2.toDecimal() == "0")
	{
		throw new exception("Divide by 0 error!\n");
	}
	int signFlag; // =1 nếu 2 số dương hoặc 2 số âm, bằng 0 nếu 1 dương 1 âm
	if (number1.sign == number2.sign)
	{
		signFlag = 1;
	}
	else
	{
		signFlag = 0;
	}
	string n1 = number1.toDecimal();
	string n2 = number2.toDecimal();
	
	if (number1.sign == 1)
	{
		n1.erase(n1.begin());
	}
	if (number2.sign == 1)
	{
		n2.erase(n2.begin());
	}
	
	string res="0";
	while (1)
	{
		n1 = Subtraction(n1, n2);
		res = addDec(res, "1");
		QInt temp1(10, n1);
		QInt temp2(10, n2);
		if (temp1.compare(temp2) == -1)
		{
			break;
		}
	}
	if (signFlag == 0)
	{
		res = '-' + res;
	}
	return QInt(10, res);
}

QInt operator*(QInt num1, QInt num2)
{
	string n1 = num1.toDecimal();
	string n2 = num2.toDecimal();
	string temp = Multiplication(n1, n2);
	return QInt(10, temp);
}