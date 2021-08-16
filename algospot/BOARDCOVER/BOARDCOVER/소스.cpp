//board의 흰색 부분을 L자 모양의 블록으로 덮는 경우의 수를 구하는 알고리즘
#include<iostream>
#include<vector>

using namespace std;



const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
};

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size())
			ok = false;
		else if ((board[ny][nx] += delta > 1))
			ok = false;
	}
	return ok;
}

int waysToCoverBoard(vector<vector<int>>& board)
{
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1)
			break;
	}

	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++)
	{
		if (set(board, y, x, type, 1))
			ret += waysToCoverBoard(board);

		set(board, y, x, type, -1);
	}
	return ret;
}
int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		vector<vector<int>> board;
		int height, width;
		cin >> height >> width;
		
		char tmp;
		for (int j = 0; j < height; j++)
		{
			vector<int> h;
			for (int k = 0; k < width; k++)
			{
				cin >> tmp;
				h.push_back((tmp == '.') ? 0 : 1);
			}
			board.push_back(h);
		}

		for (int j = 0; j < height; j++)
		{
			for (int k = 0; k < width; k++)
			{
				cout << board[j][k] << " ";
			}
			cout << "\n";
		}
		//cout << waysToCoverBoard(board) << "\n";
	}
	cout << "\n\n";
	
	return 0;
}