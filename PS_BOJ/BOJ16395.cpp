#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n, k;
int memo[35][35];

/*
ÆÄ½ºÄ®ÀÇ »ï°¢Çü
nCr = (n-1)C(r-1) + (n-1)Cr
nCn==nC0==1
*/

int dp(int n, int r) {
	int& ret = memo[n][r];
	if (memo[n][r]) return memo[n][r];
	if (r == 0 || r == n) {
		ret = 1; return ret;
	}
	ret = dp(n - 1, r - 1) + dp(n - 1, r);
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;
	cout << dp(n - 1, k - 1) << endl;

	return 0;
}