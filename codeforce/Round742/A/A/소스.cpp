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
		string s;
		cin >> n;
		cin >> s;

		string ans = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'U')
				ans += 'D';
			else if (s[i] == 'D')
				ans += 'U';
			else
				ans += s[i];
		}

		cout << ans << endl;
	}
}

