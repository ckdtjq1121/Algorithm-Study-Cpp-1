#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		string s, t;
		cin >> s >> t;

		int n = s.size();
		int m = t.size();

		if (n < m)
		{
			cout << "NO\n";
			continue;
		}
		int p = (n - m) & 1; // �����̴� ó�� ���� 2���� �ۿ� �� �����. Ȧ���� ���̰� ���ٸ� �ݵ�� ù��°�Ÿ� ���� �Ѵ�.
		int q = 0;
		int k = 0;
		for (int i = p; i < n; i++) {
			if (k == 1) {
				k = 0;
				continue;
			}
			if (q < m && s[i] == t[q]) {
				q++;
			}
			else {	// ��ã����� i�� i+1�� ��ŵ�Ѵ�.
				k++;
			}
		}

		if (q == m)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}