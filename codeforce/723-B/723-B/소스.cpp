#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int x;
		cin >> x;
		// 111a + 11b
		if (x % 11 == 0 )
		{
			cout << "YES\n";
		}
		else
		{
			bool flag = false;
			for (int i = 0; i < 10; i++)
			{
				x -= 111;
				//cout << x % 11 << " ";
				if (x >= 0 && x % 11 == 0)
				{
					//cout << x << " ";
					flag = true;
					break;
				}
			}

			if (flag)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}