#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<char> > grid(n);
	vector<vector<bool> > visited(n);
	for (int i = 0; i < n; i++)
	{
		grid[i] = vector<char>(m);
		visited[i] = vector<bool>(m, false);
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}
	
	queue<pair<pair<int, int>, int> > q;
	q.push({ {0, 0}, 0 });


	int dy[4] = { 0, 0, 1, -1 };
	int dx[4] = { 1, -1, 0, 0 };
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int block = q.front().second;
		q.pop();

		visited[y][x] = true;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= nx && nx < m && 0 <= ny && ny < n)
			{

			}
		}
	}
}