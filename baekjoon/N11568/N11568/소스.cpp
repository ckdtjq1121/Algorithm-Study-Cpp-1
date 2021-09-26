#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	vector<int> dp(n, 1);
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] < arr[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		//cout << dp[i] << " ";
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";
}