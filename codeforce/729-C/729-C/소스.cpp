#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
	if (a < b)
		swap(a, b);

	ll tmp;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		ll n;
		cin >> n;

		ll ans = n;
		ll lcm = 1;
		for (int i = 1; i <= n; i++)
		{
	
			lcm = lcm / gcd(lcm, i) * i;
			ans += n / lcm;
			ans %= 1000000007;

			if (n < lcm)
				break;
		}

		cout << ans << "\n";
	}
}