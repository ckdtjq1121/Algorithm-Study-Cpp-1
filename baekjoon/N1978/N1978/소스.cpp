#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);


	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 2; j < arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				break;
			}

			if (j == arr[i] - 1)
				ans++;
		}

		if (arr[i] == 2)
			ans++;
	}

	cout << ans << "\n";

}