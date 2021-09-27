#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		string s;
		cin >> s;


		int ans = 10;
		int ag = 0, ab = 0, bg = 0, bb = 0, ac = 5, bc = 5;
		for (int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
			{
				if (s[i] == '1')
					ag++;
				else if (s[i] == '?')
					ab++;

				ac--;
			}
			else
			{
				if (s[i] == '1')
					bg++;
				else if (s[i] == '?')
					bb++;

				bc--;
			}
			
			if (ac + ag < bg + bb || bc + bg < ag + ab)
			{
				ans = i + 1;
				break;
			}			
		}

		cout << ans << "\n";
	}
}