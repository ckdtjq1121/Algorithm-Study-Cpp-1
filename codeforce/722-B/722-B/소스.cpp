#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end());
		
		vector<int> diff(n, 0);
		vector<int> mi(n, INT_MAX);
		for (int i = 1; i < n; i++)
		{
			diff[i] = abs(arr[i] - arr[i - 1]);
			mi[i] = min(mi[i - 1], diff[i]);
		}

		int ans = n;
		for (int i = n - 1; i >= 0; i--)
		{
			if (arr[i] > mi[i])
				ans--;
			else
				break;
		}

		cout << ans << "\n";
	}
}