// 비오면 2미터  0.75
// 비 안오면 1미터 0.25

// 4 * (3/4)^3 *(1/4)
#include<bits/stdc++.h>
long long dp[1001][1001];
double powerS[1001];
double powerR[1001];
using namespace std;
long long combination(int n, int r)
{
	if (r == 0 || r == n)
		return 1;

	if (r == 1 || r == n - 1)
		return n;

	long long& ret = dp[n][r];

	if (ret != -1)
		return ret;

	return ret = combination(n - 1, r) + combination(n - 1, r - 1);
}
//double powerSunny(int sunny)
//{
//	if (sunny == 0)
//		return 1;
//	if (sunny == 1)
//		return 0.25;
//
//	double& ret = powerS[sunny];
//	if (ret != -1)
//		return ret;
//
//	double half;
//	if (sunny % 2)
//		return ret = 0.25 * powerSunny(sunny - 1);
//	else
//	{
//		half = powerSunny(sunny / 2);
//		return ret = half * half;
//	}
//}
//double powerRainy(int rainy)
//{
//	if (rainy == 0)
//		return 1;
//
//	if (rainy == 1)
//		return 0.75;
//
//	double& ret = powerR[rainy];
//	if (ret != -1)
//		return ret;
//
//	double half;
//	if (rainy % 2)
//		return ret = 0.75 * powerRainy(rainy - 1);
//	else
//	{
//		half = powerRainy(rainy / 2);
//		return ret = half * half;
//	}
//}
double escapePercent(int sunny, int rainy)
{
	double ret = combination(sunny + rainy, rainy) * powerS[sunny] * powerR[rainy];

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	cout << fixed;
	cout.precision(10);

	memset(dp, -1, sizeof(dp));
	powerR[0] = 1;
	powerS[0] = 1;
	for (int i = 1; i < 1001; i++)
	{
		powerR[i] = powerR[i - 1] * 0.75;
		powerS[i] = powerS[i - 1] * 0.25;
	}


	for (; testCase > 0; testCase--)
	{
		int n, m;
		cin >> n >> m;

		double ans = 0;
		for (int i = 0; i <= m; i++)
		{
			if (i + (m - i) * 2 >= n)
			{
				ans += escapePercent(i, m - i);
			}
		}

		cout << ans << "\n";
	}
}
