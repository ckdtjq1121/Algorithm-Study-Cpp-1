#include<iostream>
#include<list>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	list<int> li;
	for (int i = 1; i <= n; i++)
	{
		li.push_back(i);
	}

	list<int>::iterator iter;
	iter = li.begin();

	// iterator 사용시 li.end() 접근에 주의하자  
	// [li.begin, li.end() )
	cout << "<";
	while (li.size() != 1)
	{
		for (int i = 0; i < (k - 1) % n; i++)
		{
			iter++;
			if (iter == li.end())
				iter = li.begin();
		}

		cout << *iter << ", ";

		iter = li.erase(iter);
		if (iter == li.end())
			iter = li.begin();
	}
	cout << *iter << ">\n";
}