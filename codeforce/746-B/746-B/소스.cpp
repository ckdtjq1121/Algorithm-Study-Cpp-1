#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		int n, x;
		cin >> n >> x;
		vector<int> arr(n);
		vector<int> sorted(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
			sorted[i] = arr[i];
		}
		sort(sorted.begin(), sorted.end());

		// 이미 정렬되어 있으면  ok
		if (arr == sorted)
		{
			cout << "YES\n";
			continue;
		}

		// 모든 구간에서 swap i , i+1 을 만들어 낼수 있으면 ok
		if (x <= n / 2)
			cout << "YES\n";
		// 0 + n-x ~ x-1 까지가 정렬된것과 같을때
		else
		{
			bool fail = false;
			for (int i = n - x; i < x; i++)
				if (arr[i] != sorted[i])
					fail = true;

			if (!fail)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}