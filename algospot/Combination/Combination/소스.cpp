// 0 ~ (n-1) ���� n���� ���� �� m���� ���Ҹ� ���� ��� ������ ã�� �˰���
#include<iostream>

#include<vector>
using namespace std;

// n : �� ������ ��
// picked : ����� ������ ����
// toPick : ������ �� �� ������ ��

void printPicked(vector<int>& picked)
{
	for (int i = 0; i < picked.size(); i++)
		cout << picked[i] << " ";

	cout << "\n";
	return;
}
void pick(int n, vector<int>& picked, int toPick)
{
	if (toPick == 0) 
	{
		printPicked(picked);
		return;
	}

	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; next++)
	{
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
	
	return;
}
int main()
{
	int n, m;
	cin >> n >> m;

	vector<int> ret;
	pick(n, ret, m);
	return 0;
}