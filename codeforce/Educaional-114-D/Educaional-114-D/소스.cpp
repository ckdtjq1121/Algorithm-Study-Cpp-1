#include <bits/stdc++.h>

using namespace std;

int main()		// 374ms
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	// input
	int n;
	cin >> n;
	vector<vector<int> > slot(n);
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		slot[i].resize(c);
		for (int j = 0; j < c; j++)
			cin >> slot[i][j];
	}
	int m;
	cin >> m;
	vector<vector<int> > banned(m);
	for (int i = 0; i < m; i++)
	{
		banned[i].resize(n);
		for (int j = 0; j < n; j++)
		{
			cin >> banned[i][j];
			banned[i][j]--;
		}
	}

	sort(banned.begin(), banned.end());

	// if not banned max
	vector<int> tmp(n);
	for (int i = 0; i < n; i++)
		tmp[i] = int(slot[i].size()) - 1;

	if (!binary_search(banned.begin(), banned.end(), tmp))
	{
		for (int i = 0; i < n; i++)
			cout << tmp[i] + 1 << " ";
		cout << "\n";
		return 0;
	}

	// find max among ways that smaller than banned build
	int mx = 0;
	vector<int> ans(n, -1);
	for (int i = 0; i < m; i++)
	{
		tmp = banned[i];
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			sum += slot[j][tmp[j]];
		}

		for (int j = 0; j < n; j++)
		{
			if (tmp[j] != 0)
			{
				tmp[j]--;

				if (!binary_search(banned.begin(), banned.end(), tmp) && sum - slot[j][tmp[j] + 1] + slot[j][tmp[j]] > mx)
				{
					mx = sum - slot[j][tmp[j] + 1] + slot[j][tmp[j]];
					ans = tmp;
				}
				tmp[j]++;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
		cout << ans[i] + 1 << " ";
	cout << "\n";

	// bruteforce find max - if not banned max value return else max of that smaller than banned list 
	// banned list find binary searching
}