#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int> > edge;
// discovered[i] : i가 발견된 순서
// finished[i] : i가 종료 했으면  1, 아니면 0
vector<int> discovered, finished;
int cnt;
bool isthereCycle;
void dfs(int here)
{
	discovered[here] = cnt++;

	for (int i = 0; i < edge[here].size(); i++)
	{
		int there = edge[here][i];
		cout << here << ", " << there << " : ";
		if (discovered[there] == -1)
		{
			cout << "tree edge\n";
			dfs(there);
		}
		else if (discovered[here] < discovered[there])
			cout << "forward E\n";
		else if (!finished[there]) // there 이 아직 안끝났다
		{
			cout << "backward E\n";
			isthereCycle = true;
		}
		else
			cout << "cross E\n";

	}

	finished[here] = 1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	cin >> n >> m;
	edge = vector<vector<int> >(n);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;

		edge[u].push_back(v);
		//edge[v].push_back(u);
	}

	discovered = vector<int>(n, -1);
	finished = vector<int>(n, 0);
	cnt = 0;
	isthereCycle = false;
	dfs(0);

	if (isthereCycle)
		cout << "is there Cycle \n";
}