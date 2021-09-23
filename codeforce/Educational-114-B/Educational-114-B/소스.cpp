#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	vector<long long> a(3);
	for (; testCase > 0; testCase--)
	{
			long long m;
			cin >> a[0] >> a[1] >> a[2] >> m;

			sort(a.begin(), a.end());
	
			if (a[2] - (a[0] + a[1] + 1) <= m && m <= a[2] + a[1] + a[0] - 3)
			{
				cout << "YES\n";
			}
			else
				cout << "NO\n";
	}
}