#include<bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		// A
		//long long n;
		//cin >> n;
		//int rest = n % 6;
		//long long ans = n / 6 * 15;
		//if (rest == 0)
		//	ans += 0;
		//else if (rest <= 2)
		//	ans += 5;
		//else if (rest <= 4)
		//	ans += 10;
		//else
		//	ans += 15;
		//if (ans < 15)
		//	ans = 15;
		//cout << ans << "\n";

		// B   -   0이 되는 조건
		//int w, h;
		//cin >> w >> h;
		//int x1, y1, x2, y2;
		//cin >> x1 >> y1 >> x2 >> y2;
		//int a, b;
		//cin >> a >> b;
		//// -1 할 수 없는 상황
		//if (w < (x2 - x1) + a && h < (y2 - y1) + b)
		//{
		//	cout << -1 << "\n";
		//	continue;
		//}
		//// 0 움직이지 않아도 되는 상황
		//if (a <= x1 || b <= y1 || x2 <= w - a || y2 <= h - b)
		//{
		//	cout << 0 << "\n";
		//	continue;
		//}
		//double ans = INF;
		//if (w >= (x2 - x1) + a)
		//{
		//	if (a - x1 > 0)
		//		ans = min(ans, (double)a - x1);
		//	if (x2 - (w - a) > 0)
		//		ans = min(ans, (double)(x2 - (w - a)));
		//}
		//if (h >= (y2 - y1) + b)
		//{
		//	if (b - y1 > 0)
		//		ans = min(ans, (double)b - y1);
		//	if (y2 - (h - b) > 0)
		//		ans = min(ans, (double)(y2 - (h - b)));
		//}
		//
		//cout.precision(10);
		//cout << ans << "\n";

		// C
		//int m;
		//cin >> m;
		//int board[2][100001];
		//for (int i = 0; i < 2; i++)
		//{
		//	for (int j = 0; j < m; j++)
		//	{
		//		cin >> board[i][j];
		//	}
		//}
		//vector<int> psumA(m)
		//for (int i = 0; i < m; i++)
		//{
		//	if (i != 0)
		//		psumA[i] = psumA[i - 1] + board[0][i];
		//	else
		//		psumA[i] = board[0][i];
		//}
		//vector<int> psumB(m);
		//for (int i = 0; i < m; i++)
		//{
		//	if (i != 0)
		//		psumB[i] = psumB[i - 1] + board[1][i];
		//	else
		//		psumB[i] = board[1][i];
		//}
		//int upside, downside;
		//int ans = INF;
		//for (int i = 0; i < m; i++)
		//{
		//	// i+1 ~ m -1
		//	upside = psumA[m - 1] - psumA[i];
		//	// 0 ~ i-1
		//	if (i > 0)
		//		downside = psumB[i - 1];
		//	else
		//		downside = 0;
		//	ans = min(ans, max(upside, downside));;
		//}
		//cout << ans << "\n";

	}

	// D
	int n, q;
	cin >> n >> q;

	string s;
	cin >> s;

	// init
	int psumCnt[3][20001];
	for (int i = 0; i < s.size(); i++)
	{
		psumCnt[0][i] = 0;
		psumCnt[1][i] = 0;
		psumCnt[2][i] = 0;
	}

	// psum 1 ~ n        -   O(n)
	for (int i = 1; i <= s.size(); i++)
	{
		if (3 < i)
		{
			psumCnt[0][i] += psumCnt[0][i - 3];
			psumCnt[1][i] += psumCnt[1][i - 3];
			psumCnt[2][i] += psumCnt[2][i - 3];
		}

		if (s[i] == 'a')
			psumCnt[0][i]++;
		else if (s[i] == 'b')
			psumCnt[1][i]++;
		else
			psumCnt[2][i]++;
	}
	// query - use psumCnt[right-2, right-1, right] - > make pattern - > repeat -> cnt cost  - O(1)
	for (int i = 0; i < q; i++)
	{
		int left, right;
		cin >> left >> right;

		int p1[3], p2[3], p3[3];
		int ref = right % 3;
		left = left / 3;
		left = left * 3;
		left = left - 3;
		left = left + ref;

		for (int i = 0; i < 3; i++)
		{
			if (right >= 0)
			{
				if (left > 0)
					p1[i] = psumCnt[i][right] - psumCnt[i][left];
				else
					p1[i] = psumCnt[i][right];
			}
			else
			{
				p1[i] = 0;
			}

			if (right - 1 >= 0)
			{
				if (left - 1 > 0)
					p2[i] = psumCnt[i][right - 1] - psumCnt[i][left - 1];
				else
					p2[i] = psumCnt[i][right - 1];
			}
			else
			{
				p1[i] = 0;
			}

			if (right - 1 >= 0)
			{
				if (left - 2 > 0)
					p3[i] = psumCnt[i][right - 2] - psumCnt[i][left - 2];
				else
					p3[i] = psumCnt[i][right - 2];
			}
			else
			{
				p1[i] = 0;
			}
		}


		// ex) baacb  1 5
		// a   1   0   1
		// b   0   1   1
		// c   0   1   0
		//
		// => a c b(right)  pathern
		// ans = 0 + 1 + 1 => 2
	}
}