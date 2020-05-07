#include <iostream>
#define endl '\n'
using namespace std;

int R = 50;
int C = 50;

int main() {
	for (int r = 0; r < 26; r++) {
		cout << char('z'-r) << endl;
	}
	return 0;
}

//int main() {
//	for (int r = 0; r < R; r++) {
//		for (int c = 0; c < C; c++) {
//			if (r == 0 || c == 0 || r == R - 1 || c == C - 1)
//				cout << '0' << ' ';
//			else
//				cout << '0' << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}