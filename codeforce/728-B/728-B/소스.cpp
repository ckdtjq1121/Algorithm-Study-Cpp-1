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
		vector<int> arr(n + 1);
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = arr[i];
			int j = x - i; // i+j는 항상 arr[i]의 배수 
			while (j <= i) // i < j
				j += x;	
			while (j <= n)
			{
				long long tmp = arr[i];
				tmp *= arr[j];
				if (tmp == (long long)i + j)
					ans++;

			//cout << i << " " << j << " " << arr[i] << " " << arr[j] << "\n";
				j += x;
			}
		}
		cout << ans << "\n";
	}
}