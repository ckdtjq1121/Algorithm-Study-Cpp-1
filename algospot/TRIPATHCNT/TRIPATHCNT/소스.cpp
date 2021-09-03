#include<bits/stdc++.h>

using namespace std;
int triangle[101][101];
int dp[101][101];
		int n;

void makePath()
{
	for (int i = n - 1; i > 0; i--)
		for (int j = 1; j <= i; j++)
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);

	return;
}
int cnt(int y, int x)
{
	int& ret = dp[y][x];

	if (ret != -1)
		return ret;
	
	if (y == n)
		return 1;

	int a = triangle[y + 1][x];
	int b = triangle[y + 1][x+1];
	if (a < b)
		return ret = cnt(y + 1, x + 1);
	else if (a > b)
		return ret = cnt(y + 1, x);
	else
		return ret = cnt(y + 1, x) + cnt(y + 1, x + 1);

}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cin >> triangle[i][j];
			}
		}

		
		// triangle을 최대 경로의 값으로 갱신해 나간다.
		// dp : triangle 이 최대 경로일 때 경우의 수를 갱신해 나간다.
		//for (int j = 1; j <= n; j++)
		//	dp[n][j] = 1;

		//for (int i = n-1; i > 0; i--)
		//{
		//	for (int j = 1; j <= i; j++)
		//	{
		//		triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);

		//		if (triangle[i + 1][j] > triangle[i + 1][j + 1])
		//			dp[i][j] = dp[i + 1][j];
		//		else if (triangle[i + 1][j] == triangle[i + 1][j + 1])
		//			dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
		//		else
		//			dp[i][j] = dp[i + 1][j + 1];
		//	}
		//}

		////for (int i = 1; i <= n; i++)
		////{
		////	for (int j = 1; j <= i; j++)
		////	{
		////		cout << triangle[i][j] << " ";
		////	}
		////	cout << endl;
		////}
		////cout << endl;

		////for (int i = 1; i <= n; i++)
		////{
		////	for (int j = 1; j <= i; j++)
		////	{
		////		cout << dp[i][j] << " ";
		////	}
		////	cout << endl;
		////}
		////cout << endl;
		//cout << dp[1][1] << "\n";

		memset(dp, -1, sizeof(dp));
		makePath();
		cout << cnt(1, 1) << "\n";

	}
}