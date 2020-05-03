#include <iostream>
#define MAX (int)1e6+1
#define DIV 15746
using namespace std;

int N;
int dp[MAX][2];

int DP(int n, int m) {
	if (n < 1)
		return 0;
	int& ret = dp[n][m];
	if (ret)
		return ret;
	if (m == 0) {
		return ret = (DP(n - 2, 0) + DP(n - 2, 1)) % DIV;
	}
	else if (m == 1) {
		return ret = (DP(n - 1, 0) + DP(n - 1, 1)) % DIV;
	}
	else {
		cerr << "ERROR" << endl;
		return -1;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	dp[1][0] = 0;
	dp[1][1] = 1;
	dp[2][0] = 1;
	dp[2][1] = 1;
	cout << (DP(N, 0) + DP(N, 1)) % DIV << endl;

	return 0;
}