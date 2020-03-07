#include <iostream>
#include <map>
#define endl '\n'
using namespace std;

int K, N;
//int num[1000];
map<int, int> dp;

int min(int a, int b) {
	return a < b ? a : b;
}

//9넘으면 처리 해야하고
//아예 답안나올때도 처리해야함
int DP(int n) {
	cout << n << " 등판 " << endl;
	if (n < 1 || n>32000)
		return 0;
	if (dp.find(n) != dp.end())
		return dp.find(n)->second;
	int a = DP(n - K) + 1;
	int b = DP(n / K) + DP(n % K);
	dp[n] = min(a, b);
	cout << n << " 의 메모 값은 " << dp[n] << endl;
	//return dp[n] = min(DP(n - K), DP(n / K)) + 1;
	return dp[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K >> N;
	dp[0] = 0;
	dp[1] = 2;
	dp[K] = 1;
	dp[K * 11] = 2;
	dp[K * 111] = 3;
	dp[K * 1111] = 4;
	dp[K * 11111] = 5;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		cout << DP(n) << endl;
	}


	return 0;
}