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
		int p = (n - m) & 1; // 예술이다 처음 뺴곤 2개씩 밖에 못 지운다. 홀수개 차이가 난다면 반드시 첫번째거를 빼야 한다.
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
			else {	// 못찾을경우 i와 i+1을 스킵한다.
				k++;
			}
		}

		if (q == m)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}