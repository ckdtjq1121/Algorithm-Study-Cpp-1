#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;

	int ans = -1;

	for (int i = c; i <= b; i += c)
	{
		if (a <= i)
		{
			ans = i;
			break;
		}
	}
	
	cout << ans << "\n";
}