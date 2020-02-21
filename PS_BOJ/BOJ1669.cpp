#include <iostream>

using namespace std;


int x, y;
int cnt;
int k;

int main() {
	cin >> x >> y;
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
	return 0;
}