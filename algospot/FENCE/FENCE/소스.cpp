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
		//cout << i << " " << area << "\n"; // i �� area ���� Ȯ���ϴ� �ڵ�
		ret = max(ret, area);
	}
	return ret;
}

// left ~ right������ �ִ� maxArea�� ã�´�
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

// segment Tree�� �̿��� �ع� - ��Ǯ��
int solveToSegmentTree()
{
	int ret = 0;

	return ret;
}


int solveToStack()
{
	stack<int> remaining;
	fence.push_back(0); // fence[num] = 0 solveToStack()���� �ʿ���

	int ret = 0;
	int height, left, right, width;
	for (int i = 0; i <= num; i++)
	{
		if (remaining.empty())	// stack �� ����� ��
		{
			remaining.push(i);
			continue;
		}

		// stack�� top �� height���� �ϴ� ���� �����ֱ�
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

		// stack�� i��° ���� �߰�
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

		//cout << solveToBruteForce() << "\n"; // n^n ������ �ƽ��ƽ��ϰ� ���
		cout << solveToDivideAndConqure() << "\n"; // n log n �̾�� �ϴ´� �ð��ʰ�
		//cout << solveToSegmentTree() << "\n"; // log n ^ 2
		//cout << solveToStack() << "\n"; // ����

		fence.clear(); // vector�� ���������� �ΰ� ���� �� ��� �� �ʱ�ȭ �ϴ� ������ ������
	}
}