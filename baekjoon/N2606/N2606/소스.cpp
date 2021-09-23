#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	int m;
	cin >> m;
	
	vector<vector<int> > edge(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	vector<bool> visited(n + 1, false);
	stack<int> s; // dfs
	s.push(1);

	while (!s.empty())
	{
		int u = s.top();
		s.pop();

		visited[u] = true;
		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			
			if (!visited[v])
				s.push(v);
		}
	}

	int ans = -1;
	for (int i = 0; i < n + 1; i++)
	{
		if (visited[i])
			ans++;
	}

	cout << ans << "\n";
}
