#include<bits/stdc++.h>

using namespace std;
int h, w;
vector<vector<bool> > visited;
int grid[51][51];
int direct[8][2] = {
	{-1, -1},
	{-1, 0},
	{-1, 1},
	{0, -1},
	{0, 1},
	{1, -1},
	{1, 0},
	{1, 1}
};
int dfs(int y, int x)
{
	visited[y][x] = true;

	for (int i = 0; i < 8; i++)
	{
		int nextY = y + direct[i][0], nextX = x + direct[i][1];
		if (nextY >= 0 && nextY < h && nextX >= 0 && nextX < w
			&& !visited[nextY][nextX] && grid[nextY][nextX] == 1)
			dfs(nextY, nextX);
	}

	return 0;
}

int dfsAll()
{
	visited = vector<vector<bool> >(h);
	for (int i = 0; i < h; i++)
	{
		visited[i] = vector<bool>(w, false);
	}

	int ret = 0;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (!visited[i][j] && grid[i][j] == 1)
			{
				dfs(i, j);
				ret++;
			}
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0)
			break;

		
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> grid[i][j];
			}
		}

		cout << dfsAll() << "\n";
	}
}