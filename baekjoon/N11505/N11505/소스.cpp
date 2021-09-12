#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1000001;
const int MOD = 1000000007;
ll arr[MAX];
ll* tree;
ll init(int node, int start, int end)
{
	if (start == end) // base node
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	ll leftNode = init(2 * node, start, mid) % MOD;
	ll rightNode = init(2 * node + 1, mid + 1, end) % MOD;
	return tree[node] = leftNode * rightNode % MOD;
}

ll update(int node, int start, int end, int idx, int value)
{
	if (idx < start || end < idx) // out of range
		return tree[node];

	if (start == end && start == idx) // End of recursive
		return tree[node] = arr[idx] = value;

	int mid = (start + end) / 2;
	ll leftNode = update(2 * node, start, mid, idx, value);
	ll rightNode = update(2 * node + 1, mid + 1, end, idx, value);
	return tree[node] = leftNode * rightNode % MOD;
}

ll query(int node, int start, int end, int left, int right)
{
	if (end < left || right < start)	// out of range
		return 1;

	if (left <= start && end <= right)	// in of range
		return tree[node];

	int mid = (start + end) / 2;
	ll leftNode = query(2 * node, start, mid, left, right) % MOD;
	ll rightNode = query(2 * node + 1, mid + 1, end, left, right) % MOD;
	return leftNode * rightNode % MOD;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int height = ceil(log2(n));
	tree = new ll[1 << (height + 1)];

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	init(1, 1, n);

	int a, b, c;
	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, 1, n, b, c);	// tree[node]가 0일 때를 잘 고려할 것
		}
		else if (a == 2)
		{
			cout << query(1, 1, n, b, c) << "\n";
		}
	}
}