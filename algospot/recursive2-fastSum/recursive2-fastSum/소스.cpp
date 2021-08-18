// 1 부터 N까지 의 합을 구하는 반복함수와 재귀함수
#include<iostream>

using namespace std;

int recursiveFunction(int n)
{
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;

	return n + recursiveFunction(n - 1);
}

int fastSum(int n) // divide and conqure
{
	// basecase
	if (n == 1)
		return 1;

	if (n % 2 == 1)
		return fastSum(n - 1) + n;

	// divide and merge
	return 2 * fastSum(n / 2) + n * n / 4;
}
int main()
{
	int n;
	cin >> n;

	cout << recursiveFunction(n) << " " << fastSum(n) << "\n";

	return 0;
}