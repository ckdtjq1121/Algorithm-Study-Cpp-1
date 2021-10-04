#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 200001;
int n;
vector<vector<int> > edge;
vector<int> dist;
vector<int> discovered;
vector<int> parent;
vector<int> numOfChild;
int cnt;
int dfs(int here)
{
	discovered[here] = cnt++;

	int c = 0;
	for (int i = 0; i < edge[here].size(); i++)
	{
		int there = edge[here][i];

		if (discovered[there] == -1)
		{
			parent[there] = here;
			dist[there] = dist[here] + 1;
			c += dfs(there) + 1;
		}
	}
	
	return numOfChild[here] = c;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;
	
	edge = vector<vector<int> >(n);		
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	// 0���� ������ distance
	dist = vector<int>(n, INF);
	dist[0] = 0;

	// �߰ߵ� ����
	discovered = vector<int>(n, -1);
	cnt = 0; // �߰߼��� ī����

	// �θ� idx
	parent = vector<int>(n);
	parent[0] = 0;

	// �ڽ��� ��
	numOfChild = vector<int>(n, 0);
	dfs(0);		

	// sum of dist
	vector<ll> sum(n, 0);
	for (int i = 1; i < n; i++)
		sum[0] += (long long)dist[i];

	// �߰� ������� sort
	vector<pair<int, int> > seq(n);
	for (int i = 0; i < n; i++)
	{
		seq[i].first = discovered[i];
		seq[i].second = i;
	}
	sort(seq.begin(), seq.end());

	// �߰� ������� calc sum of dist 
	for (int i = 1; i < n; i++)
	{
		int v = seq[i].second;

		// �ڽĵ��� dist--, �ڽĵ� + ���� + �θ��� �� ������ ����� dist++;
		// sum[v] = sum[parent[v]] - numbOfChild[v] + (n - numOfChild[v] - 2);
		sum[v] = sum[parent[v]] + n - (ll)2 * numOfChild[v] - 2; 
		
	}

	for (int i = 0; i < n; i++)
		cout << sum[i] << "\n";
}