#include<bits/stdc++.h>

using namespace std;
int n;
vector<vector<bool> > visited;
vector<vector<int> > grid;
int direct[4][2] = {

	{-1, 0},
	{0, -1},
	{0, 1},
	{1, 0},
};
int dfs(int y, int x, int rain)
{
	visited[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + direct[i][0], nextX = x + direct[i][1];
		if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n
			&& !visited[nextY][nextX] && grid[nextY][nextX] > rain)
			dfs(nextY, nextX, rain);
	}

	return 0;
}

int dfsAll(int rain)
{
	visited = vector<vector<bool> >(n);
	for (int i = 0; i < n; i++)
	{
		visited[i] = vector<bool>(n, false);
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && grid[i][j] > rain)
			{
				dfs(i, j, rain);
				ret++;
			}
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	grid = vector<vector<int> >(n);
	for (int i = 0; i < n; i++)
	{
		grid[i] = vector<int>(n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
		}
	}

	int ans = 1;
	for (int i = 0; i <= 100; i++)
		ans = max(ans, dfsAll(i));

	cout << ans << "\n";

}