#include <iostream>
#define DIV 10007
using namespace std;

int N;
int memo[10][1001];

int DP(int k, int n) {
	if (k == 8 && n == 3)
		cout << "kokoda" << endl;
	int& ret = memo[k][n];
	if (ret)
		return ret;
	int sum = 0;
	for (int kk = k; k < 10; k++) {
		int plus = DP(kk, n - 1);
		cout << k << " 랑 " << n << " 일 때, " << sum << " + " << plus << endl;
		sum += plus;
	}
	return ret = sum;
}

int DP2(int k, int n) {
	if (k > 9)
		return 0;
	int& ret = memo[k][n];
	if (ret)
		return ret;
	ret = (DP2(k, n - 1) + DP2(k + 1, n)) % DIV;
	//cout << k << " 랑 " << n << " 일 때, " << ret << endl;
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < 10; i++) {
		memo[i][1] = 1;
	}
	int ans = 0;
	DP2(0, N);
	for (int i = 0; i < 10; i++) {
		ans = (ans + DP2(i, N)) % DIV;//여기서 %DIV 안붙여서 삽질했다.
	}
	cout << ans << endl;
	return 0;
}