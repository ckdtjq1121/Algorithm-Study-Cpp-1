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

		int size = s.size();
		vector<int> alpha(26, 0);
		for (int i = 0; i < size; i++)
		{
			alpha[s[i] - 'a']++;
		}

		bool fail = false;
		for (int i = 0; i < 26; i++)
		{
			if (i < size && alpha[i] != 1)
				fail = true;
			else if (i >= size && alpha[i] > 0)
				fail = true;
		}

		if (fail)
		{
			cout << "NO\n";
			continue;
		}

		int start, end;
		for (int i = 0; i < size; i++)
		{
			if (s[i] == 'a')
			{
				start = end = i;
				break;
			}
		}


		for (int i = 1; i < size; i++)
		{
			//cout << start << " " << end << " " << 'a' + i << "\n";
			if (start > 0 && s[start - 1] == 'a' + i)
				start--;
			else if (end < size && s[end + 1] == 'a' + i)
				end++;
			else
			{
				fail = true;
				break;
			}
		}

		if (fail)
		{
			cout << "NO\n";
			continue;
		}
		else
			cout << "YES\n";
	}
}
