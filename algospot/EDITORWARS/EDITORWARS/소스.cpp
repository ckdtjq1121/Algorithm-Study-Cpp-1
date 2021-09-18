//#include<bits/stdc++.h>
//
//using namespace std;
//
//const int MAX = 10000;
//
//vector<int> root(MAX);// pair <parent, rank>
//vector<int> unionsize(MAX);
//
//// 조상 찾기
//int find(int u)
//{
//	// 부모가 자기 자신일 경우 u는 조상
//	if (root[u] == u)
//		return u;
//	// 아닐경우 부모의 조상을 찾아 자신의 부모로 함
//	else
//		return root[u] = find(root[u]);
//}
//// v에 u추가
//void merge(int u, int v)
//{
//	// 조상 찾기
//	int uRoot = find(u);
//	int vRoot = find(v);
//
//	if (uRoot == vRoot)
//		return;
//
//	// u의 조상을 v의 조상으로 함
//	root[uRoot] = vRoot;
//	// v union 에 u union 을 합치며 크기를 늘림
//	unionsize[vRoot] += unionsize[uRoot];
//
//	//cout << v << " " << unionsize[v] << "    " << u << " " << unionsize[u] << "\n";
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//
//	int testCase;
//	cin >> testCase;
//	for (; testCase > 0; testCase--)
//	{
//		int n, m;
//		cin >> n >> m;
//
//		// init
//		vector<int> dis(n);
//		for (int i = 0; i < n; i++)
//			dis[i] = i;
//
//		for (int i = 0; i < n; i++)
//			root[i] = i;
//
//		for (int i = 0; i < n; i++)
//			unionsize[i] = 1;
//
//		// input
//		vector<string> type(m);
//		vector<int> u(m);
//		vector<int> v(m);
//		for (int i = 0; i < m; i++)
//		{
//			cin >> type[i] >> u[i] >> v[i];
//		}
//
//		int contradiction = 0;
//		for (int i = 0; i < m; i++)
//		{
//			int uRoot = find(u[i]);
//			int vRoot = find(v[i]);
//
//			// type is ACK
//			if (type[i][0] == 'A')
//			{
//				// CONTRADICTION
//				if (dis[uRoot] == vRoot || uRoot == dis[vRoot])
//				{
//					contradiction = i + 1;
//					break;
//				}
//
//				if (uRoot != vRoot)
//					merge(uRoot, vRoot);
//
//				if (dis[uRoot] != dis[vRoot])
//					merge(dis[uRoot], dis[vRoot]);
//			}
//
//			// type is DIS
//			if (type[i][0] == 'D')
//			{
//				// CONTRADICTION
//				if (uRoot == vRoot)
//				{
//					contradiction = i + 1;
//					break;
//				}
//
//				// 둘다 상대편이 없는 경우 상대편을 지정
//				if (dis[uRoot] == uRoot && dis[vRoot] == vRoot)
//				{
//					dis[uRoot] = vRoot;
//					dis[vRoot] = uRoot;
//				}
//				// 한쪽만 상대편이 있는 경우
//				else if (dis[uRoot] == uRoot)
//				{
//					merge(uRoot, dis[vRoot]);
//				}
//				else if (dis[vRoot] == vRoot)
//				{
//					merge(vRoot, dis[uRoot]);
//				}
//			}
//		}
//
//		if (contradiction)
//		{
//			cout << "CONTRADICTION AT " << contradiction << "\n";
//			continue;
//		}
//		int ans = 0;
//		vector<bool> checked(n, false);
//		for (int i = 0; i < n; i++)
//		{
//			int u = find(i); // i의 조상
//			int v = find(dis[u]); // i 조상의 대립
//
//			// 조상 일때 조상 유니온의 크기와 대립 유니온의 크기중 작은 것
//			if (!checked[u] && !checked[v])
//			{
//				checked[u] = true;
//				checked[v] = true;
//				ans += min(unionsize[u], unionsize[v]);
//
//				cout << u << " " << unionsize[u] << "   " << v << " " << unionsize[v] << "\n";
//			}
//		}
//
//		//cout << n - ans << " " << ans << "\n";
//		ans = max(n - ans, ans);
//
//		cout << "MAX PARTY SIZE IS " << ans << "\n";
//	}
//}
//
//
//// dis[i] = i // init 변경 필요

#include<bits/stdc++.h>

using namespace std;

int N, M;

struct BipartiteUnionFind {
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) : parent(n), rank(n, 0), enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (parent[u] == u)
			return u;
		return parent[u] = find(parent[u]);
	}
	int merge(int u, int v)
	{
		if (u == -1 || v == -1) return max(u, v);

		u = find(u), v = find(v);

		if (u == v) return u;

		if (rank[u] > rank[v]) swap(u, v);

		if (rank[u] == rank[v]) rank[v]++;

		parent[u] = v;
		size[v] += size[u];
		return v;
	}

	bool dis(int u, int v)
	{
		u = find(u), v = find(v);

		if (u == v) return false;

		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b;
		enemy[b] = a;
		return true;
	}

	bool ack(int u, int v)
	{
		u = find(u), v = find(v);

		if (enemy[u] == v) return false;

		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;

		if (b != -1)
			enemy[b] = a;

		return true;
	}
};

int maxParty(const BipartiteUnionFind& buf)
{
	int ret = 0;
	for (int node = 0; node < N; node++)
	{
		if (buf.parent[node] == node) // 루트 노드만
		{
			int enemy = buf.enemy[node];

			// node 와  enemy의 관계를 한번만 계산하기 위해서
			if (enemy > node) continue;

			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);

			ret += max(mySize, enemySize);
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
		cin >> N >> M;

		BipartiteUnionFind buf(N);

		bool contradict = false; //모순
		int num = -1;

		for (int i = 0; i < M; i++)
		{
			string s;
			int node1, node2;

			cin >> s >> node1 >> node2;

			if (contradict)
				continue;


			if (s == "ACK")
			{
				if (!buf.ack(node1, node2)) //모순 발생할 경우
				{
					contradict = true;
					num = i + 1;
				}
			}

			else
			{
				if (!buf.dis(node1, node2)) //모순 발생할 경우
				{
					contradict = true;
					num = i + 1;
				}
			}
		}

		if (contradict)
			cout << "CONTRADICTION AT " << num << "\n";
		else
			cout << "MAX PARTY SIZE IS " << maxParty(buf) << "\n";
	}
}