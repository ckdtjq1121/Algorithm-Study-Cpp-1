#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	string s;
	cin >> s;

	if (s[n - 1] == 'o')
		cout << "Yes\n";
	else
		cout << "No\n";

}