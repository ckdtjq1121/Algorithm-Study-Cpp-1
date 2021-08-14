//board의 흰색 부분을 L자 모양의 블록으로 덮는 경우의 수를 구하는 알고리즘
#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
char board[20][20];
int height, width;
bool isFoolBoard(char** board)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == '.')
				return false;
		}
	}
	return true;
}
bool canAddBlock(char** board, int way) // 4가지 방법이 있음
{
	if (way == 1)
	{

	}
	else if (way == 2)
	{


	}
	else if (way == 3)
	{

	}
	else if (way == 4)
	{

	}
	else //  잘못된 경우
	{
		
	}
}
void addBlock(char** board, int y, int x, int way)
{

}
void removeBlock(char** board, int y, int x, int way)
{

}

int waysToCoverBoard(char** board)
{
	if (isFoolBoard(board))
		return 1;

	int ret = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (board[i][j] == '.')
			{
				for (int way = 1; way <= 4; way++)
				{
					if (canAddBlock(board, way))
					{
						addBlock(board, i, j, way);
						ret += waysToCoverBoard(board);
						removeBlock(board, i, j, way);
					}
				}
			}
		}
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
		
		memset(board, 0, sizeof(board));
		for (int j = 0; j < height; j++)
		{
			for (int k = 0; k < width; k++)
			{
				cin >> board[j][k];
			}
		}
	}

	cout << waysToCoverBoard(board) << "\n";
	return 0;
}