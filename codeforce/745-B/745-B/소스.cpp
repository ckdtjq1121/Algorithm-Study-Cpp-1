#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		ll n, m, k;
		cin >> n >> m >> k;

		ll ref = n * (n - 1) / 2;
		
		// 이중 간선이 생기거나 연결 그래프가 아니거나
		if (ref < m || m < n - 1)
		{
			cout << "NO\n";
			continue;
		}

		if (n == 1)
		{
			if(k > 1)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if (m < ref)
		{
			if(k > 3)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
		else if( k > 2) //  m == ref
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
}
