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
		{
			cin >> arr[i];
		}

		vector<int> ans(n);
		ans[0] = 0;
		for (int i = 1; i < n; i++)
		{
			int a = arr[i - 1] ^ ans[i - 1];
			int b = arr[i];
			if ((a & b) == a)
			{
				ans[i] = 0;
			}
			else // b ^ x (min x)
			{
				ans[i] = (a | b) - b;
			}
		}

		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";

	}
}