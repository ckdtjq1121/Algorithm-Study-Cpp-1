#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int M = 98765432;

int V, E;

vector<vector<pair<int, int>>> adj;

bool reachable[101][101];

int bellmanford()
{
	for (int k = 0; k < V; k++)
		for (int i = 0; i < V; i++)
			for (int j = 0; j < V; j++)
				reachable[i][j] |= reachable[i][k] && reachable[k][j];

	vector<int> upper(V, INF);

	upper[0] = 0;
	bool updated;

	bool cycle = false;

	for (int i = 0; i < V; i++)
	{
		updated = false;

		for (int here = 0; here < V; here++)
		{
			if (upper[here] == INF)
				continue;

			for (size_t j = 0; j < adj[here].size(); j++)
			{
				int there = adj[here][j].first;
				int w = adj[here][j].second;

				if (upper[there] > upper[here] + w)
				{
					if (i == V - 1 && (reachable[there][1] || reachable[here][1]))
						cycle = true;
					upper[there] = upper[here] + w;
					updated = true;
				}
			}
		}

		if (!updated)
			break;
	}

	if (upper[1] == INF) // why INF - M : 987654321 -98765432
		return -INF;

	if (cycle)
		return INF;

	return upper[1];
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		cin >> V >> E;

		adj.clear();
		adj.resize(V);

		memset(reachable, false, sizeof(reachable));
		for (int i = 0; i < V; i++)
			reachable[i][i] = true;

		for (int i = 0; i < E; i++)
		{
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({ v, w });
			reachable[u][v] = true;
		}

		int past = bellmanford();

		if (past == -INF)
		{
			cout << "UNREACHABLE" << "\n";
			continue;
		}

		if (past == INF)
			cout << "INFINITY ";
		else
			cout << past << " ";

		for (size_t i = 0; i < V; i++)
			for (size_t j = 0; j < adj[i].size(); j++)
				adj[i][j].second = -adj[i][j].second;

		int present = bellmanford();
		if (present == INF)
			cout << "INFINITY\n";
		else
			cout << -present << "\n";

	}
	return 0;
}