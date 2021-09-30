#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;


	vector<int> arr(1001);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	for (int i = 4; i <= 1000; i++)
	{
		arr[i] = arr[i - 1] + 1;
		while (arr[i] % 3 == 0 || arr[i] % 10 == 3)
			arr[i]++;
	}


	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;

		cout << arr[n] << "\n";
	}
}