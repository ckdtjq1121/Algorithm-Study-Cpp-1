#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<int> indegree;
vector<bool> visited;
vector<vector<int> > edge;

void visitAdj(int u)
{
	visited[u] = true;
	for (int i = 0; i < edge[u].size(); i++)
	{
		int v = edge[u][i];

		// 방문 안되어 있는 leaf 노드들 방문
		visited[v] = true;

		indegree[u]--;
		indegree[v]--;
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		cin >> n >> m;

		indegree = vector<int>(n, 0);
		edge = vector<vector<int> >(n);
		visited = vector<bool>(n);
		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			edge[u].push_back(v);
			edge[v].push_back(u);

			indegree[u]++;
			indegree[v]++;
		}

		queue<int> q;
		// leaf 노드 q에 추가
		for (int i = 0; i < n; i++)
		{
			if (indegree[i] == 1)
				q.push(i);
		}

		int ans = 0;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			if (indegree[u] != 1)
				continue;

			// bud를 찾아서 bud의 leaf들을 방문
			for (int i = 0; i < edge[u].size(); i++)
			{
				int v = edge[u][i];
				if (!visited[v])
				{
					//cout << u << " " << v << "\n";
					visitAdj(v);
					ans++;
					break;
				}
			}

			// 새로 생긴 말단들 추가
			if (q.empty())
			{
				for (int i = 0; i < n; i++)
				{
					if (indegree[i] == 1)
						q.push(i);
				}
			}
		}

		// 방문안된 단일 노드들 추가
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && indegree[i] == 0)
			{
				//cout << i << "\n";
				ans++;
			}
		}
		cout << ans << "\n";

	}
}

// indegree == 1 이나 인접한 애들이 이미 다 visited 되어 있다.