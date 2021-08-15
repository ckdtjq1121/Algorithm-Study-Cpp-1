#include <iostream>

using namespace std;

int main()
{
	int hour = 0, minute = 0;
	cin >> hour >> minute;

	if (minute >= 45)
		minute -= 45;
	else
	{
		minute += 15;
		hour--;
		if (hour == -1)
			hour = 23;
	}

	cout << hour << " " << minute;
}