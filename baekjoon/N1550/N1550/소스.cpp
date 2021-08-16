// 16진수를 입력받아서 10진수로 출력하는 프로그램
#include<iostream>
#include<string>
using namespace std;
char hexDecDB[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	
int solveToCppGrammer(string hexDec)
{
	const char* c = hexDec.c_str(); // string.c_str() : string  to  const char*
	int nDec = (int)strtol(c, NULL, 16); // str to long : 문자열을 정수로 바꿔줌 n진수로 계산할지 정할 수 있음
	int ret = nDec;

	return ret;
}

int hexDecToDec(string hexDec)
{
	int ret = 0;
	const char* ch = hexDec.c_str();
	int digit = 1;
	for (int i = hexDec.size() - 1; i >= 0; i--)
	{
		// cpp 에서 string char char* const char 등등에 대해 자세히 공부하기 책으로
		
		for (int j = 0; j < 16; j++)
		{
			if (hexDecDB[j] == ch[i])
				ret += j * digit;
		}
		
		digit *= 16;
	}
	return ret;
}

int main()
{
	string hexadecimal;
	cin >> hexadecimal;

	cout << solveToCppGrammer(hexadecimal) << "\n";
	//cout << hexDecToDec(hexadecimal) << "\n";
}