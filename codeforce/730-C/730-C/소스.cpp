#include<bits/stdc++.h>

using namespace std;
typedef long double ld;
ld roulette(ld c, ld m, ld p, ld v, int s)
{
	ld ret = 0;

	if (c > 1e-10)
	{
		if (c > v)
		{
			if (m > 1e-10)
				ret += c * roulette(c - v, m + v / 2, p + v / 2, v, s + 1);
			else
				ret += c * roulette(c - v, m, p + v, v, s + 1);
		}
		else
		{
			if (m > 1e-10)
				ret += c * roulette(0, m + c / 2, p + c / 2, v, s + 1);
			else
				ret += c * roulette(0, m, p + c, v, s + 1);
		}

	}

	if (m > 1e-10)
	{
		if (m > v)
		{
			if (c > 1e-10)
				ret += m * roulette(c + v / 2, m - v, p + v / 2, v, s + 1);
			else
				ret += m * roulette(c, m - v, p + v, v, s + 1);
		}
		else
		{
			if (c > 1e-10)
				ret += m * roulette(c + m / 2, 0, p + m / 2, v, s + 1);
			else
				ret += m * roulette(c, 0, p + m, v, s + 1);
		}

	}
	//cout << c << " " << m << " " << p << "\n";
	ret += p * s;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (; testCase > 0; testCase--)
	{
		ld c, m, p, v;
		cin >> c >> m >> p >> v;

		cout.fixed;
		cout.precision(11);
		cout << roulette(c, m, p, v, 1) << "\n";
	}
}