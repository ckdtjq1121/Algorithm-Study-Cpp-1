#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1000001;
ll arr[MAX];
ll tree[MAX * 4];

ll init(int node, int start, int end)
{
	if (start == end)	
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = 
init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

// idx번째 값을 value 로 update
void update(int node, int start, int end, int idx, ll diff)
{
	if (idx < start || end < idx)	// 범위 밖 update X
		return;

	tree[node] += diff;

	if (start == end)
		return;

	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, diff);
	update(2 * node + 1, mid + 1, end, idx, diff);
}

// left, right 사이 idx의 구간 합 구하기
ll query(int node, int start, int end, int left, int right)
{
	if (end < left || right < start)	// 범위 밖 0
		return 0;

	if (left <= start && end <= right)	// left, right 사이의 구간
		return tree[node];

	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) + query(2 * node + 1, mid + 1, end, left, right);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	init(1, 1, n);

	int a, b;
	ll c;
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)		// init 뿐만 아니라 diff를 구할때 arr에 접근을 하므로 update시 arr 값을 변경 해줘야 한다................
		{
			ll diff = c - arr[b];
			arr[b] = c;
			update(1, 1, n, b, diff);
		}
		else if (a == 2)
			cout << query(1, 1, n, b, c) << "\n";
	}
	return 0;
}

