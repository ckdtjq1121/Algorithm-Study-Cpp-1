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

		deque<int> d;

		d.push_back(arr[0]);
		for (int i = 1; i < n; i++)
		{
			if (arr[i] <= d.front())
				d.push_front(arr[i]);
			else
				d.push_back(arr[i]);
		}

		for (int i = 0; i < n; i++)
			cout << d[i] << " ";
		cout << "\n";
	}
}