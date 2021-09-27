#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int> > edge(m);
	vector<vector<int> > e(n + 1);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		edge[i].first = u;
		edge[i].second = v;
		e[u].push_back(v);
	}

	for (int i = 0; i < m; i++)
	{
		vector<int> dist(n + 1, INF);
		priority_queue<pair<int, int> > pq;
		pq.push({ 0, 1 });
		dist[1] = 0;

		while (!pq.empty())
		{
			int here = pq.top().second;

			pq.pop();

			int banu = edge[i].first;
			int banv = edge[i].second;
			for (int j = 0; j < e[here].size(); j++)
			{
				int next = e[here][j];

				if (here == banu && next == banv)
					continue;

				if (dist[next] > dist[here] + 1)
				{
					dist[next] = dist[here] + 1;
					pq.push({ -dist[next], next });
				}
			}
		}

		if (dist[n] != INF)
			cout << dist[n] << "\n";
		else
			cout << -1 << "\n";
	}
}