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

		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		vector<int> b(n);
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}


		int ans = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (b[i] > a[j])
					ans = min(ans, i + j);
			}
		}

		cout << ans << "\n";
		
	}
}
