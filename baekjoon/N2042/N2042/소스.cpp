#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAX = 1000001;
ll arr[MAX];
ll* psum;

ll init(int left, int right, int node)
{
	if (left == right)
		return psum[node] = arr[left];

	int mid = (left + right) / 2;
	return psum[node] = init(left, mid, 2 * node) + init(mid + 1, right, 2 * node + 1);
}

// n번째 값을 after로 update 하기
void update(int left, int right, int node, int n, ll diff)
{
	if (n < left || right < n)
		return;

	psum[node] += diff;

	if (left != right)
	{
		int mid = (left + right) / 2;
		update(left, mid, 2 * node, n, diff);
		update(mid + 1, right, 2 * node + 1, n, diff);
	}
}

// left , right 사이에 대해서 start, end의 구간합 구하기 -- Sum[start, end]
ll query(int left, int right, int node, int start, int end)
{
	if (end < left || right < start)
		return 0;

	if (start <= left && right <= end)
	{
		//cout << start << " " << end << "   " << left << " " << right << "   " << psum[node] << endl;
		return psum[node];
	}

	int mid = (left + right) / 2;
	return query(left, mid, 2 * node, start, end) + query(mid + 1, right, 2 * node + 1, start, end);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	int height = ceil(log2(n));
	psum = new ll[1 << (height + 1)];
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	init(1, n, 1);

	for (int i = 0; i < m + k; i++)
	{
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			int index = b;
			ll value = c;
			ll diff = value - arr[index];
			update(1, n, 1, index, diff);
		}
		else if (a == 2)
		{
			cout << query(1, n, 1, b, c) << endl;
		}
	}
}

