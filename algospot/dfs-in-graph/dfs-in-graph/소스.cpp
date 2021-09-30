#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<bool> visited;
void dfs(int here)
{
	cout << "DFS visted " << here << "\n";

	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		if (!visited[there])
			dfs(there);
	}
}

void dfsAll()
{
	visited = vector<bool>(n, false);
	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs(i);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// input
	cin >> n >> m;
	adj = vector<vector<int> >(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u); // undirected G
	}

	// dfs
	dfsAll();
}