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
		cin >> n;

		string s;
		cin >> s;

		int cnt = 0;
		for (int i = 0; i < s.size(); i++)
		{
			int c = s[i] - 48;

			if (i == s.size() - 1)
				cnt += c;		// cnt
			else if(c != 0)
				cnt += c + 1; // cnt ans digit  change
		}

		cout << cnt << "\n";
	}
}
