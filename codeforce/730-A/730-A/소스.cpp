#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		ll a, b;
		cin >> a >> b;

		if (a < b)
			swap(a, b);

		ll	gcd = a - b;
		if (gcd == 0)
			cout << 0 << " " << 0 << "\n";
		else
		{
			ll move = a % gcd;
			move = min(move, gcd - move);
			cout << gcd << " " << move << "\n";
		}
	}
}