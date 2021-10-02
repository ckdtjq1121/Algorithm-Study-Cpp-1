#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;  cin.ignore();

	for (; testCase > 0; testCase--)
	{
		string s;
		getline(cin, s);

		int sum = 0;

		string tmp = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ')
				tmp += s[i];
			else
			{
				sum += stoi(tmp);
				tmp = "";
			}
		}
		sum += stoi(tmp);
		cout << sum << "\n";

	}
}


