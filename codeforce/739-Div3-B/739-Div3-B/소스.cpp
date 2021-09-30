#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if(a > b)
		swap(a, b);
		int gap = abs(b - a);

		//cout << a << " " << gap << "\n";
		if (gap < a)
		{
			cout << -1 << "\n";
		}
		else
		{
			int fail = true;
			if (c <= gap * 2)
			{
				if (c + gap <= gap * 2)
				{
					cout << c + gap << "\n";
					fail = false;

				}
				else if (1 <= c - gap)
				{
					cout << c - gap << "\n";
					fail = false;
				}

			}

			if (fail)
				cout << -1 << "\n";
		}
			
	}
}