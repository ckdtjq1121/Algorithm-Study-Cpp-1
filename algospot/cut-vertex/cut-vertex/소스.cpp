#include<bits/stdc++.h>

using namespace std;
int n, m;
vector<vector<int> > edge;
vector<int> discovered;
vector<bool> isCutVertex;
int cnt;

int findCutVertex(int here, bool isRoot)
{
	discovered[here] = cnt++;
	int ret = discovered[here];

	int children = 0;
	for (int i = 0; i < edge[here].size(); i++)
	{
		int there = edge[here][i];
		if (discovered[there] == -1)
		{
			children++;

			int subtree = findCutVertex(there, false);j

			if (!isRoot && subtree >= discovered[there])
				isCutVertex[here] = true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[there]);
	}

	if (isRoot)
		isCutVertex[here] = (children >= 2);

	return ret;
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
		edge[v].push_back(u);
	}

	discovered = vector<int>(n, -1);
	cnt = 0;
	

}