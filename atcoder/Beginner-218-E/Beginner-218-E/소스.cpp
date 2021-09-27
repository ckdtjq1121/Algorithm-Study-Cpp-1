#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<pair<int, pair<int, int> > > edge(m);
	vector<int> indegree(n+1, 0);
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		edge[i] = make_pair(c, make_pair(u, v));

		indegree[u]++;
		indegree[v]++;
	}

	sort(edge.begin(), edge.end(), greater<>());

	int ans = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v, c;
		u = edge[i].second.first;
		v = edge[i].second.second;
		c = edge[i].first;

		if (indegree[u] > 1 && indegree[v] > 1)
		{
			indegree[u]--;
			indegree[v]--;

			ans += c;
		}
	}

	cout << ans << "\n";
}