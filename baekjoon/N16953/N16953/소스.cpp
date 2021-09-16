#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int cnt = 0;
	while (b > a)
	{
		if (b % 10 == 1)
			b /= 10;
		else if (b % 2 == 1)
			break;
		else
			b /= 2;

		cnt++;
	}
	int ans = -1;
	if (a == b)
		ans = cnt + 1;

	cout << ans << "\n";	
}