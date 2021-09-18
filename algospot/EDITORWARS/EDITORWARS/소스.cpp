#include<bits/stdc++.h>

using namespace std;

const int MAX = 10000;

vector<int> root(MAX);// pair <parent, rank>
vector<int> unionsize(MAX);

// 조상 찾기
int find(int u)
{
	// 부모가 자기 자신일 경우 u는 조상
	if (root[u] == u)
		return u;
	// 아닐경우 부모의 조상을 찾아 자신의 부모로 함
	else
		return root[u] = find(root[u]);
}
// v에 u추가
void merge(int u, int v)
{
	// 조상 찾기
	int uRoot = find(u);
	int vRoot = find(v);

	if (uRoot == vRoot)
		return;

	// u의 조상을 v의 조상으로 함
	root[uRoot] = vRoot;
	// v union 에 u union 을 합치며 크기를 늘림
	unionsize[vRoot] += unionsize[uRoot];

	//cout << v << " " << unionsize[v] << "    " << u << " " << unionsize[u] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;
	for (; testCase > 0; testCase--)
	{
		int n, m;
		cin >> n >> m;

		// init
		vector<int> dis(n);
		for (int i = 0; i < n; i++)
			dis[i] = i;

		for (int i = 0; i < n; i++)
			root[i] = i;

		for (int i = 0; i < n; i++)
			unionsize[i] = 1;

		// input
		vector<string> type(m);
		vector<int> u(m);
		vector<int> v(m);
		for (int i = 0; i < m; i++)
		{
			cin >> type[i] >> u[i] >> v[i];
		}

		int contradiction = 0;
		for (int i = 0; i < m; i++)
		{
			int uRoot = find(u[i]);
			int vRoot = find(v[i]);

			// type is ACK
			if (type[i][0] == 'A')
			{
				// CONTRADICTION
				if (dis[uRoot] == vRoot || uRoot == dis[vRoot])
				{
					contradiction = i + 1;
					break;
				}

				if (uRoot != vRoot)
					merge(uRoot, vRoot);

				if (dis[uRoot] != dis[vRoot])
					merge(dis[uRoot], dis[vRoot]);
			}

			// type is DIS
			if (type[i][0] == 'D')
			{
				// CONTRADICTION
				if (uRoot == vRoot)
				{
					contradiction = i + 1;
					break;
				}

				// 둘다 상대편이 없는 경우 상대편을 지정
				if (dis[uRoot] == uRoot && dis[vRoot] == vRoot)
				{
					dis[uRoot] = vRoot;
					dis[vRoot] = uRoot;
				}
				// 한쪽만 상대편이 있는 경우
				else if (dis[uRoot] == uRoot)
				{
					merge(uRoot, dis[vRoot]);
				}
				else if (dis[vRoot] == vRoot)
				{
					merge(vRoot, dis[uRoot]);
				}
			}
		}

		if (contradiction)
		{
			cout << "CONTRADICTION AT " << contradiction << "\n";
			continue;
		}
		int ans = 0;
		vector<bool> checked(n, false);
		for (int i = 0; i < n; i++)
		{
			int u = find(i); // i의 조상
			int v = find(dis[u]); // i 조상의 대립

			// 조상 일때 조상 유니온의 크기와 대립 유니온의 크기중 작은 것
			if (!checked[u] && !checked[v])
			{
				checked[u] = true;
				checked[v] = true;
				ans += min(unionsize[u], unionsize[v]);

				cout << u << " " << unionsize[u] << "   " << v << " " << unionsize[v] << "\n";
			}
		}

		//cout << n - ans << " " << ans << "\n";
		ans = max(n - ans, ans);

		cout << "MAX PARTY SIZE IS " << ans << "\n";
	}
}


// dis[i] = i // init 변경 필요