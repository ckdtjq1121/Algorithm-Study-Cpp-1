#include<bits/stdc++.h>

using namespace std;

bool canChange(int a, int b, int c)
{
	if (a == 0 && b == 0 && c == 0)
		return false;

	return !((a ^ b) ^ c);
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

		vector<int> binary(n);
		for (int i = 0; i < n; i++)
			cin >> binary[i];

		vector<int> psum(n, 0);


		for (int i = 0; i < n; i++)
		{
			cout << psum[i] << " ";
		}
		cout << endl;
		//cout << canChange(0, 1, 1) << "\n";
	}
}