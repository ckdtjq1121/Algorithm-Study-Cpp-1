#include<bits/stdc++.h>

using namespace std;

// a ^ n
int pow(int a, int n)
{
	if (n == 1)
		return a;

	if (n % 2)
		return n * pow(a, n - 1);

	return pow(a, n / 2) * pow(a, n / 2);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> arr(n);
	vector<int> alphabet(26);

	// input arr <string>
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// get priority by frequency and digit
	for (int i = 0; i < n; i++)
	{
		string s = arr[i];
		int pos = pow(10, s.size() - 1);
		for (int j = 0; j < s.size(); j++)
		{
			alphabet[s[j] - 'A'] += pos;

			pos /= 10;
		}
	}

	// sorted by prirority
	sort(alphabet.begin(), alphabet.end(), greater<>());

	// get ans
	// ans += alphabet priority (digit*frequency) * value
	int value = 9;
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans += alphabet[i] * value;
		value--;

		if (!value)
			break;
	}

	cout << ans << "\n";
}