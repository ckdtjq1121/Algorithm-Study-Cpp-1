#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int x1, y1, x2, y2, x3, y3;// 1 에서 2까지 3을 피해서
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		int ans = 0;
		if (x1 == x2 && x2 == x3)
		{
			if ((y1 < y3 && y3 < y2) || (y2 < y3 && y3 < y1))
			{
				ans += 2;
			}
		}
		else if (y1 == y2 && y2 == y3)
		{
			if ((x1 < x3 && x3 < x2) || (x2 < x3 && x3 < x1))
			{
				ans += 2;
			}

		}

		ans += abs(x2 - x1) + abs(y2 - y1);

		cout << ans << "\n";
	}
}