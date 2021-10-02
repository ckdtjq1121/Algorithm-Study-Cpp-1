#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> d(n+1);
		for (int i = 1; i <= n; i++)
			cin >> d[i];

		vector<vector<int> > edge(n+1);
		vector<int> indegree(n+1, 0);
		for (int i = 0; i < k; i++)
		{
			int u, v;
			cin >> u >> v;

			edge[u].push_back(v);
			indegree[v]++;
		}
		vector<int> ans(n+1, 0);
		queue<int> q;
		for (int i = 1; i <= n; i++)
		{
			if (indegree[i] == 0)
			{
				q.push(i);
				ans[i] = d[i];
			}
		}

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			for (int i = 0; i < edge[u].size(); i++)
			{
				int v = edge[u][i];
				indegree[v]--;
				
				// v를 짓는대 필요한 시간
				ans[v] = max(ans[v], d[v] + ans[u]);
				// 선행 건물을 다 지엇을 경우 지을 수 있다
				if (indegree[v] == 0)
					q.push(v);
			}
		}

		int last;
		cin >> last;

		cout << ans[last] << "\n";
	}
}