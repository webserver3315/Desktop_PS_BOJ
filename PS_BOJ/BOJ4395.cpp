#include <iostream>

using namespace std;

int t;
int x, y;
int cnt;
int k;

int main() {
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cnt = 0;
		k = 1;
		while (x < y) {
			x += k;
			cnt++;
			if (x < y) {
				y -= k;
				cnt++;
			}
			k++;
		}
		cout << cnt << endl;
	}
	return 0;
}