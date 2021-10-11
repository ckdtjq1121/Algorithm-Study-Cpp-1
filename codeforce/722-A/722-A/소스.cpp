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

		int tmp = arr[0];
		int ans = n;
		for (int i = 1; i < n; i++)
			if (arr[i] != tmp)
			{
				ans -= i;
				break;
			}

		if (ans == n)
			cout << 0 << "\n";
		else
			cout << ans << "\n";
	}
}