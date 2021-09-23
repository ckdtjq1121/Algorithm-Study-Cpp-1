#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sum;

ll fightCost(ll x, ll y, ll hero)
{
	ll attack = 0;
	ll defence = 0;

	if (hero < x)
		attack = x - hero;

	defence = y - (sum - hero);

	if (defence < 0)
		defence = 0;

	ll ans = attack + defence;

	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	sum = 0;
	vector<ll> hero(n);
	for (int i = 0; i < n; i++)
	{
		cin >> hero[i];
		sum += hero[i];
	}
	sort(hero.begin(), hero.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		ll x, y;
		cin >> x >> y;

		int left = 0;
		int right = n - 1;
		int mid;
		while (left < right)
		{
			mid = (left + right) / 2;

			if (hero[mid] <= x)
				left = mid + 1;
			else if (hero[mid] > x)
				right = mid - 1;
	
		}
	
		ll ans = fightCost(x, y, hero[left]);

		if (left != 0)
			ans = min(ans, fightCost(x, y, hero[left - 1]));
		
		if (left != n - 1)
			ans = min(ans, fightCost(x, y, hero[left + 1]));
		cout << ans << "\n";
	}
}