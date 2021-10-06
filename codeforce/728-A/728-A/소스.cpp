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

		if (n % 2 == 1)
		{
			cout << 3 << " " << 1 << " " << 2 << " ";
			for (int i = 4; i + 1 <= n; i += 2)
			{
				cout << i + 1 << " " << i << " ";
			}
			cout << "\n";
		}
		else
		{
			for (int i = 1; i + 1 <= n; i += 2)
			{
				cout << i + 1 << " " << i << " ";
			}
			cout << "\n";
		}
		
	}
}