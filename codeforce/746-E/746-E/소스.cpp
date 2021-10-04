#include<bits/stdc++.h>

using namespace std;
vector<int> arr;
vector<int> tree;
int init(int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(2 * node, start, mid) & init(2 * node + 1, mid + 1, end);
}

int query(int node, int start, int end, int left, int right)
{
	if (end < left || right < start)
		return INT_MAX;

	if (left <= start && end <= right)
	{
		//cout << left << " " <<right << " " << start << " " << right << " " << tree[node] << "t\n";
		return tree[node];
	}

	int mid = (start + end) / 2;
	return query(2 * node, start, mid, left, right) & query(2 * node + 1, mid + 1, end, left, right);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	arr = vector<int>(n+1);
	arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	vector<pair<int, int> > pxor(n + 1);
	pxor[0].first = 0;
	pxor[0].second = 0;
	for (int i = 1; i <= n; i++)
	{
		pxor[i].first = pxor[i - 1].first ^ arr[i];
		pxor[i].second = i;
	}

	sort(pxor.begin(), pxor.end());

	int height = ceil(log2(n));
	tree.resize(1 << (height + 1));
	init(1, 1, n);

	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = pxor[i].second;
		int r = pxor[i - 1].second;

		if (r < l)
			swap(r, l);
		int a, b; // a = xor, b = and
		a = pxor[i].first ^ pxor[i - 1].first;

		b = query(1, 1, n, l + 1, r);
		cout << l << " " << r << " " << a << " " << b << "\n";

		if (b > a)
		{
			ans = max(ans, r - l);
		}
	}


	cout << ans << "\n";
}
