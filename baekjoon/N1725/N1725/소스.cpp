#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> height;
int solveStack()
{
	stack<int> remaining;
	height.push_back(0); // �������� 0�� �ִ� ������ height[remaining.top()] >= (height[i] = 0) �� ���� ��Ű�� ���ؼ�
	int ret = 0;
	// if( remaining.top() < height[i] ) remaining.push(i)
	// else if( remaining.empty()) remaining.push(i)
	// else if( !remaining.empty() && remaining.top()>= height[i] ) ret = max(ret, height[i] * width)
	// width ���ϴ� ��� 1 : remaining�� �� i�� �������� i������ width
	// width ���ϴ� ��� 2 : ���������� height�� �� Ŀ�� ��� �����Ƿ� ������+1 ���� ���� ��ġ����  width
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