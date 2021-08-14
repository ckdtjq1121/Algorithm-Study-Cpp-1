// �л����� ¦���� �ٶ� ģ����θ� ¦�� �����ִ� ����� ��
#include<iostream>
#include<algorithm>

using namespace std;

int studentNum, pairNum;
int areFriends[10];

int waysToFriendPair(int taken)
{
	// ���� ������ �����Ͽ� ���� ���¸� �����ϴ� ���
	int firstFree = -1;
	for (int i = 0; i < studentNum; i++)
	{
		if ((taken & (1 << i)) == 0)
		{
			firstFree = i;

			break;
		}
	}

	// ��ΰ� ���� ����������
	if (firstFree == -1)
	{
		return 1;
	}

	int ret = 0;
	for (int pairWith = firstFree + 1; pairWith < studentNum; pairWith++)
	{
		// ���� ���� �ƴ� �� �л��� ģ���� ��
		if ((taken & (1 << pairWith)) == 0 && ((areFriends[firstFree] & (1 << pairWith))))
		{
			// �����
			/*cout << firstFree << " is firstFree " << pairWith <<
			  " is pairWith\n";*/

			  // ���� ����������
			taken ^= (1 << firstFree);
			taken ^= (1 << pairWith);
			ret += waysToFriendPair(taken);
			// ���� ���� �ʾ�����
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

		// �ʱ�ȭ
		for (int i = 0; i < studentNum; i++)
		{
			areFriends[i] = 0;
		}
		// ģ�� ���� �Է�
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
		// �� ���
		cout << waysToFriendPair(0) << "\n";
	}

}