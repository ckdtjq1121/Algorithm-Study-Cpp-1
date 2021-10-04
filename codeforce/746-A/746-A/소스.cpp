#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, h;
		cin >> n >> h;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr.begin(), arr.end(), greater<>());

		int ans = 0;
		int sum = arr[0] + arr[1];

		ans += h / sum * 2;
		h = h % sum;


		if (h != 0)
		{
			if (h <= arr[0])
				ans++;
			else
				ans += 2;
		}

		cout << ans << "\n";
	}
}