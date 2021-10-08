#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		char c;
		cin >> n >> c;

		string s;
		cin >> s;

		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != c)
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			cout << 0 << "\n";
		}
		else
		{
			if (n % 2 == 1)
			{
				flag = false;
				for (int i = n - 1; i >= (n - 1) / 2; i--)
				{
					//cout << s[i] << " " << c << "\n";
					if (s[i] == c)
					{
						cout << 1 << "\n";
						cout << i + 1 << "\n";
						flag = true;
						break;
					}
				}
			}
			else
			{
				flag = false;
				for (int i = n - 1; i > (n - 1) / 2; i--)
				{
					//cout << s[i] << " " << c << "\n";
					if (s[i] == c)
					{
						cout << 1 << "\n";
						cout << i + 1 << "\n";
						flag = true;
						break;
					}
				}
			}

			if (flag)
				continue;

			cout << 2 << "\n";
			cout << n - 1 << " " << n << "\n";
		}
	}
}