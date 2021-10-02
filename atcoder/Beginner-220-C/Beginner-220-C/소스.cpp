

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ll n;
	cin >> n;
	vector<ll> arr(n);
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	ll x;
	cin >> x;

	ll res = x % sum;
	int i = 0;
	for (; i < n; i++)
	{
		res -= arr[i];
		if (res < 0)
		{
			break;
		}
	}

	cout << (x / sum) * n + i + 1 << "\n";
}

// 1000000000000000000