#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<ll> a(n+1);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort(a.begin(), a.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		ll x;
		cin >> x;

		int left = 0;
		int right = n - 1;
		int mid;

		while (left <= right)
		{
			mid = (left + right) / 2;

			if (a[mid] < x)
				left = mid + 1;
			else
				right = mid - 1;
		}

		// a[left]�� x���� ũ�ų� ���� �� left�� n�� �ɶ��� �����ؾ� �Ѵ�
		cout << a[left] << "  ";


		if (a[left] == x)
			cout << "1 ";
		else
			cout << "0 ";

	}
}