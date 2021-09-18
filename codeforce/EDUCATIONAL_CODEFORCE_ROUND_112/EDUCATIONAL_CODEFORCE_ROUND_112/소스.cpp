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
		int w, h;
		cin >> w >> h;
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int a, b;
		cin >> a >> b;
		// -1 할 수 없는 상황
		if (w < (x2 - x1) + a && h < (y2 - y1) + b)
		{
			cout << -1 << "\n";
			continue;
		}
		// 0 움직이지 않아도 되는 상황
		if (a <= x1 || b <= y1 || x2 <= w - a || y2 <= h - b)
		{
			cout << 0 << "\n";
			continue;
		}
		double ans = INF;
		if (w >= (x2 - x1) + a)
		{
			if (a - x1 > 0)
				ans = min(ans, (double)a - x1);
			if (x2 - (w - a) > 0)
				ans = min(ans, (double)(x2 - (w - a)));
		}
		if (h >= (y2 - y1) + b)
		{
			if (b - y1 > 0)
				ans = min(ans, (double)b - y1);
			if (y2 - (h - b) > 0)
				ans = min(ans, (double)(y2 - (h - b)));
		}
		
		cout.precision(10);
		cout << ans << "\n";


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
}