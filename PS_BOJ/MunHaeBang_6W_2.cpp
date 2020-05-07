#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int n;
int memo[40] = { 0,1,5,11 };

int dp(int k) {
	if (k == 1 || k == 2 || k == 3) {
		return memo[k];
	}
	else if (memo[k] != 0) return memo[k];
	memo[k] = dp(k - 1) + 4 * dp(k - 2) + 2 * dp(k - 3);
	return memo[k];
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cout << dp(n) << endl;

	return 0;
}