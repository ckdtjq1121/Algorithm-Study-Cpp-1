#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<pair<int, int> > value;
vector<vector<int> > edge;
vector<bool> visited;

ll dfs(int u, int val)
{
	visited[u] = true;

	ll ret = 0;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];

		if (!visited[v])
		{
			if (abs(val - value[v].first) > abs(val - value[v].second))
				ret += dfs(v, value[v].first) + abs(val - value[v].first);
			else
				ret += dfs(v, value[v].second) + abs(val - value[v].second);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;

		value = vector<pair<int, int> >(n);
		for (int i = 0; i < n; i++)
		{
			int l, r;
			cin >> l >> r;

			value[i] = { l, r };
		}

		edge = vector<vector<int> >(n);
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		visited = vector<bool>(n, false);
		ll a = dfs(0, value[0].first);

		visited = vector<bool>(n, false);
		ll b = dfs(0, value[0].second);

		cout << max(a, b) << "\n";
	}
}
