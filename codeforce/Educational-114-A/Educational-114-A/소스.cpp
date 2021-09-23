#include<bits/stdc++.h>

using namespace std;

void printA(int n)
{
	string s = "";
	for (int i = 0; i < n; i++)
	{
		s += "(";
	}
	for (int i = 0; i < n; i++)
	{
		s += ")";
	}

	cout << s;
}
void printB(int n)
{
	string s = "";
	for (int i = 0; i < n; i++)
	{
		s += "()";
	}

	cout << s << "\n";
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int testCase;
	cin >> testCase;
	
	for (; testCase > 0; testCase--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			printA(i);
			printB(n - i);
		}
	}
}