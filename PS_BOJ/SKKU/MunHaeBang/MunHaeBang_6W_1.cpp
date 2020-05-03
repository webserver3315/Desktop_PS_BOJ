#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int memo[31];
int n;

int dp(int k) {
	if (memo[k] != 0) return memo[k];
	else {
		int ret = 0;
		for (int i = 0; i <= k - 1; i++) {
			//if (k == 3) {
			//	int a = ret; int b = dp(k - 1 - i); int c = dp(i);
			//	cout << "dp " << k << " : " << a << " += " << b << " * " << c << endl;
			//}
			ret += dp(k - 1 - i) * dp(i);
		}
		memo[k] = ret;
		return memo[k];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	memo[0] = 1; memo[1] = 1; memo[2] = 2;
	int ans = dp(n);
	cout << ans << endl;

	return 0;
}