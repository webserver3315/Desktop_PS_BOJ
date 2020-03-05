#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX (int)1e5+5
#define endl '\n'
using namespace std;

int t;
int N;
int sticker[MAX][3];
int memo[MAX][3];//0: 선택안했을 때, 1: 1번 선택했을 때, 2: 2번 선택했을 때

/*
memo[n][0]=max(memo[n-1][0],memo[n-1][1],memo[n-1][2])
memo[n][1]=max(memo[n-1][0],memo[n-1][2])+sticker[n][1]
memo[n][2]=max(memo[n-1][0],memo[n-1][1])+sticker[n][2]
*/

int DP(int n, int m) {
	//cout << n << ", " << m << " 함수에 진입" << endl;
	if (n < 0)
		return 0;
	int& ret = memo[n][m];
	if (ret != -1)
		return ret;
	switch (m) {
	case 0:
		ret = max(DP(n - 1, 1), DP(n - 1, 2));
		//ret = max(ret, DP(n - 1, 0));//혹시몰라서 박았는데, 필요없었다. 108ms->104ms로 단축.
		break;
	case 1:
		ret = max(DP(n - 1, 0), DP(n - 1, 2));
		ret += sticker[n][m];
		break;
	case 2:
		ret = max(DP(n - 1, 0), DP(n - 1, 1));
		ret += sticker[n][m];
		break;
	default://default가 맨 위에 있어도 되나?
		cerr << "ERROR" << endl;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> N;
		memset(sticker, -1, sizeof(sticker));
		memset(memo, -1, sizeof(memo));
		for (int i = 1; i < 3; i++) {
			for (int c = 0; c < N; c++) {
				cin >> sticker[c][i];
			}
		}
		int ans0 = DP(N - 1, 0);
		int ans1 = DP(N - 1, 1);
		int ans2 = DP(N - 1, 2);
		int ans = max(max(ans0, ans1), ans2);
		cout << ans << endl;
	}

	return 0;
}//뻘짓포함 38분 소요