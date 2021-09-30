#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<bool> visited;
void dfs(int here)
{
	visited[here] = true;

	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
		{
			dfs(there);
		}
	}
}
int dfsAll()
{
	visited = vector<bool>(n, false);
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(i);
			ret++;
		}
	}

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m;
	adj = vector<vector<int> >(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	cout << dfsAll() << "\n";
}