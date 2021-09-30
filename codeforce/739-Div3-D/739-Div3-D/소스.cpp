#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	vector<int> arr;
	for (int i = 1; i <= 1000000000; i = i * 2)
	{
		arr.push_back(i);
		cout << i << " ";
	}
	cout << "\n";
	vector<vector<int> > dict(arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		dict[i] = vector<int>(10, 0);
		int tmp = arr[i];
		while (tmp != 0)
		{
			dict[i][tmp % 10]++;
			tmp /= 10;
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < 10; j++)
			cout << dict[i][j] << " ";
		cout << "\n";
	}

	//for (; testCase > 0; testCase--)
	//{
	//	int n;
	//	vector<int> ndict(10, 0);
	//	while (n != 0)
	//	{
	//		ndict[n % 10]++;
	//		n /= 10;
	//	}
	//}


}