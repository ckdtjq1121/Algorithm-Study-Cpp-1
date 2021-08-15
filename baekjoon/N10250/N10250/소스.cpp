#include <iostream>

using namespace std;

int main()
{
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
	{
		int height, width, number;
		cin >> height >> width >> number;

		if (number % height != 0)
			cout << 100 * (number % height) + (number / height + 1) << "\n";
		else
			cout << 100 * height + number / height << "\n";
	}
}