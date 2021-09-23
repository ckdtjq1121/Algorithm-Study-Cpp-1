#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	int pre[20001][20001];
	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;
		
		bool impossible = true;
		vector<vector<int> > pre(n+1);
		for (int i = 1; i <= n; i++)
		{
			int k;
			cin >> k;

			if (!k)
				impossible = false;
			int tmp;
			for (int j = 0; j < k; j++)
			{
				cin >> tmp;
				pre[i].push_back(tmp);
			}
		}

		if (impossible)
		{
			cout << -1 << "\n";
			continue;
		}


		vector<bool> understand(n + 1, false);
		for (int i = 0; i < n; i++)
		{
			if (pre[i].size() == 0)
				understand[i] = true;


		}

		
		else
			cout << " " << "\n";
	}
}
