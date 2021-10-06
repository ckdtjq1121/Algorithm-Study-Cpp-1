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
		int n, a, b;
		cin >> n >> a >> b;

		if (a == 1)
		{
			if ((n - 1) % b == 0)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else
		{
			bool end = false;
			ll x = 1;
			while (x <= n)
			{
				if (x % b == n % b)
				{
					end = true;
					break;
				}

				x *= a;
			}

			if (end)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}