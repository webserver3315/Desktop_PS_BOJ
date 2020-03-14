#include <iostream>
using namespace std;

int main() {
	float a = 1e20;
	float b = -1e20;
	float c = 3.14;

	float d = a + b;
	float e = d + c;

	float f = b + c;
	float g = f + a;

	float h = a + c;
	float i = h + b;

	cout << (-1e20 + 1e20) + 3.14 << endl;
	cout << (-1e20 + 3.14) << endl;
	cout << 1e20 + (-1e20 + 3.14) << endl;

	return 0;
}