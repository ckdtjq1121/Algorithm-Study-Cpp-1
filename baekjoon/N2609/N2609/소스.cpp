#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
	if (a < b)
		swap(a, b);

	int tmp;
	while (b != 0)
	{
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	cin >> a >> b;

	int g = gcd(a, b);
	cout << g << "\n";	// greatest common divide
	cout << a / g * b << "\n"; // least common mutiply
}