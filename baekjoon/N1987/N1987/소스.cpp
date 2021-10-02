#include<bits/stdc++.h>

using namespace std;


int r, c;
vector<vector<char> > grid;
vector<vector<int> > dist;
int dfs(int y, int x, vector<bool> visitedA)
{
	if (r <= y || y < 0 || c <= x || x < 0|| visitedA[grid[y][x] - 'A'])
		return 0;

	visitedA[grid[y][x] - 'A'] = true;
	int ret = 0;

	int a = 0;
	a = max(dfs(y + 1, x, visitedA), dfs(y, x + 1, visitedA));
	int b = 0;
	b = max(dfs(y - 1, x, visitedA), dfs(y, x - 1, visitedA));
	return ret = max(a, b) + 1;
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
	cout << dfs(0, 0, vector<bool>(26, false)) << "\n";
}