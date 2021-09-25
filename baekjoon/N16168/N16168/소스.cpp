// check euler circuit
#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > edge(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	vector<bool> visited(n + 1, false);
	// dfs
	stack<int> s;
	s.push(1);
	while (!s.empty())
	{
		int u = s.top();
		visited[u] = true;
		s.pop();

		for (int i = 0; i < edge[u].size(); i++)
		{
			int v = edge[u][i];
			if (!visited[v])
				s.push(v);
		}
	}

	bool disconnected = false;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			disconnected = true;
			break;
		}
	}

	if (disconnected)
	{
		cout << "NO\n";
		return 0;
	}


	int odd = 0;
	for (int i = 1; i <= n; i++)
	{
		if (edge[i].size() % 2 == 1)
			odd++;
	}

	if (odd == 0 || odd == 2)
		cout << "YES\n";
	else
		cout << "NO\n";
}