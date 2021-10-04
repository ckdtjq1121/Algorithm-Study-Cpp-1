// Kruskal's algorithm - minimum spanning tree

#include<bits/stdc++.h>

using namespace std;
int n;
// union find
vector<int> parent;
int find(int x)
{
	if (x == parent[x])
		return x;

	return parent[x] = find(parent[x]);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<pair<int, pair<int, int> > > edge;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		edge.push_back({ w,{u, v} });
	}

	sort(edge.begin(), edge.end());

	parent = vector<int>(n);
	for (int i = 0; i < n; i++)
		parent[i] = i;

	int ans = 0;
	vector<bool> visited(n, false);
	for (int i = 0; i < m; i++)
	{
		int u = edge[i].second.first;
		int v = edge[i].second.second;
		int w = edge[i].first;
		
		int pu = find(u);
		int pv = find(v);
		// don't get cycle
		if (pu != pv)
		{
			ans += w;
			parent[pu] = pv;
		}
	}

	cout << ans << "\n";
}