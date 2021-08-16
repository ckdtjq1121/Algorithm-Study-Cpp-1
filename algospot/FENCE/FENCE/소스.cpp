#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> fence;
int num;

int solveToBruteForce()
{
	int ret = 0;
	int area;
	for (int i = 0; i < num; i++)
	{
		area = fence[i];
		for (int j = i + 1; j < num; j++)
		{
			if (fence[i] <= fence[j])
				area += fence[i];
			else
				break;
		}
		for (int j = i - 1; j >= 0; j--)
		{
			if (fence[i] <= fence[j])
				area += fence[i];
			else
				break;
		}
		//cout << i << " " << area << "\n"; // i 의 area 값을 확인하는 코드
		ret = max(ret, area);
	}
	return ret;
}

// left ~ right에서의 최대 maxArea를 찾는다
int findMaxArea(int left, int right)
{
	int mid = (left + right) / 2;

	if (left >= right)
		return 0;

	int ret = 0;
	int minHeight = 10000;
	int toLeft = mid;
	int toRight = mid + 1;
	while (true)
	{
		minHeight = min(minHeight, fence[toLeft]);
		minHeight = min(minHeight, fence[toRight]);

		int tmpArea = minHeight * (toRight - toLeft + 1);
		ret = max(ret, tmpArea);

		if (left == toLeft && right == toRight)
			break;

		if (left < toLeft && (right == toRight || fence[toLeft - 1] > fence[toRight + 1]))
			toLeft--;
		else if (toRight < right && (toRight == right || fence[toLeft - 1] <= fence[toRight + 1]))
			toRight++;
	}

	ret = max(ret, findMaxArea(left, mid));
	ret = max(ret, findMaxArea(mid + 1, right));

	return ret;
}
int solveToDivideAndConqure()
{
	int left = 0;
	int right = num - 1;

	int ret = 0;
	for (int i = 0; i < num; i++)
	{
		ret = max(ret, fence[i]);
	}

	return ret = max(ret, findMaxArea(left, right));
}

// segment Tree를 이용한 해법 - 미풀이
int solveToSegmentTree()
{
	int ret = 0;

	return ret;
}


int solveToStack()
{
	stack<int> remaining;
	fence.push_back(0); // fence[num] = 0 solveToStack()에서 필요함

	int ret = 0;
	int height, left, right, width;
	for (int i = 0; i <= num; i++)
	{
		if (remaining.empty())	// stack 이 비었을 때
		{
			remaining.push(i);
			continue;
		}

		// stack의 top 을 height으로 하는 넓이 구해주기
		while (!remaining.empty() && fence[remaining.top()] >= fence[i])
		{
			height = fence[remaining.top()];
			remaining.pop();

			if (!remaining.empty())
				left = remaining.top();
			else
				left = -1;

			right = i;

			width = right - left - 1;
			cout << "h : " << height << " w : " << width << "\n";
			ret = max(ret, height * width);
		}

		// stack에 i번째 원소 추가
		remaining.push(i);
	}

	
	return ret;
}

int main()
{
	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		cin >> num;
		int tmp;
		for (int i = 0; i < num; i++)
		{
			cin >> tmp;
			fence.push_back(tmp);
		}

		//cout << solveToBruteForce() << "\n"; // n^n 이지만 아슬아슬하게 통과
		cout << solveToDivideAndConqure() << "\n"; // n log n 이어야 하는대 시간초과
		//cout << solveToSegmentTree() << "\n"; // log n ^ 2
		//cout << solveToStack() << "\n"; // 오답

		fence.clear(); // vector를 전역변수로 두고 쓸시 다 사용 후 초기화 하는 습관을 가지자
	}
}