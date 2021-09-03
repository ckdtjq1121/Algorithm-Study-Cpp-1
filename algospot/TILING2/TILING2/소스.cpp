#include<bits/stdc++.h>

using namespace std;
const int MOD = 1000000007;
int dp[101];
int waysToTiling(int n)
{
	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	int& ret = dp[n];
	if (ret != -1)
		return ret;


	return ret = (waysToTiling(n - 1) + waysToTiling(n - 2)) % MOD;
}

//int waysToTilingToTailRecursion(int n)
//{
//	if (n == 1)
//		return 1;
//
//	if (n == 2)
//		return 2;
//
//	int prevprev = 1;
//	int prev = 2;
//	int next = prevprev + prev;
//	int cnt = 3;
//	while (cnt++ < n)
//	{
//		prevprev = prev % MOD;
//		prev = next % MOD;
//		next = prevprev + prev % MOD;
//	}
//
//	return next;
//}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;

		memset(dp, -1, sizeof(dp));

		cout << waysToTiling(n) << "\n";
		//cout << waysToTilingToTailRecursion(n) << "\n";
	}
}