#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		ll n, k;
		cin >> n >> k;

		ll ans = 0;
		vector<ll> power;
		power.push_back(1);
		int i = 1;
		while ((1ll << i) <= k)
		{
			ll tmp = power.back() * n % MOD;
			power.push_back(tmp);
			i++;	
		}

		i = 0;
		while ((1ll << i) <= k)
		{
			if ((k & (1ll << i)))
				ans = (ans + power[i]) % MOD;

			i++;
			//cout << ans << " ";
		}

		cout << ans << "\n";
	}
}