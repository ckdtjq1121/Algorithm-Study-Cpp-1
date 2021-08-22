#include <iostream>

using namespace std;

int main()
{
	int a = 0, b = 0;
	int c;
	cout << (c = a + b) << " " << ++a; 
	// expected ans => c = 0, a = 1
	// but real ans => c = 1, a = 1
	// ++a -> c = a + b -> cout << c << " " << a
}