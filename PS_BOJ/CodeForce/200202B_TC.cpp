#include <iostream>
using namespace std;
int main() {
	for (int a = 0; a <= 2; a++) {
		for (int b = 0; b <= 2; b++) {
			cout << 2 << endl;
			cout << a << " " << b << " " << endl;
		}
	}
	for (int a = 0; a <= 3; a++) {
		for (int b = 0; b <= 3; b++) {
			for (int c = 0; c <= 3; c++) {
				cout << 3 << endl;
				cout << a << " " << b << " " << c << " " << endl;
			}
		}
	}
	for (int a = 0; a <= 4; a++) {
		for (int b = 0; b <= 4; b++) {
			for (int c = 0; c <= 4; c++) {
				for (int d = 0; d <= 4; d++) {
					cout << 4 << endl;
					cout << a << " " << b << " " << c << " " << d << endl;
				}
			}
		}
	}
	return 0;
}