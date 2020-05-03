/*
집합
*/

#include <iostream>
#define endl '\n'
using namespace std;

int N;
int bm;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	while (N--) {
		string order;
		cin >> order;
		if (order == "add") {
			int n;
			cin >> n;
			bm |= (1 << n);
		}
		else if (order == "remove") {
			int n;
			cin >> n;
			bm &= ~(1 << n);
		}
		else if (order == "check") {
			int n;
			cin >> n;
			if (bm & (1 << n))
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (order == "toggle") {
			int n;
			cin >> n;
			bm ^= (1 << n);
		}
		else if (order == "all") {
			bm = (1 << 21) - 1;//20이 아니라 21임에 유의하라.
		}
		else if (order == "empty") {
			bm = 0;
		}
	}

	return 0;
}