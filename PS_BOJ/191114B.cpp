#include <iostream>
#define endl '\n'
using namespace std;

int t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	while (t--) {
		int a, b;
		bool isyes = false;
		cin >> a >> b;
		if (a > 3) {
			isyes = true;
		}
		else {
			if (a == 3) {
				if (b == 1 || b == 2 || b == 3) {
					isyes = true;
				}
			}
			else if (a == 2) {
				if (b == 1 || b == 2 || b == 3) {
					isyes = true;
				}
			}
			else if (a == 1) {
				if (b == 1) {
					isyes = true;
				}
			}
		}
		if (isyes)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}