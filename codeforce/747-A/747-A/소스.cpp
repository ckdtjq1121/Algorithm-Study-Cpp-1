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
		ll n;
		cin >> n;

		cout << -n + 1 << " " << n << "\n";
	}
}