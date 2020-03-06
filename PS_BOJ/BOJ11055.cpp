#include <iostream>
#define MAX (int)1e4+1
using namespace std;

int N;
int maxmemo;
int val[MAX];
int memo[MAX];

//아래 DP함수는 38 19 의 수열에서 19면 스스로를 memo에 박지 못하고 바로 함수가 다른 loop로 넘어가버리는 문제가 있다.
void DP_BU(int k) {//BottomUp DP
	for (int n = k; n < N; n++) {
		for (int i = n - 1; i >= 0; i--) {
			if (val[i] < val[n]) {
				if (memo[n] < memo[i] + val[n]) {
					//cout << "memo[" << n << "] 은 memo[" << i << "] + val[" << n << "] 로 업데이트되어 " << memo[i] + val[n] << " 가 되었습니다." << endl;
					memo[n] = memo[i] + val[n];
					if (maxmemo < memo[n])
						maxmemo = memo[n];
				}
			}
		}
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