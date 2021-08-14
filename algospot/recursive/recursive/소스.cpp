// 1 ���� N���� �� ���� ���ϴ� �ݺ��Լ��� ����Լ�
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