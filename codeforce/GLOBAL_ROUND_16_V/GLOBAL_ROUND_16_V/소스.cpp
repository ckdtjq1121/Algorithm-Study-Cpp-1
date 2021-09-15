#include<bits/stdc++.h>

using namespace std;

// sort 에서의 compare 함수 작성시
// if (a.first == b.first)
//return a.second < b.second;
// 이 부분을 모든 컴파일러가 보장해 주지 않는다.
bool compare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;

	return a.first < b.first;
}

bool sameCompare(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second > b.second;

	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		//// B
		//string s;
		//cin >> s;
		//
		//int ans = 0;
		//for (int i = 0; i < s.size(); i++)
		//{
		//	if (s[i] == '0')
		//		ans++;
		//
		//	for (int j = i + 1; j < s.size(); j++)
		//	{		
		//		if (s[i] != s[j])
		//		{
		//			i = j - 1;
		//			break;
		//		}
		//
		//		if (j == s.size() - 1)
		//			i = j;
		//	}
		//}
		//
		//ans = min(2, ans);
		//
		//cout << ans << "\n";

		//C
		//int n;
		//cin >> n;
		//string a, b;
		//cin >> a >> b;
		//
		//int ans = 0, j;
		//for (int i = 0; i < n; i++)
		//{
		//	if (a[i] != b[i])
		//		ans += 2;
		//	else if (a[i] == '1')
		//	{
		//		j = i + 1;
		//		while (j < n && a[j] == b[j] && a[j] == '1')
		//		{
		//			j++;
		//		}
		//		if (a[j] != b[j])
		//			ans += 2;
		//		else if (a[j] == '0')
		//			ans += 2;
		//		i = j;
		//	}
		//	else if (a[i] == '0')
		//	{
		//		j = i + 1;
		//		while (j < n && a[j] == b[j] && a[j] == '0')
		//		{
		//			ans++;
		//			j++;
		//		}
		//		if (n == j)
		//			ans++;
		//		else if (a[j] != b[j])
		//			ans += 3;
		//		else if (a[j] == '1')
		//			ans += 2;
		//		
		//		i = j;
		//	}
		//	
		//	//cout << i << " " << ans << "\n";
		//}
		//
		//cout << ans << "\n";

		// D
		//int n, m;
		//cin >> n >> m;
		//for (int i = 0; i < m; i++)
		//{
		//	cin >> seat[i];
		//}
		//int ans = 0;
		//for (int i = 1; i < m; i++)
		//{
		//	for (int j = 0; j < i; j++)
		//	{
		//		if (seat[j] < seat[i])
		//			ans++;
		//	}
		//}
		//cout << ans << "\n";

		int n, m;
		cin >> n >> m;

		pair<int, int> seat[90001];

		// seat[i].first = input data
		// seat[i].second = input sequence index
		for (int i = 0; i < n * m; i++)
		{
			cin >> seat[i].first;
			seat[i].second = i;
		}

		// sorted by input data (sight)
		sort(seat, seat + n*m);

		//for (int i = 0; i < n * m; i++)
		//	cout << seat[i].second << " ";
		//cout << endl;
		
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			// In each row, sorted by the order of entry : if( a.first == b.first) sort desc
			sort(seat + m * i, seat + m * i + m, sameCompare);

			// In each row, count incomvience
			for (int j = 0; j < m; j++)
			{		
				for (int k = 0; k < j; k++)
				{
					if (seat[m * i + k].second < seat[m * i + j].second)
					{

						//cout << seat[m * i + k].first << " " << seat[m * i + k].second << "     " << seat[m * i + j].first << " " << seat[m * i + j].second << "\n";
						ans++;
					}
				}
			}
		}

	/*	for (int i = 0; i < n * m; i++)
			cout << seat[i].second << " ";
		cout << endl;*/
		cout << ans << "\n";
	}
}
