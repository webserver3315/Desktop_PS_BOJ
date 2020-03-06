#include <iostream>
#define DIV (int)1e9
//#define int long long
using namespace std;


int N;
int memo[10][101];

int DP(int k, int n) {
	if (k < 0 || k>9 || n<1 || n>N)//이거 n 제한 빼먹은데다가, if ret 이후에 설정한 탓에 삽질했다.
		return 0;
	int& ret = memo[k][n];
	if (ret)
		return ret;
	else if (n == 1 && k == 0) {
		ret = 0;
	}
	else if (n == 1) {
		ret = 1;
	}
	else {
		ret = (DP(k - 1, n - 1) + DP(k + 1, n - 1)) % DIV;
	}
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	/*for (int i = 0; i < 10; i++) {
		memo[i][1] = 1;
	}*/
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		//sum += DP(i, N);
		////sum += DP(i, N) % DIV;
		//sum %= DIV;
		sum = (sum + DP(i, N)) % DIV;
	}
	cout << sum << endl;
	return 0;
}