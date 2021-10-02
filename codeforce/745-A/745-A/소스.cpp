#include<bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	long long dp[200001];
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 200000; i++)
	{
		dp[i] = dp[i-1] * i;
		dp[i] %= 1000000007;
	}

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;

		cout << dp[2 * n] << "\n";
	}
}