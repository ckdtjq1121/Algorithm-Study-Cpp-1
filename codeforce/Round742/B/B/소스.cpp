#include <iostream>

using namespace std;

int dp[300001];
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int testCase;
	cin >> testCase;

	dp[0] = 0;
	for (int i = 1; i <= 300000; i++)
	{
		dp[i] = dp[i - 1] ^ i;
	}

	for (; testCase > 0; testCase--)
	{
		int a, b;
		cin >> a >> b;

		int x = dp[a - 1];
		int z = b;
		int y = (x ^ z);

		int ans;
		if (x == z)
			ans = a;
		else
		{
			if (y == a)
				ans = a + 2;
			else
				ans = a + 1;
		}

		cout << ans << "\n";
	}
}