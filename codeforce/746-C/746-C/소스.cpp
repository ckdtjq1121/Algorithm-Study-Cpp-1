#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> discoverd;
vector<vector<int> > edge;
vector<bool> visited;
vector<int> x;

int cnt;
int dfs(int here)
{
	discoverd[here] = cnt++;

	for (int i = 0; i < edge[here].size(); i++)
	{
		int there = edge[here][i];

		if (discoverd[there] == -1)
		{
			dfs(there);
		}
	}

	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		edge = vector<vector<int> >(n);
		for (int i = 0; i < n-1; i++)
		{
			int u, v;
			cin >> u >> v;
			u--;
			v--;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}

		discoverd = vector<int>(n, -1);
		cnt = 0;
		dfs(0);

		vector<pair<int, int> > seq(n);
		for (int i = 0; i < n; i++)
		{
			seq[i].first = discoverd[i];
			seq[i].second = i;
		}
		sort(seq.begin(), seq.end());

		vector<int> x(n);
		x[0] = arr[0];
		for (int i = 1; i < n; i++)
		{
			x[i] = x[i - 1] ^ arr[seq[i].second];
		}

		int last = x[n - 1];
		int a = 0, b = 0;
		for (int i = 0; i < n; i++)
		{
			if (x[i] == last)
				a++;
			else if (x[i] == 0)
				b++;
		}
		if (last == 0)
			cout << "YES\n";
		else if (b > 0 && a + b <= k)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}