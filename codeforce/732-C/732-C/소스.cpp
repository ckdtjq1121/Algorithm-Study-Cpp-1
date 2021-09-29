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

		vector<int> right(n);
		for (int i = 0; i < n; i++)
			right[i] = arr[i];

		sort(right.begin(), right.end());

		vector<int> a;
		vector<int> b;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
				a.push_back(arr[i]);
			else
				b.push_back(arr[i]);
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		for (int i = 0; i < a.size(); i++)
		{
			arr[2 * i] = a[i];
			if(i < b.size())
			arr[2 * i + 1] = b[i];
		}


		bool fail = false;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] != right[i])
				fail = true;
		}

		if (fail)
			cout << "NO\n";
		else
			cout << "YES\n";

	}
}