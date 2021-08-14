#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> height;
int solveStack()
{
	stack<int> remaining;
	height.push_back(0); // 마지막에 0을 넣는 이유는 height[remaining.top()] >= (height[i] = 0) 을 만족 시키기 위해서
	int ret = 0;
	// if( remaining.top() < height[i] ) remaining.push(i)
	// else if( remaining.empty()) remaining.push(i)
	// else if( !remaining.empty() && remaining.top()>= height[i] ) ret = max(ret, height[i] * width)
	// width 구하는 방법 1 : remaining이 비어서 i가 들어왔을때 i까지가 width
	// width 구하는 방법 2 : 전에꺼보다 height이 더 커서 들어 왔으므로 전에꺼+1 부터 현재 위치까지  width
	for (int i = 0; i < height.size(); i++)
	{
		while (!remaining.empty() && height[remaining.top()] >= height[i])
		{
			int j = remaining.top();
			remaining.pop();
			int width = -1;

			if (remaining.empty())
				width = i;
			else
				width = (i - remaining.top() - 1);
			ret = max(ret, height[j] * width);
		}
		remaining.push(i);
	}

	return ret;
}
int main()
{
	int num;
	cin >> num;

	int tmp;
	height.push_back(0);
	for (int i = 1; i <= num; i++)
	{
		cin >> tmp;
		height.push_back(tmp);
	}

	cout << solveStack() << "\n";
}