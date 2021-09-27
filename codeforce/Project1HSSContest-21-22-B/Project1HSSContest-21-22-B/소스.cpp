#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		string s, t;
		cin >> s >> t;
		
		int ss = s.size();
		int ts = t.size();
			
		int i;
		int j = 0;
		bool end = false;
		for (i = 0; i < ss; i++)
		{
			if (j == ts)
			{
				end = true;
				break;
			}
			if (s[i] == t[j])
			{
				
				int a = i - 1;
				int b = j + 1;
				while (a >= 0 && b < ts && s[a] == t[b])
				{
					a--;
					b++;
				}

				// ans
				if (b == ts)
				{
					end = true;
					break;
				}

				j++;
			}
		}

		if (end)
		{
			cout << "YES\n";
			continue;
		}
		else
			cout << "NO\n";

	}
}