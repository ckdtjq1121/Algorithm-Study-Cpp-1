#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;

	vector<int> plus;
	vector<int> zero;
	vector<int> minus;

	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;

		if (tmp > 0)
			plus.push_back(tmp);
		else if (tmp == 0)
			zero.push_back(tmp);
		else
			minus.push_back(tmp);
	}

	sort(plus.begin(), plus.end(), greater<>());
	sort(minus.begin(), minus.end());

	int ans = 0;
	for (int i = 0; i < plus.size(); i = i + 2)
	{
		if (i == plus.size() - 1) // 양의 정수가 홀수 개인 경우
			ans += plus[i];
		else if(plus[i] == 1 || plus[i+1] == 1) // 1이 포함된경우 곱보다 합이 더크다
			ans += plus[i] + plus[i + 1];
		else                                     
			ans += plus[i] * plus[i + 1];
	}
	for (int i = 0; i < minus.size(); i = i + 2)
	{
		if (i == minus.size() - 1)
		{
			if (zero.size() != 0) // 음의 정수가 홀수 개인 경우 0이 있다면 0이랑 곱해서 상쇄
				ans += 0;
			else
				ans += minus[i];
		}
		else
			ans += minus[i] * minus[i + 1];
	}

	cout << ans << "\n";
}