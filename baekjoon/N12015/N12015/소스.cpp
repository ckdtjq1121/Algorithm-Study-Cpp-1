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

	vector<int> sorted(n);
	sorted = arr;

	sort(sorted.begin(), sorted.end());

	int ans = 1;
	int last = arr[0];
	for (int i = 1; i < n; i++)
	{

	}

	//
}