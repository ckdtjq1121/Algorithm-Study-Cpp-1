#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	// psum 을 활용시 원소가 0개일때와 원소가 n개 일 때를 주의 하자
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (sum + 1 < arr[i])
			break;

		sum += arr[i];
	}

	cout << sum + 1 << "\n";
}