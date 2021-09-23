#include<bits/stdc++.h>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, v;
	cin >> n >> m >> v;

	vector<vector<int> > edge(n+1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	// 작은 정점부터 탐색을 위한 정렬
	for (int i = 0; i < n + 1; i++)
		sort(edge[i].begin(), edge[i].end());

	// dfs - stack
	vector<bool> visited(n+1, false);
	stack<int> s;
	s.push(v);
	while (!s.empty())
	{
		int u = s.top();
		s.pop();
		if (visited[u])
			continue;

		visited[u] = true;

		cout << u << " ";

		for (int i = edge[u].size()-1; i >= 0; i--)
		{
			s.push(edge[u][i]);
		}
	}
	cout << endl;

	// bfs - queue
	for (int i = 0; i < n + 1; i++)
		visited[i] = false;

	queue<int> q;
	q.push(v);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (visited[u])
			continue;

		visited[u] = true;

		cout << u << " ";

		for (int i = 0; i < edge[u].size(); i++)
		{
			q.push(edge[u][i]);
		}
	}
	cout << endl;

}