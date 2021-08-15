#include <iostream>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;

	int db[11][10];	// db[a][b] : a^b % 10 의 값
	int dbPeriod[11];	// db[a][b] 의 값이 db[a][1] 이 되는데 까지 걸리는 주기
	bool finded = false;
	for (int i = 1; i <= 10; i++)
	{
		db[i][1] = i % 10;
		finded = false;
		for (int j = 2; j < 10; j++)
		{
			db[i][j] = (db[i][j - 1] * i) % 10;		// db 구하기
			if (!finded && db[i][j] == db[i][1])	// dbPeriod의 첫번째 주기를 찾아서 저장한다.
			{
				dbPeriod[i] = j-1;
				finded = true;
			}
		}
	}
	
	//// db와 dbPeriod 값을 확인하는 코드
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
		if (a == 0)	// 기저 사례 추가
		{
			cout << 10 << "\n";
			continue; // break시 다른 testCase 를 사용하지 못함
		}
		b %= dbPeriod[a];
		if (b == 0)
			b = dbPeriod[a];
		cout << db[a][b] << "\n";

	}
}