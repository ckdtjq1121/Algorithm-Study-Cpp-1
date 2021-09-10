// reverse insert sorting
#include<bits/stdc++.h>

using namespace std;
const int MAX = 50001;
int n;

int ans[MAX];
int arr[MAX];
int sorted[MAX];
int segTree[MAX * 2 + 1];
bool checked[MAX];
void makeReverse()
{
	int tmp;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i - arr[i]; j < i; j++)
		{
			tmp = sorted[j];
			sorted[j] = sorted[j + 1];
			sorted[j + 1] = tmp;
		}

	}
}

void treeInit(int node, int start, int end)
{
	if (start == end)
	{
		segTree[node] = 1;
		return;
	}

	int mid = (start + end) / 2;
	treeInit(2 * node, start, mid);
	treeInit(2 * node + 1, mid + 1, end);
	segTree[node] = segTree[2 * node] + segTree[2 * node + 1];

	return;
}
// [start, end]에서 x번째 원소의 index 찾기
int query(int node, int start, int end, int x)
{
	if (start == end) return start; // x번째 원소 index return
	int mid = (start + end) / 2;
	if (segTree[2 * node] < x) query(2 * node + 1, mid + 1, end, x - segTree[2 * node]); // 왼쪽 노드의 값 < x 오른쪽 노드에서 (x - 왼쪽 노드의 값) 번째 값을 찾아야함
	else return query(2 * node, start, mid, x);	// 왼쪽노드에서  x번째 값을 찾으면 됨
}
void update(int node, int start, int end, int x)
{
	if (start > x || end < x) return; // x가 없는 범위면 끝을 냄
	segTree[node]--;	// x가 있는 범위에엇 x를 사용했으므로 cnt를 -- 해줌
	if (start == end) return;	// 마지막 update 범위
	int mid = (start + end) / 2;
	update(2 * node, start, mid, x); // 왼쪽 자식 트리
	update(2 * node + 1, mid + 1, end, x); // 오른쪽 자식 트리
}

// sorted[x] == x;
int find(int x)	// 뒤에서 x번째 원소 찾기
{
	int& ret = sorted[n - x];	// x번째 값
	int ans;
	if (x == n)
		return 1;

	ans = ret;
	ret = sorted[n - x - 1];	// make union
	if (checked[ans]) // not union
	{
		ans = find(n - ret);		// find root of union
		
	}

	checked[ans] = true;
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		//input 
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		//init
		for (int i = 1; i <= n; i++)
		{
			sorted[i] = i;
		}

		// inplement ReverseINSERTION  -  n^2
		//makeReverse();

		// segTree	-  n * log n
		//treeInit(1, 1, n);
		//for (int i = n; i > 0; i--) {
		//	ans[i] = query(1, 1, n, arr[i] + 1);
		//	update(1, 1, n, ans[i]);
		//	ans[i] = n - ans[i] + 1;
		//}

		// unionfind		-  fail 
		for (int i = 1; i <= n; i++)
		{
			checked[i] = false;
		}
		for (int i = n; i > 0; i--)
		{
			ans[i] = find(arr[i]);
		}

		//output
		for (int i = 1; i <= n; i++)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}

