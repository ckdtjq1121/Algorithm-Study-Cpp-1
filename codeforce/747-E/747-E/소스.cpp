#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int k;
	cin >> k;

	vector<ll> arr(61);
	arr[1] = 1;
	arr[2] = 16;
	for (int i = 3; i <= k; i++)
	{
		arr[i] = (arr[i - 1] * arr[i - 1]) % MOD;
	}

	ll ans = 6;
	int n;
	cin >> n;
	map<int, string> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		string s;
		cin >> a >> s;

		m[a] = s;
	}

	map<int, string>::iterator iter = m.begin();
	/*for (int i = 0; i < m.size(); i++)
	{
		if(*iter)
	}*/
	for (int i = 1; i <= k; i++)
	{
		ans = (ans * arr[i]) % MOD;
	}

	cout << ans << "\n";
}

// 부모 자식