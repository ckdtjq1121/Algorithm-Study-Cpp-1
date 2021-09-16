#include<bits/stdc++.h>

using namespace std;
const int MAX = 300001;



bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second > b.second;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, k;

	cin >> n >> k;

	vector<pair<int, int> > jewelry(n);
	for (int i = 0; i < n; i++)
	{
		cin >> jewelry[i].first >> jewelry[i].second;
	}
	//sort(jewelry.begin(), jewelry.end(), greater<>());
	sort(jewelry.begin(), jewelry.end(), compare);


	//cout << endl;
	//for (int i = 0; i < n; i++)
	//{
	//	cout << jewelry[i].first << " " << jewelry[i].second << "\n";
	//}

	vector<int> bag(k);
	for (int i = 0; i < k; i++)
	{
		cin >> bag[i];
	}
	sort(bag.begin(), bag.end(), greater<>());


	for (int i = 0; i < n; i++)
	{
		int left = 0;
		int right = k - 1;

		while (left < right)
		{
			int mid = (left + right);

			if (jewelry[i].first <= bag[mid])
			{
				right = mid - 1;
			}
			else
				left = mid + 1;
		}

		cout << bag[left] << " ";
	}
}