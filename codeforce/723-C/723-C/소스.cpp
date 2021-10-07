#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	priority_queue<ll, vector<ll>, greater<ll> > pq;
	int ans = n;
	vector<ll> psum(n);
	psum[0] = arr[0];
	if (psum[0] < 0)
	{
		ans--;
		psum[0] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (arr[i] < 0)
		{
			pq.push(arr[i]);
		}
		psum[i] = psum[i - 1] + arr[i];

		if (psum[i] < 0)
		{
			ans--;
			psum[i] -= pq.top();
			pq.pop();
		}

	}

	cout << ans << "\n";

}