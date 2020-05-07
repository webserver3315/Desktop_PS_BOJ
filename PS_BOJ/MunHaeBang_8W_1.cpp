#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n, s;
int cnt;
vector<int> vct;

void dfs(int start, int sum) {//넣는다 또는 안넣는다는 2가지의 선지가 있음. 전체 완전탐색시 2의 20승. 1e6이므로 ㄱㄴ.
	if (sum == s) {
		cnt++;
		return;
	}
	for (int i = start; i < n; i++) {
		sum += vct[i];
		dfs(i + 1, sum);
		sum -= vct[i];
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		vct.push_back(tmp);
	}
	dfs(0, 0);
	cout << cnt << endl;

	return 0;
}