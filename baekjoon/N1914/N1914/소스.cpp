
#include<bits/stdc++.h>

using namespace std;
// n����  from���� to�� �ű��
void hanoi(int n, int from, int tmp, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
		return;
	}

	hanoi(n - 1, from, to, tmp);
	cout << from << " " << to << "\n";
	hanoi(n - 1, tmp, from, to);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	// 2^100 -1�� long long ���ε� ǥ�� �Ұ� - > string���� ǥ��
	string ans = to_string(pow(2, n));
	// �Ҽ������� �κ� ����
	int idx = ans.find('.');
	ans = ans.substr(0, idx);
	// -1
	ans[ans.size() - 1] -= 1;
	cout << ans << "\n";

	if (n <= 20)
		hanoi(n, 1, 2, 3);
}