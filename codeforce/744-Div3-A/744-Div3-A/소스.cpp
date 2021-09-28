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
		int a = 0, b = 0, c = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'A')
				a++;
			else if (s[i] == 'B')
				b++;
			else
				c++;
		}

		//cout << a + c << " " << b << "\n";
		if (a + c == b)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}