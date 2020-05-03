#include <iostream>
#define MAX (int)1e4+1
using namespace std;

int N;
int maxmemo;
int val[MAX];
int memo[MAX];

void DP_BU(int k) {//BottomUp DP
	for (int n = k; n < N; n++) {
		int maxval = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (val[i] < val[n]) {
				if (maxval < memo[i])
					maxval = memo[i];
			}
		}
		memo[n] = maxval + val[n];
		if (maxmemo < memo[n])
			maxmemo = memo[n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> val[i];
	}
	memo[0] = val[0];
	DP_BU(0);
	cout << maxmemo;
	return 0;
}