#include <iostream>
#define MAX 100
#define endl '\n'
#define int long long//전혀 예상하지 못했는데, 타블로그보고 알았다. - https://m.blog.naver.com/occidere/220788046159
using namespace std;

int N;
int dp[MAX][2];

int DP(int n, int k) {
	if (n < 1)
		return 0;
	int& ret = dp[n][k];
	if (ret)
		return ret;
	if (k == 0) {
		return ret = DP(n - 1, 0) + DP(n - 1, 1);
	}
	else if (k == 1) {
		return ret = DP(n - 1, 0);
	}
	else {
		cerr << "ERROR" << endl;
		return -1;
	}
}
/*
짜고 생각해봤는데
이거 최우측만 건드리는게 아니라, 최좌측만 건드린다면
1차원의 memo배열로만 끝낼 수 있다.
조건에 의해 자연스럽게 최좌원소는 1로 고정되기 때문에
dp[n]=dp[n-1]+dp[n-2]가 된다.(차좌원소가 1,0일경우 각각 상징)
즉 피보나치다.
*/
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	dp[1][0] = 0;
	dp[1][1] = 1;
	cout << DP(N, 0) + DP(N, 1) << endl;
	return 0;
}