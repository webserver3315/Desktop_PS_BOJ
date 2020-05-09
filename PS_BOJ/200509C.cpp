#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int t;
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		int tmp = k / (n - 1);
		if (k % (n - 1) == 0) {
			tmp--;
		}
		cout << k + tmp << endl;
	}

	return 0;
}