#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<pair<int, int>, int> > edge(m);
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		u--, v--;
		edge[i].first.first = u;
		edge[i].first.second = v;
		edge[i].second = c;
	}

	vector<long long> dist(n, INT_MAX);
	dist[0] = 0;

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int u = edge[j].first.first;
			int v = edge[j].first.second;
			int c = edge[j].second;

			if (dist[u] == INT_MAX)
				continue;

			if (dist[v] > dist[u] + c)
			{
				dist[v] = dist[u] + c;
			}
		}
	}

	bool istherecycle = 0;
	for (int i = 0; i < m; i++)
	{
		int u = edge[i].first.first;
		int v = edge[i].first.second;
		int c = edge[i].second;

		if (dist[u] == INT_MAX)
			continue;
		if (dist[v] > dist[u] + c)
			istherecycle = 1;
	}

	if (istherecycle)
		cout << "-1\n";
	else 
	{
		for (int i = 1; i < n; i++) 
		{
			if (dist[i] == INT_MAX) 
				cout << "-1\n";
			else 
				cout << dist[i] << "\n";
		}
	}
}