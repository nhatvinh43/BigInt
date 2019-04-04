#include "QInt.h"
#include "OutterFunctions.h"

QInt operator/(QInt x, QInt y)
{
	
}

void main(int argc, char* argv[])
{
	/*if (argc == 1)
	{
		argv[1] = "input.txt";
		argv[2] = "output.txt";
	}
	if (argc == 2)
	{
		argv[2] = "output.txt";
	}
	cout << "Processing, please wait!\n";
	
	ifstream input(argv[1]);
	ofstream output(argv[2], ios::out);
	if (input.is_open() == 0)
	{
		return;
	}
	while (!input.eof())
	{
		try{
			string sKind;
			getline(input, sKind, ' ');
			if (sKind == "")
			{
				return;
			}
			int kind= stoi(sKind); //Lưu hệ cơ số làm viẹc
			string tempS; // Lưu chuỗi tạm
			getline(input, tempS, ' ');//Đọc chuỗi cho tới dấu cách
			if ((tempS == "10") || (tempS == "16") || (tempS == "2") || (tempS == "~") || (tempS == "ror") || tempS == ("rol")) //Nhận diện chuyển đổi cơ số hoặc thao tác với toán tử 1 ngôi
			{
				if (tempS == "10" || tempS == "16" || tempS == "2") //Phát hiện chuyển đổi cơ số
				{
					string number;
					getline(input, number); //Get chuỗi số cần chuyển đổi
					QInt res(kind, number);
					if (tempS == "10")
					{
						output << res.toDecimal()<<endl;
					}
					if (tempS == "16")
					{
						output << res.toHex()<<endl;
					}
					if (tempS == "2")
					{
						output << res.toBinary()<<endl;
					}
				}
				else //Phát hiện các toán tử 1 ngôi còn lại
				{
					string number;
					getline(input, number); //Get chuỗi số cần chuyển đổi
					QInt res(kind, number);
					if (tempS == "~")
					{
						if (kind == 2)
						{
							output << (~res).toBinary()<<endl;
						}
						if (kind == 10)
						{
							output << (~res).toDecimal()<<endl;
						}
						if (kind == 16)
						{
							output << (~res).toHex()<<endl;
						}
					}
					if (tempS == "ror")
					{
						if (kind == 2)
						{
							output << (res.ror()).toBinary()<<endl;
						}
						if (kind == 10)
						{
							output << (res.ror()).toDecimal()<<endl;
						}
						if (kind == 16)
						{
							output << (res.ror()).toHex()<<endl;
						}
					}
					if (tempS == "rol")
					{
						if (kind == 2)
						{
							output << (res.rol()).toBinary()<<endl;
						}
						if (kind == 10)
						{
							output << (res.rol()).toDecimal()<<endl;
						}
						if (kind == 16)
						{
							output << (res.rol()).toHex()<<endl;
						}
					}
				}

			}
			else //Các toán tử 2 ngôi gồm +, -, *, /, &, |, ^, >>, <<, chuỗi tempS lúc này sẽ là số hạng thứ nhất
			{
				QInt firstNum(kind, tempS);

				getline(input, tempS, ' ');//Đọc toán tử
				string num2;
				getline(input, num2);//Đọc toán hạng thứ 2
				if (tempS == "+")
				{
					QInt secondNum(kind, num2);
					if (kind == 2)
					{
						output << (firstNum + secondNum).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum + secondNum).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum + secondNum).toHex()<<endl;
					}
				}
				if (tempS == "-")
				{
					QInt secondNum(kind, num2);
					if (kind == 2)
					{
						output << (firstNum - secondNum).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum - secondNum).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum - secondNum).toHex()<<endl;
					}
				}
				if (tempS == "*")
				{
					QInt secondNum(kind, num2);
					if (kind == 2)
					{
						output << (firstNum * secondNum).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum * secondNum).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum * secondNum).toHex()<<endl;
					}
				}
				if (tempS == "/")
				{
					output << "000\n";
					continue;
					QInt secondNum(kind, num2);
					if (kind == 2)
					{
						output << (firstNum / secondNum).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum / secondNum).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum / secondNum).toHex()<<endl;
					}
				}
				if (tempS == "&")
				{
					QInt secondNum(kind, num2);
					if (kind == 2)
					{
						output << (firstNum & secondNum).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum & secondNum).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum & secondNum).toHex()<<endl;
					}
				}
				if (tempS == "|")
				{
					QInt secondNum(kind, num2);
					if (kind == 2)
					{
						output << (firstNum | secondNum).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum | secondNum).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum | secondNum).toHex()<<endl;
					}
				}
				if (tempS == "^")
				{
					QInt secondNum(kind, num2);
					if (kind == 2)
					{
						output << (firstNum ^ secondNum).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum ^ secondNum).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum ^ secondNum).toHex()<<endl;
					}
				}
				if (tempS == "<<")
				{
					if (kind == 2)
					{
						output << (firstNum << stoi(num2)).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum << stoi(num2)).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum << stoi(num2)).toHex()<<endl;
					}
				}
				if (tempS == ">>")
				{
					if (kind == 2)
					{
						output << (firstNum >> stoi(num2)).toBinary()<<endl;
					}
					if (kind == 10)
					{
						output << (firstNum >> stoi(num2)).toDecimal()<<endl;
					}
					if (kind == 16)
					{
						output << (firstNum >> stoi(num2)).toHex()<<endl;
					}
				}

			}
		}
		catch (exception e)
		{
			output << "\n";
		}
	}
	input.close();
	output.close();
	system("cls");
	cout << "Operation finished!\n";*/



}