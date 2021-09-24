#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> money(n);
	for (int i = 0; i < n; i++)
	{
		cin >> money[i];
	}
	sort(money.begin(), money.end());

	int total;
	cin >> total;
	
	int left = 1;
	int right = 1000000000;
	int mid;

	while (left <= right)
	{
		mid = (left + right) / 2;

		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (money[i] < mid)
				sum += money[i];
			else
				sum += mid;
		}

		if (sum > total)
			right = mid - 1;
		else
			left = mid + 1;
	}

	if (right == 1000000000)
		cout << money[n-1] << "\n";
	else
		cout << right << "\n";
}