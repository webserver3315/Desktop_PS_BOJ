#include <iostream>
#define MAX 1001
#define DIV 10007
using namespace std;

int N, K;
int memo[MAX][MAX];

int DP(int n, int k) {
	int& ret = memo[n][k];
	if (ret != 0)
		return ret;
	if (n < 1)
		return 0;

	if (k == 0) {
		ret = 1;
		return ret;
	}
	else if (k == 1) {
		ret = n;
		return ret;
	}
	else {
		//ret = DP(n - 1, k - 1) % DIV + DP(n - 1, k) % DIV;
		//ret = (DP(n - 1, k - 1) % DIV + DP(n - 1, k) % DIV) % DIV;
		ret = (DP(n - 1, k - 1) + DP(n - 1, k)) % DIV;
		return ret;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	if (K > N - K)
		K = N - K;
	cout << DP(N, K) << endl;
	return 0;
}