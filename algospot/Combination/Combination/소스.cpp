// 0 ~ (n-1) 까지 n개의 원소 중 m개의 원소를 고르는 모든 조합을 찾는 알고리즘
#include<iostream>

#include<vector>
using namespace std;

// n : 총 원소의 수
// picked : 골라진 원소의 집합
// toPick : 앞으로 더 고를 원소의 수

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