#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	
	int a, b;
	cin >> a >> b;

	cout.fixed;
	cout.precision(10);
	double ans = (double)2 * a + (double)2 * b * (3.141592);
	cout << ans << "\n";
}