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

		// �湮 �ȵǾ� �ִ� leaf ���� �湮
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
		// leaf ��� q�� �߰�
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

			// bud�� ã�Ƽ� bud�� leaf���� �湮
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

			// ���� ���� ���ܵ� �߰�
			if (q.empty())
			{
				for (int i = 0; i < n; i++)
				{
					if (indegree[i] == 1)
						q.push(i);
				}
			}
		}

		// �湮�ȵ� ���� ���� �߰�
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

// indegree == 1 �̳� ������ �ֵ��� �̹� �� visited �Ǿ� �ִ�.