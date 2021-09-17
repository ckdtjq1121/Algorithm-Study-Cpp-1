#include<bits/stdc++.h>

using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {};

	// pos 까지의 부분합
	int sum(int pos)
	{

		int ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			// 이진수 에서 뒤쪽에 있는 1을 제거하는 방법
			pos = pos & (pos - 1);
		}
		return ret;
	}

	// pos 위치가 포함된 부분의 부분합에 val 만큼 더해줌
	void add(int pos, int val)
	{
		while (pos < tree.size())
		{
			tree[pos] += val;
			// 이진수에서 마지막 1만큼을 더해서 상위 부분합으로 이동
			pos += (pos & -pos);
		}
	}
};


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	FenwickTree tree = FenwickTree(5);
	// 1 ~ n
	for (int i = 1; i <= 5; i++)
	{
		tree.add(i, i);
	}

	//for (int i = 1; i <= 5; i++)
	//{
	//	cout<< tree.sum(i) << " ";
	//}
	tree.add(3, 3);
	cout << tree.sum(5) - tree.sum(1) << "\n";
	tree.add(5, -3);
	cout << tree.sum(5) - tree.sum(2) << "\n";
}