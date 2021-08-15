#include <iostream>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	int db[11][10];	// db[a][b] : a^b % 10 �� ��
	int dbPeriod[11];	// db[a][b] �� ���� db[a][1] �� �Ǵµ� ���� �ɸ��� �ֱ�
	bool finded = false;
	for (int i = 1; i <= 10; i++)
	{
		db[i][1] = i % 10;
		finded = false;
		for (int j = 2; j < 10; j++)
		{
			db[i][j] = (db[i][j - 1] * i) % 10;		// db ���ϱ�
			if (!finded && db[i][j] == db[i][1])	// dbPeriod�� ù��° �ֱ⸦ ã�Ƽ� �����Ѵ�.
			{
				dbPeriod[i] = j-1;
				finded = true;
			}
		}
	}
	
	//// db�� dbPeriod ���� Ȯ���ϴ� �ڵ�
	//for (int i = 1; i <= 10; i++)
	//{
	//	
	//	for (int j = 1; j < 10; j++)
	//	{
	//		cout << db[i][j] << " ";
	//	}
	//	cout << "           " << dbPeriod[i] << "\n\n";
	//}

	for (int i = 0; i < testCase; i++)
	{
		int a, b;
		cin >> a >> b;

		a %= 10;
		if (a == 0)	// ���� ��� �߰�
		{
			cout << 10 << "\n";
			continue; // break�� �ٸ� testCase �� ������� ����
		}
		b %= dbPeriod[a];
		if (b == 0)
			b = dbPeriod[a];
		cout << db[a][b] << "\n";

	}
}