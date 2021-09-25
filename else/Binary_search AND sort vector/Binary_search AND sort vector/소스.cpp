#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<int> > a(n);
	for (int i = 0; i < n; i++)
	{
		a[i].resize(n);
		for(int j = 0; j < n; j++)
		cin >> a[i][j];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j];
		cout << "\n";
	}

	// bool binary_search (<T>.begin(), <T>.end(), T value)
	//cout << binary_search(a.begin(), a.end(), 10);
}