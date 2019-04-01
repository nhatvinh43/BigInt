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

		binaryString += "0";
		if (binaryString == "00")
		{
			binaryString = "0";
		}
		reverse(binaryString.begin(), binaryString.end());
		if (sign == 1)
		{
			binaryString = binaryToSecondComplement(binaryString);

			return;
		}
		return;
	}
	decimalToBinary(a, binaryString, sign);
}

string binaryToSecondComplement(string binaryString)
{
	if (binaryString == "0")
	{
		return "0";
	}
	int n = binaryString.length();
	binaryString = reverseBinaryString(binaryString);
	string res = addBin(binaryString, "1");
	return res;
}
string binaryToDecimal(string binaryString)
{

	int n = binaryString.length();
	bool sign=0;
	if (binaryString.at(0) == '1')
	{
		sign = 1;
	}
	string positivePart="0"; //Chuỗi tổng các số phần dương
	string negativePart;//Chuỗi phần âm
	int k = 0; //vị trí số mũ
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == 0 && sign == 1)
		{
			negativePart = pow("2", k);
			break;
		}
		if (binaryString.at(i) == '1')
		{
			positivePart = addDec(positivePart,pow("2", k));
		}
		
		k++;
	}
	if (sign == 0)
	{
		return positivePart;
	}
	else
	{
		string res="-";
		res += diff(negativePart, positivePart);
		return res;
	}
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
		
		decimalToBinary(str, binaryString, this->sign);  //Chuyển về chuỗi nhị phân thứ tự đúng (dạng bù 2)
		if (binaryString.at(0) == '1')
		{
			this->sign = 1;
		}
		else this->sign = 0;
		this->len = binaryString.length();
	}
	if (kind == 16) //Nếu chuỗi là chuỗi hệ 16
	{
		binaryString = hexToBinary(str);
		if (binaryString.at(0) == '1')
		{
			this->sign = 1;
		}
		else
		{
			this->sign = 0;
		}
		this->len = binaryString.length();
	}

	for (int i = 0; i < 4; i++)
	{
		this->data[i] = (this->data[i] & 0);
	}
	int k =binaryString.length()-1;
	int shiftCount = 0; //Biến lưu số bit cần dịch, reset lại =0 mỗi khi qua ô mới
	int temp=3;
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
		
		this->data[bitPosition] = this->data[bitPosition] | ((int)(binaryString[k] - 48) << shiftCount);

		shiftCount++;
		k--;
	}
	
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


int makeEqualLength(string &str1, string &str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2)
	{
		for (int i = 0; i < len2 - len1; i++){
			str1 = '0' + str1;
		}
		return len2;
	}
	else if (len1 > len2)
	{
		for (int i = 0; i < len1 - len2; i++){
				str2 = '0' + str2;
		}
		return len1; // n?u len1 >= len2 
	}
}

string Subtraction(string a, string b)
{
	string result = "";
	while (a.length() < b.length())
		a = '0' + a;
	while (b.length() < a.length())
		b = '0' + b;
	bool neg = false;
	if (a<b)
	{
		swap(a, b);
		neg = true;
	}
	int borrow = 0;
	for (int i = a.length() - 1; i >= 0; i--)
	{
		int x = a[i] - b[i] - borrow;
		if (x<0)
		{
			x += 10;
			borrow = 1;
		}
		else borrow = 0;
		result = (char)(x % 10 + 48) + result;
	}
	while (result.length()>1 && result[0] == '0') result.erase(0, 1);
	if (neg) result = "-" + result;
	return result;
}

string addBin( string firstNum,  string secondNum)
{
	string result = ""; // Initialize result 
	int s = 0;          // Initialize digit sum 

	// Travers both strings starting from last 
	// characters 
	int i = firstNum.size() - 1, j = secondNum.size() - 1;
	while (i >= 0 || j >= 0 || s == 1)
	{
		// Comput sum of last digits and carry 
		s += ((i >= 0) ? firstNum[i] - '0' : 0);
		s += ((j >= 0) ? secondNum[j] - '0' : 0);

		// If current digit sum is 1 or 3, add 1 to result 
		result = char(s % 2 + '0') + result;

		// Compute carry 
		s /= 2;

		// Move to next digits 
		i--; j--;
	}
	
	return result;

}

