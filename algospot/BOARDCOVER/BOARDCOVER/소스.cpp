//board의 흰색 부분을 L자 모양의 블록으로 덮는 경우의 수를 구하는 알고리즘
#include<iostream>


using namespace std;


int height, width;
int arrBoard[20][20];
const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool set(int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= height || nx < 0 || nx >= width) // ny, nx가 배열 밖으로 나가면 X
			ok = false;
		// (arrBoard[ny][nx] += delta) > 1 괄호를 치지 않으면 값이 계산이 되지 않아 무한 재귀를 타게 됨
		else if ((arrBoard[ny][nx] += delta) > 1)	// arrBoard[ny][nx]의 값이 이미 1(채워진부분)이라면 X
			ok = false;
	}
	return ok;
}

int waysToCoverBoard()
{
	// 아직도 0인 x, y를 찾는다.
	int y = -1, x = -1;
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			if (arrBoard[h][w] == 0)
			{
				y = h;
				x = w;
				break;
			}
		}
		if (y != -1)
			break;
	}

	if (y == -1) return 1;	// arrBoard[i][j] == 0인 값이 없다 즉 모두 1로 채워졌다. 한가지 방법을 찾았다.

	// 4가지 방법을 모두 재귀로 해봄
	int ret = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(y, x, type, 1))
			ret += waysToCoverBoard();

		set(y, x, type, -1);
	}
	return ret;
}
int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		cin >> height >> width;
		char tmp;
		for (int h = 0; h < height; h++)
		{
			for (int w = 0; w < width; w++)
			{
				cin >> tmp;
				arrBoard[h][w] = (tmp == '.') ? 0 : 1;
			}
		}

		cout << waysToCoverBoard() << "\n";
	}


	return 0;
}