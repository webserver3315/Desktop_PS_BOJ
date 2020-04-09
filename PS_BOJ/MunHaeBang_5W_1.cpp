#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n) {
		int cnt = 0;
		int cmp = 1;
		while (cmp * 2 <= n) {
			cmp *= 2;
			cnt++;
		}
		cout << cnt << endl;
		cin >> n;
	}

	return 0;
}