#include<bits/stdc++.h>

using namespace std;
int n;
void star1(int i, int j)
{
	if (j <= i)
		cout << "*";
}
void star2(int i, int j)
{
	if (j < n - i - 1)
		cout << " ";
	else
		cout << "*";
}
void star3(int i, int j)
{
	if (i + j < n)
		cout << "*";
}
void star4(int i, int j)
{
	if (i > j)
		cout << " ";
	else
		cout << "*";
}
void star5(int i, int j)
{
	if (j < n)
	{
		if (i + j < n - 1)
			cout << " ";
		else
			cout << "*";
	}
	else
	{
		if (j - n < i)
			cout << "*";
	}
}
void star6(int i, int j)
{
	if (j < n)
	{
		if (j < i)
			cout << " ";
		else
			cout << "*";
	}
	else
	{
		if (i + j - n + 1< n)
			cout << "*";
	}
}
void star7(int i, int j)
{
	if (i < n && j < n)
	{
		if (i + j < n - 1)
			cout << " ";
		else
			cout << "*";
	}
	else if (i < n && n <= j)
	{
		if (j - n < i)
			cout << "*";
	}
	else if (n <= i && j < n)
	{
		if (i - n < j)
			cout << "*";
		else
			cout << " ";
	}
	else if (n <= i && n <= j)
	{
		if (i + j + 2 < 3 * n)
			cout << "*";
	}
}
void star8(int i, int j)
{
	if (i < n && j < n)
	{
		if (j <= i)
			cout << "*";
		else
			cout << " ";
	}
	else if (i < n && n <= j)
	{
		if (i + j < 2 * n - 1)
			cout << " ";
		else
			cout << "*";
	}
	else if (n <= i && j < n)
	{
		if (i + j < 2 * n - 1)
			cout << "*";
		else
			cout << " ";
	}
	else if (n <= i && n <= j)
	{
		if (i < j)
			cout << "*";
		else
			cout << " ";
	}
}
void star9(int i, int j)
{
	if (i < n && j < n)
	{
		if (i <= j)
			cout << "*";
		else
			cout << " ";
	}
	else if (i < n && n <= j)
	{
		if (i + j < 2 * n - 1)
			cout << "*";

	}
	else if (n <= i && j < n)
	{
		if (i + j < 2 * n - 2)
			cout << " ";
		else
			cout << "*";
	}
	else if (n <= i && n <= j)
	{
		if (i >= j)
			cout << "*";
	}
}
void star10(int n, int i, int j)
{
	if (n == 1)
	{
		cout << "*";
		return;
	}

	if (n / 3 <= i && i < n / 3 * 2 && n / 3 <= j && j < n / 3 * 2)
		cout << " ";
	else
	{
		n = n / 3;
		star10(n, i % n, j % n);
	}
}
void star11(int n, int i, int j)
{

}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//star1(i, j);
			//star2(i, j);
			//star3(i, j);
			//star4(i, j);
		}
		//cout << "\n";
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j++)
		{
			//star5(i, j);
			//star6(i, j);
		}
		//cout << "\n";
	}

	for (int i = 0; i < 2 * n - 1; i++)
	{
		for (int j = 0; j < 2 * n; j++)
		{
			//star7(i, j);
			//star8(i, j);
			//star9(i, j);
		}
		//cout << "\n";
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			//star10(n, i, j);
		}
		//cout << "\n";
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2 * n; j++)
			star11(i, j);
		cout << "\n";
	}
}