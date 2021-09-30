#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, d;
		cin >> n >> d;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int cnt = 0;
		while (true)
		{
			int ans = 0;
			for (int i = 0; i < n; i++)
				ans |= arr[i];

			if (!ans)
			{
				cout << cnt << "\n";
				break;
			}

			vector<int> tmp(n);
			for (int i = 0; i < n; i++)
			{
				tmp[i] = arr[(n - d + i) % n];
				//cout << tmp[i] << " ";
			}

			bool end = true;
			for (int i = 0; i < n; i++)
			{
				if (arr[i] != tmp[i])
				{
					end = false;
					break;
				}
			}

			if (end)
			{
				cout << -1 << "\n";
				break;
			}

			for (int i = 0; i < n; i++)
			{
				arr[i] = arr[i] & tmp[i];
			}
			cnt++;


		}

	}
}