#include<bits/stdc++.h>

using namespace std;
double mul(int a, int b)
{
	return (double)a * b;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	double a = INT_MAX;
	double b = INT_MAX;

	string s = to_string(mul(a, b));
	cout << a << " " << b << " " << s << " " << a* b << "\n";
}