#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> arr(n);
		vector<int> sorted(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sorted[i] = arr[i];
		}
		sort(sorted.begin(), sorted.end());

		// �̹� ���ĵǾ� ������  ok
		if (arr == sorted)
		{
			cout << "YES\n";
			continue;
		}

		// ��� �������� swap i , i+1 �� ����� ���� ������ ok
		if (x <= n / 2)
			cout << "YES\n";
		// 0 + n-x ~ x-1 ������ ���ĵȰͰ� ������
		else
		{
			bool fail = false;
			for (int i = n - x; i < x; i++)
				if (arr[i] != sorted[i])
					fail = true;

			if (!fail)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}