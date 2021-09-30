#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int k;
		cin >> k;

		int y = 0, x = 1;
		while (x * x < k)
			x++;

		k -= (x - 1) * (x - 1);

		while (y < x)
		{
			if (k == 0)
				break;

			y++;
			k--;
		}

		while (k > 0)
		{
			x--;
			k--;
		}

		cout << y << " " << x << "\n";
	}
}