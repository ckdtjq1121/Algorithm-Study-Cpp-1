#include<bits/stdc++.h>

using namespace std;

struct FenwickTree {
	vector<int> tree;
	FenwickTree(int n) : tree(n + 1) {};

	// pos ������ �κ���
	int sum(int pos)
	{

		int ret = 0;
		while (pos > 0)
		{
			ret += tree[pos];
			// ������ ���� ���ʿ� �ִ� 1�� �����ϴ� ���
			pos = pos & (pos - 1);
		}
		return ret;
	}

	// pos ��ġ�� ���Ե� �κ��� �κ��տ� val ��ŭ ������
	void add(int pos, int val)
	{
		while (pos < tree.size())
		{
			tree[pos] += val;
			// ���������� ������ 1��ŭ�� ���ؼ� ���� �κ������� �̵�
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