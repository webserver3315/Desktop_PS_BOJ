#include <bits/stdc++.h>
using namespace std;

int n;
int dp[1000][1000];

//점화식 - dp(n,c)=dp(n-1,c-1)+dp(n-1,c);
int DP(int r, int c) {//위로부터 lev칸, 좌로부터 col. 통일을 위해 nC0을 nC1로 취급하기로 함. 즉 c를 1 올림.
	if (r<1 || c<1 || r>n || c>n)
		return 0;
	if (dp[r][c] != -1)
		return dp[r][c];
	if (c == 1 || r == c) {
		dp[r][c] = 1;
		return dp[r][c];
	}
	else if (c == 2 || r - 1 == c) {
		dp[r][c] = r - 1;
		return dp[r][c];
	}
	dp[r][c] = DP(r - 1, c - 1) + DP(r - 1, c);
	return dp[r][c];
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++)
		memset(dp[i], -1, sizeof(dp[i]));

	for (int r = 1; r <= n; r++) {
		for (int s = n - 1; s >= r; s--) {
			cout << ' ';
		}
		for (int c = 1; c <= r; c++) {
			cout << DP(r, c) << ' ';
		}
		cout << endl;
	}

	return 0;
}