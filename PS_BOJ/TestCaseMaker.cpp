#include <iostream>
#define endl '\n'
using namespace std;

int R = 50;
int C = 50;

int main() {
	cout << "1000 1000" << endl;
	for (int r = 0; r < 1000; r++) {
		for (int c = 0; c < 1000; c++) {
			cout << r + c + 1 << ' ';
		}
		cout << endl;
	}
	return 0;
}
