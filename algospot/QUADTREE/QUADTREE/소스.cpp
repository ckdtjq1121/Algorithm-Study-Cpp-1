#include <iostream>
#include <string>
using namespace std;
const int MAX = 1000;

char* printReverseQT(const char* arr, int start, int end)
{
	char* ret = (char*)malloc(MAX * sizeof(char));
	int iter = 0;
	ret[iter++] = 'x';

	// 4분면 배열 동적할당
	char* quadrant[4];
	for (int i = 0; i < 4; i++)
	{
		quadrant[i] = (char*)malloc(MAX * sizeof(char));
	}

	// 4분면으로 나누기
	int num = 0;
	for (int i = start + 1; i < end; i++)
	{
		if (arr[i] == 'b' || arr[i] == 'w')
			quadrant[num][0] = arr[i];
		else if (arr[i] == 'x')
		{
			quadrant[num] = printReverseQT(arr, i, end);

			// printReverseQT(arr, i, end); 에서 iter를 움직인 만큼 i 움직여주기
			for (int j = 0; j < MAX; j++)
			{
				char c = quadrant[num][j];
				if (c != 'b' && c != 'w' && c != 'x')
				{
					i += j-1;
					break;
				}
			}
		}

		num++;
		if (num == 4)
			break;
	}

	// 상하 반전시키기 reverse up and down
	// 1 2 3 4 분면 순의 문자열을
	//    -->
	// 3 4 1 2 순으로 바꾸기
	int seq[4] = { 2, 3, 0, 1 };
	for (int i = 0; i < 4; i++)
	{
		if (iter == end)
			break;

		for (int j = 0; j < end; j++)
		{
			char c = quadrant[ seq[i] ][j];
			if (c == 'x' || c == 'b' || c == 'w')
				ret[iter++] = c;
			else
				break;
		}
	}
	return ret;

	//		  DEBUGING - const char* to char* 
	// 	   
	//char* ans = (char*)malloc(MAX * sizeof(char));
	//for (int i = 0; i < MAX; i++)
	//{
	//	char c = arr[i];
	//	if (c == 'x' || c == 'b' || c == 'w')
	//	{
	//		ans[i] = arr[i];
	//		continue;
	//	}
	//	break;
	//}
	//return ans;
}
int main()
{
	int testCase;
	cin >> testCase;

	string str;
	const char* arr;
	for (int i = 0; i < testCase; i++)
	{
		cin >> str;
		arr = str.c_str();

		if (arr[0] == 'b')
		{
			cout << 'b' << "\n";
			continue;
		}

		if (arr[0] == 'w')
		{
			cout << 'w' << "\n";
			continue;
		}

		char* ans = (char*)malloc(MAX * sizeof(char));
		ans = printReverseQT(arr, 0, str.size());

		for (int i = 0; i < str.size(); i++)
		{
			char c = ans[i];
			if (c == 'x' || c == 'b' || c == 'w')
			{
				cout << ans[i];
				continue;
			}		
		}
		cout << '\n';
	}

}