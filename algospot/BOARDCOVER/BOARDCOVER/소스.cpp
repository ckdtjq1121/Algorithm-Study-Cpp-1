//board�� ��� �κ��� L�� ����� ������� ���� ����� ���� ���ϴ� �˰���
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
		if (ny < 0 || ny >= height || nx < 0 || nx >= width) // ny, nx�� �迭 ������ ������ X
			ok = false;
		// (arrBoard[ny][nx] += delta) > 1 ��ȣ�� ġ�� ������ ���� ����� ���� �ʾ� ���� ��͸� Ÿ�� ��
		else if ((arrBoard[ny][nx] += delta) > 1)	// arrBoard[ny][nx]�� ���� �̹� 1(ä�����κ�)�̶�� X
			ok = false;
	}
	return ok;
}

int waysToCoverBoard()
{
	// ������ 0�� x, y�� ã�´�.
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

	if (y == -1) return 1;	// arrBoard[i][j] == 0�� ���� ���� �� ��� 1�� ä������. �Ѱ��� ����� ã�Ҵ�.

	// 4���� ����� ��� ��ͷ� �غ�
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