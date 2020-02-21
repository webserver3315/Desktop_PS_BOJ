#include <iostream>
using namespace std;

/*
그리디하게 풀면 될 것 같은데.
일단 10의 9승까지니까

*/

int t;
int nokori;
int spended;

int main() {
	cin >> t;
	while (t--) {
		cin >> nokori;
		int spended = 0;
		while (nokori > 9) {
			int imaspended = nokori - nokori % 10;
			spended += imaspended;
			nokori %= 10;
			nokori += imaspended / 10;
		}
		spended += nokori;
		cout << spended << endl;
	}

	return 0;
}