// 학생들의 짝지어 줄때 친구들로만 짝을 지어주는 경우의 수
#include<iostream>
#include<algorithm>

using namespace std;

int studentNum, pairNum;
int areFriends[10];

int waysToFriendPair(int taken)
{
	// 쌍의 순서를 고정하여 답의 형태를 고정하는 방법
	int firstFree = -1;
	for (int i = 0; i < studentNum; i++)
	{
		if ((taken & (1 << i)) == 0)
		{
			firstFree = i;

			break;
		}
	}

	// 모두가 쌍이 지어졌을때
	if (firstFree == -1)
	{
		return 1;
	}

	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < studentNum; pairWith++)
	{
		// 아직 쌍이 아닌 두 학생이 친구일 때
		if ((taken & (1 << pairWith)) == 0 && ((areFriends[firstFree] & (1 << pairWith))))
		{
			// 디버깅
			/*cout << firstFree << " is firstFree " << pairWith <<
			  " is pairWith\n";*/

			  // 쌍을 지어줬을때
			taken ^= (1 << firstFree);
			taken ^= (1 << pairWith);
			ret += waysToFriendPair(taken);
			// 쌍을 짓지 않았을때
			taken ^= (1 << firstFree);
			taken ^= (1 << pairWith);
		}
	}
	return ret;
}
int main()
{
	int testCase;
	cin >> testCase;

	int tmp_first;
	int tmp_second;
	for (int i = 0; i < testCase; i++)
	{

		cin >> studentNum >> pairNum;
		int tmp;

		// 초기화
		for (int i = 0; i < studentNum; i++)
		{
			areFriends[i] = 0;
		}
		// 친구 정보 입력
		for (int pair = 0; pair < pairNum; pair++)
		{
			cin >> tmp_first >> tmp_second;
			if (tmp_first > tmp_second)
			{
				tmp = tmp_first;
				tmp_first = tmp_second;
				tmp_second = tmp;
			}
			areFriends[tmp_first] |= (1 << tmp_second);
		}
		// 답 출력
		cout << waysToFriendPair(0) << "\n";
	}

}