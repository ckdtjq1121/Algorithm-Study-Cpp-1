#include<bits/stdc++.h>

using namespace std;

int n;

vector<int> tree;
vector<int> ans;
vector<int> arr;

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);

	int tmp;
	while (b != 0)
	{
		tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int init(int node, int start, int end)
{
	if (start == end)
	{
		if (start < n)
			return tree[node] = arr[start];
		else
			return tree[node] = arr[n - 1];
	}

	int mid = (start + end) / 2;
	int left = init(2 * node, start, mid);
	int right = init(2 * node + 1, mid + 1, end);
	//cout << left << " " << right << "\n";
	return tree[node] = gcd(left, right);
}

int reinit(int node, int start, int end, int x)
{
	//cout << n << " " << start << " " << end << "\n";
	

	if (start == end)
	{
		if (n <= start)
			return tree[node] = x;
		else
			return tree[node] = arr[start];
	}

	int mid = (start + end) / 2;
	int left = reinit(2 * node, start, mid, x);
	int right = reinit(2 * node + 1, mid + 1, end, x);
	//cout << left << " " << right << "\n";
	return tree[node] = gcd(left, right);
}

int query(int node, int start, int end, int x)
{
	if (start == end)
		return ans[node] = 0;

	int mid = (start + end) / 2;


	int left = query(2 * node, start, mid, x);
	int right = query(2 * node + 1, mid + 1, end, x);

	cout << tree[2 * node] << " " << tree[2 * node + 1] << "    " << ans[2*node] << " " << ans[2*node+1] << " " << ans[node] << " n" << node << "\n";

	if (tree[2 * node] != x || tree[2 * node + 1] != x)
		return ans[node] = max(left, right) + 1;
	else
		return ans[node] = max(left, right);

}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		cin >> n;
		n++;
		arr.resize(n);
		for (int i = 1; i < n; i++)
		{
			cin >> arr[i];
		}
		arr[0] = arr[n - 1]; // 0: n - 1
		int height = ceil(log2(n));
		tree.resize(1 << (height + 1));
		ans.resize(1 << (height + 1));

		init(1, 0, tree.size() / 2 - 1);
		//reinit(1, 0, tree.size() / 2 - 1, arr[0]);

		query(1, 0, tree.size() / 2 - 1, tree[1]);
		cout << ans[1] << "\n";
	}
}


// dead code