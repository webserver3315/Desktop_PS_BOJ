#include <bits/stdc++.h>
using namespace std;

int n;
int** dp;

//��ȭ�� - dp(n,c)=dp(n-1,c-1)+dp(n-1,c);
int DP(int r, int c) {//���κ��� levĭ, �·κ��� col. ������ ���� nC0�� nC1�� ����ϱ�� ��. �� c�� 1 �ø�.
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

	dp = (int**)malloc(sizeof(int*) * (n + 1));
	for (int i = 0; i < n + 1; i++) {
		dp[i] = (int*)malloc(sizeof(int) * (i + 1));
		memset(dp[i], -1, sizeof(int) * (i + 1));
	}

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