// 1 부터 N까지 의 합을 구하는 반복함수와 재귀함수
#include<iostream>

using namespace std;

int repeatFunction(int n)
{
	int ret = 0;
	for (int i = 1; i <= n; i++)
	{
		ret += i;
	}
	
	return ret;
}

int recursiveFunction(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;

	return n + recursiveFunction(n - 1);
}
int main()
{
	int n;
	cin >> n;

	cout << repeatFunction(n) << " " << recursiveFunction(n) << "\n";

	return 0;
}