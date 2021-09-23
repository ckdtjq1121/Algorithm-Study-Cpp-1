#include<bits/stdc++.h>

using namespace std;

int n;
char board[26][26];

int find(int y, int x)
{
	if (y < 0 || y >= n || x < 0 || x >= n)
		return 0;

	if (board[y][x] == '0')
		return 0;

	board[y][x] = '0';

	return find(y + 1, x) + find(y - 1, x) + find(y, x + 1) + find(y, x - 1) + 1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// input
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}


	// cnt group
	int cnt = 0;
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// measure group size
			int ret = find(i, j); // dfs group find

			if (ret != 0)
			{
				ans.push_back(ret);
				cnt++;
			}
		}
	}

	// sort group size
	sort(ans.begin(), ans.end());

	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
}