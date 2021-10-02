#include<bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	vector<int> tmp(10, 0);
	vector<int> ans(10, 0);

	ans[(arr[0] + arr[1]) % 10]++;
	ans[(arr[0] * arr[1]) % 10]++;

	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j < 10; j++)
			tmp[j] = 0;

		for (int j = 0; j < 10; j++)
		{
			if (ans[j])
			{
				tmp[(j + arr[i]) % 10] = (tmp[(j + arr[i]) % 10] + ans[j]) % MOD;
				tmp[(j * arr[i]) % 10] = (tmp[(j * arr[i]) % 10] + ans[j]) % MOD;
			}
		}

		ans = tmp;

	}

	for (int j = 0; j < 10; j++)
		cout << ans[j] << "\n";
}