string addDec(string number1, string number2)
{

	if (number1.length() > number2.length())
		number1.swap(number2);

	string result = ""; //khởi tạo chuỗi để lưu kết quả

	int n1 = number1.length(), n2 = number2.length();

	// đảo ngược 2 chuỗi
	reverse(number1.begin(), number1.end());
	reverse(number2.begin(), number2.end());

	int carry = 0;
	for (int i = 0; i<n1; i++)
	{

		int sum = ((number1[i] - '0') + (number2[i] - '0') + carry);
		result.push_back(sum % 10 + '0');

		carry = sum / 10;
	}

	// Thêm các chữ số còn lại của số lớn hơn
	for (int i = n1; i<n2; i++)
	{
		int sum = ((number2[i] - '0') + carry);
		result.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if (carry)
		result.push_back(carry + '0');

	reverse(result.begin(), result.end()); //chuỗi kết quả ngược

	return result;
}

string binToHex(string bin){
	string result;
	//string tmp, chr = "0000";
	string tmp;
	reverse(bin.begin(), bin.end());
	int len = bin.length() / 4;
	//chr = chr.substr(0, len);
	//bin = chr + bin;
	for (int i = 0; i<bin.length(); i += 4)
	{
		tmp = bin.substr(i, 4);
		if (!tmp.compare("0000"))
		{
			result = result + "0";
		}
		else if (!tmp.compare("0001"))
		{
			result = result + "8";
		}
		else if (!tmp.compare("0010"))
		{
			result = result + "4";
		}
		else if (!tmp.compare("0011"))
		{
			result = result + "C";
		}
		else if (!tmp.compare("0100"))
		{
			result = result + "2";
		}
		else if (!tmp.compare("0101"))
		{
			result = result + "A";
		}
		else if (!tmp.compare("0110"))
		{
			result = result + "6";
		}
		else if (!tmp.compare("0111"))
		{
			result = result + "E";
		}
		else if (!tmp.compare("1000"))
		{
			result = result + "1";
		}
		else if (!tmp.compare("1001"))
		{
			result = result + "9";
		}
		else if (!tmp.compare("1010"))
		{
			result = result + "5";
		}
		else if (!tmp.compare("1011"))
		{
			result = result + "D";
		}
		else if (!tmp.compare("1100"))
		{
			result = result + "3";
		}
		else if (!tmp.compare("1101"))
		{
			result = result + "B";
		}
		else if (!tmp.compare("1110"))
		{
			result = result + "7";
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
	reverse(result.begin(), result.end());
	return result;
}

void binaryStringStandardize(string& number, int len)
{
	string res;
	res = number.substr(number.length() - len);
	number = res;
}

string QInt::getBitString() const
{
	string res;
	bitset<32> bit;
	int n = ((this->len) / 32)+1; //Xác định số phần tử trong mảng đã dùng
	if (this->len % 32 == 0)
	{
		n = this->len / 32;
	}
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
		res = temp + res;
	}
	return res;
}

string multiply(string num1, string num2)
{
	int n1 = num1.length();
	int n2 = num2.length();
	if (n1 == 0 || n2 == 0)
	{
		return "0";
	}

	//Lưu kết quả vào vector theo thứ tự ngược
	vector<int> result(n1 + n2, 0);

	// Hai biến phụ tìm vị trí trong vector result
	int nPos1 = 0;
	int nPos2 = 0;

	// Duyệt số đầu tiên từ phải sang trái 
	for (int i = n1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		//Dịch chuyển vị trí sang trái sau mỗi lần nhân với một kí số của số thứ 2
		nPos2 = 0;

		// Duyệt từ phải sang trái ở số thứ 2           
		for (int j = n2 - 1; j >= 0; j--)
		{
			// Bốc ra kí số hiện tại của số thứ 2
			int n2 = num2[j] - '0';

			//Nhân n2 với số n1 và cộng vào kết quả đã lưu trước dó ở vị trí hiện tại
			int sum = n1*n2 + result[nPos1 + nPos2] + carry;

			// Phần nhớ
			carry = sum / 10;

			// Lưu vào kết quả
			result[nPos1 + nPos2] = sum % 10;

			nPos2++;
		}

		//Cộng phần nhớ
		if (carry > 0)
			result[nPos1 + nPos2] += carry;

		//Dịch chuyển sang kí số tiếp theo
		nPos1++;
	}

	// Bỏ qua số 0 bên phải
	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	// Kiểm tra xem trong 2 số có số nào là 0 không
	if (i == -1)
		return "0";

	
	string s = "";

	while (i >= 0)
		s += to_string(result[i--]);

	return s;
}

string pow(string num, int exp)
{
	string res;
	string temp = "1";
	res = temp;
	for (int i = 1; i <= exp; i++)
	{
		temp = multiply(num, temp);
		res = temp;
	}
	return res;
}

bool isSmaller(string num1, string num2)
{
	{
		int len1 = num1.length(), len2 = num2.length();

		if (len1 < len2)
		{
			return true;
		}
		if (len1 > len2)
		{
			return false;
		}

		for (int i = 0; i<len1; i++)
		{
			if (num1[i] < num2[i])
			{
				return true;
			}
			else if (num1[i] > num2[i])
			{
				return false;
			}
		}
		return false;
	}
}

string diff(string num1, string num2)
{
	//Lưu ý: 2 số truyền vào đã được lược bỏ dấu - nếu có
	// Đảm bảo số đầu tiên là số lớn hơn (về mặt giá trị tuyệt đối)
	if (isSmaller(num1, num2))
	{
		string temp = num1;
		num1 = num2;
		num2 = temp;
	}

	string res;
	int len1 = num1.length(), len2 = num2.length();
	int diff = len1 - len2;

	// Initially take carry zero 
	int carry = 0;

	// Traverse from end of both strings 
	for (int i = len2 - 1; i >= 0; i--)
	{
		// Do school mathematics, compute difference of 
		// current digits and carry 
		int sub = ((num1[i + diff] - '0') -(num2[i] - '0') - carry);
		if (sub < 0)
		{
			sub = sub + 10;
			carry = 1;
		}
		else
			carry = 0;

		res.push_back(sub + '0');
	}

	// subtract remaining digits of str1[] 
	for (int i = len1 - len2 - 1; i >= 0; i--)
	{
		if (num1[i] == '0' && carry)
		{
			res.push_back('9');
			continue;
		}
		int sub = ((num1[i] - '0') - carry);
		if (i>0 || sub>0) // remove preceding 0's 
			res.push_back(sub + '0');
		carry = 0;

	}

	// reverse resultant string 
	reverse(res.begin(), res.end());

	return res;
}

string QInt::toBinary()
{
	return this->getBitString();
}

string QInt::toDecimal()
{
	string temp = this->getBitString();
	string res = binaryToDecimal(temp);
	return res;
}

string QInt::toHex()
{
	string temp = this->getBitString();
	string res = binToHex(temp);
	return res;
}
string shiftRight(string number)
{
	string res;
	int n = number.length();
	char bitSign = number.at(0);
	res += bitSign;
	res+=number.substr(0,n-1);
	return res;
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
string shiftLeft(string number)
{
	string res;
	int n = number.length();
	res = number.substr(1, n - 1);
	res += "0";
	return res;
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
	int n1 = this->getBitString().length();
	int n2 = number.getBitString().length();
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
QInt operator* (QInt number1, QInt number2)
{
	string n1Dec = number1.toDecimal();
	string n2Dec = number2.toDecimal();
	if (n1Dec == "0" || n2Dec == "0")
	{
		return QInt(2, "0");
	}
	if (n1Dec == "1")
	{
		return QInt(10, n2Dec);
	}
	if (n2Dec == "1")
	{
		return QInt(10, n2Dec);
	}



}
void main()
{
	string a = "0";
	string b = "0";
	string c = "0";
	int arr[4] = { 0 };
	bool sign = 0;
	string binaryString;

	
	
	QInt x(10, a);
	QInt y(10, b);
	QInt z(10, c);
	QInt xx(10, "998");
	
	cout << z.getBitString() << endl;
	
//	cout << (x.rol()).getBitString() << endl;
	cout << (x - y).toDecimal() << endl;
	/*cout << z.getBitString() << endl;*/
	//cout << (x*y).getBitString() << endl;
	/*cout << x.toBinary() << endl;
	cout << x.toDecimal() << endl;
	cout << x.toHex() << endl;*/
}
