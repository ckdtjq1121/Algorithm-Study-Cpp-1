#include<bits/stdc++.h>

using namespace std;

const int MOD = 15746;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int a = 0, b = 1, c = a + b; // 1번 연산
	for (int i = 1; i < n; i++) // n - 1 번 연산
	{
		a = b % MOD;
		b = c % MOD;
		c = (a + b) % MOD;
	}

	cout << c << "\n";
}