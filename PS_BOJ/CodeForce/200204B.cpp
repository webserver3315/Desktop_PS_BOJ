#include <iostream>
using namespace std;

/*
�׸����ϰ� Ǯ�� �� �� ������.
�ϴ� 10�� 9�±����ϱ�

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