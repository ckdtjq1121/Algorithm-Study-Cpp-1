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
		vector<int> arr(2 * n);
		int odd = 0, even = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> arr[i];
			if (arr[i] % 2 == 0)
				even++;
			else
				odd++;
		}

		if (odd == even)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}