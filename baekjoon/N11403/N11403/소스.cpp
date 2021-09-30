#include<bits/stdc++.h>

using namespace std;

int n;
vector<vector<int> > adj;
vector<bool> visited;
vector<bool> ans;
void dfs(int here)
{
	visited[here] = true;

	for (int i = 0; i < adj[here].size(); i++)
	{
		int there = adj[here][i];
		ans[there] = true;
		if (!visited[there])
		{
			dfs(there);
		}
	}
}
void dfsAll()
{
	for (int i = 0; i < n; i++)
	{
		visited = vector<bool>(n, false);
		ans = vector<bool>(n, false);
		if (!visited[i])
		{
			dfs(i);	
		}

		for (int j = 0; j < n; j++)
			cout << ans[j] << " ";
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	adj = vector<vector<int> >(n);

	int tmp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> tmp;
			if (tmp == 1)
			{
				adj[i].push_back(j);
			}
		}
	}

	dfsAll();
}