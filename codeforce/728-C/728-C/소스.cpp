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
		int n;
		cin >> n;

		vector<ll> dist(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> dist[i];

		sort(dist.begin() + 1, dist.end());
		//vector<ll> diff(n);
		//for (int i = 1; i < n; i++)
		//	diff[i] = abs(dist[i + 1] - dist[i]);

		//dist[1] = 0;
		//for (int i = 2; i <= n; i++)
		//	dist[i] = dist[i - 1] + diff[i - 1];


		vector<ll> psum(n + 1);
		psum[1] = dist[1];
		for (int i = 2; i <= n; i++)
			psum[i] = psum[i - 1] + dist[i];

		ll ans = 0;
		for (int i = 3; i <= n; i++)
		{
			ans += dist[i] * (i - 2ll) - psum[i - 2];

		}

		cout << -ans << "\n";


	}
}