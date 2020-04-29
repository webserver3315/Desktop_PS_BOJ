#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int t;
int n;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		if (n % 4 != 0) {
			cout << "No" << endl;
			continue;
		}
		cout << "YES" << endl;
		int k = n / 4;
		for (int i = 1; i <= 2 * k; i++) {
			cout << 2 * i << ' ';
		}
		for (int i = 1; i <= 2 * k - 1; i++) {
			cout << 2 * i - 1 << ' ';
		}
		cout << 5 + (k - 1) * 6 << endl;
	}

	return 0;
}