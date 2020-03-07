#include <iostream>
#define MAX 100
#define endl '\n'
#define int long long//���� �������� ���ߴµ�, Ÿ��α׺��� �˾Ҵ�. - https://m.blog.naver.com/occidere/220788046159
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
¥�� �����غôµ�
�̰� �ֿ����� �ǵ帮�°� �ƴ϶�, �������� �ǵ帰�ٸ�
1������ memo�迭�θ� ���� �� �ִ�.
���ǿ� ���� �ڿ������� ���¿��Ҵ� 1�� �����Ǳ� ������
dp[n]=dp[n-1]+dp[n-2]�� �ȴ�.(���¿��Ұ� 1,0�ϰ�� ���� ��¡)
�� �Ǻ���ġ��.
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