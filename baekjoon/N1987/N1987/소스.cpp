#include<bits/stdc++.h>

using namespace std;

int r, c;
vector<vector<char> > grid;
vector<bool> visited;
int dfs(int y, int x)
{
	if (r <= y || y < 0 || c <= x || x < 0|| visited[grid[y][x] - 'A'])
		return 0;

	visited[grid[y][x] - 'A'] = true;
	int ret = 0;

	int a, b, c, d;
	a = dfs(y + 1, x);
	b = dfs(y, x + 1);
	c = dfs(y - 1, x);
	d = dfs(y, x - 1);

	ret = max(ret, a);
	ret = max(ret, b);
	ret = max(ret, c);
	ret = max(ret, d);

	visited[grid[y][x] - 'A'] = false;
	return ret + 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> r >> c;
	
	grid = vector<vector<char> >(r);
	for (int i = 0; i < r; i++)
	{
		grid[i] = vector<char>(c);
		for (int j = 0; j < c; j++)
		{
			cin >> grid[i][j];
		}
	}

	visited = vector<bool>(26);
	cout << dfs(0, 0) << "\n";

}