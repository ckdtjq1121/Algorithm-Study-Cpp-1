#include<bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int INF = 2147483647;

int arr[MAX];
vector<pair<int, int> > tree(4 * MAX);

pair<int, int> init(int node, int start, int end)
{
	if (start == end)
		return tree[node] = make_pair(arr[start], arr[end]);

	int mid = (start + end) / 2;
	pair<int, int> leftNode = init(2 * node, start, mid);
	pair<int, int> rightNode = init(2 * node + 1, mid + 1, end);
	return tree[node] = make_pair(min(leftNode.first, rightNode.first), max(leftNode.second, rightNode.second));
}

pair<int, int> query(int node, int start, int end, int left, int right)
{
	if (end < left || right < start)
		return make_pair(INF, -INF);

	if (left <= start && end <= right)
		return tree[node];

	int mid = (start + end) / 2;
	pair<int, int> leftNode = query(2 * node, start, mid, left, right);
	pair<int, int> rightNode = query(2 * node + 1, mid + 1, end, left, right);
	return make_pair(min(leftNode.first, rightNode.first), max(leftNode.second, rightNode.second));
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, q;
	cin >> n >> q;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	init(1, 1, n);

	for (int i = 0; i < q; i++)
	{
		int a, b;
		cin >> a >> b;
		pair<int, int> ans = query(1, 1, n, a, b);
		printf("%d %d\n", ans.first, ans.second);
	}
}
// cin이 scanf보다 빠르다
// cout이 printf보다 느리다