#include<bits/stdc++.h>
// b
using namespace std;
typedef long long ll;
ll baseK(ll a, ll k)
{
	ll digit = 1;
	ll ret = 0;
	while (a > 0)
	{
		ret += (a % 10) * digit;
		a /= 10;
		digit *= k;
	}

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll k;
	cin >> k;
	ll a, b;
	cin >> a >> b;

	cout << baseK(a, k) * baseK(b, k) << "\n";
}
