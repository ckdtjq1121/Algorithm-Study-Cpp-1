#include<bits/stdc++.h>
const int MAX = 50000;
using namespace std;
map<int, int> m;
// by upsk1
bool isDominated(int x, int y) {
	map<int, int>::iterator it = m.lower_bound(x);
	if (it == m.end())return false;
	return y < it->second;
}
void removeDominated(int x, int y) {
	map<int, int>::iterator it = m.lower_bound(x);
	if (it == m.begin())return;
	--it;
	while (true) {
		if (it->second > y)break;
		if (it == m.begin()) {
			m.erase(it);
		
			break;
		}
		else {
			map<int, int>::iterator jt = it;
			--jt;
			m.erase(it);
			it = jt;
			
		}
	}
}
int registered(int x, int y) {
	if (isDominated(x, y))return m.size();
	removeDominated(x, y);
	m[x] = y;
	
	return m.size();
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

		int problem, ramen;
		
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> problem >> ramen;

			ret += registered(problem, ramen);
			//// insert
			//if (m.empty() || m.lower_bound(problem) == m.end())
			//	m.insert(make_pair(problem, ramen));
			//else if (ramen > m.lower_bound(problem)->second)
			//{
			//	m.insert(make_pair(problem, ramen));
			//}

			//// remove
			//removeDominated(problem, ramen);



			//for (iter = m.begin(); iter != m.end(); iter++)
			//{
			//	cout << iter->first << " ";

			//}
			//cout << endl;

			
			
		}
		m.clear();

		cout << ret << "\n";
	}
}