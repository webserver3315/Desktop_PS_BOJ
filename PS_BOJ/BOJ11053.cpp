/*
가장 긴 증가하는 부분수열

이거 시리즈가 많네. 2번문제는 골드2수준이고. 근데 2번문제는 똑같은데 1000에서 1000000으로 수열크기가 대폭 늘어났다.
그건 혹시 보통 dp가 아니라 수열과 쿼리처럼 풀어야하는건가;

부분수열은 연속할 필요가 없다는 점에 유의하라.
*/

#include <iostream>

#define MAX 1005

using namespace std;


int N;
int arr[MAX], memo[MAX];

int dp(int n) {
	if (memo[n] != 0) {
		return memo[n];
	}
	for (int idx = n-1; idx >= 0; idx--) {
		if (arr[n] > arr[idx]) {
			memo[n] = dp(idx) + 1;
			break;
		}
	}
	return memo[n];
}

int dp2(int n) {
	if (!memo[n]) {
		return memo[n];
	}
	for (int maxmemoidx = n - 1; maxmemoidx >= 0; maxmemoidx--) {
		if (arr[n] > arr[maxmemoidx]) {
			memo[n] = dp(maxmemoidx) + 1;
			break;
		}
	}
	return memo[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	memo[0] = 1;

	int max = 0;
	/*for (int i = 1; i < N; i++) {
		int tmp = dp(i);
		if (max < tmp)
			max = tmp;
	}*/
	cout << dp2(N-1) << endl;

	return 0;
}