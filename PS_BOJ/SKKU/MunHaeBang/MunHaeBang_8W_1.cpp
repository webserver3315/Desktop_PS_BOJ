#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n, s;
int cnt;
vector<int> vct;

void dfs(int start, int sum) {//�ִ´� �Ǵ� �ȳִ´ٴ� 2������ ������ ����. ��ü ����Ž���� 2�� 20��. 1e6�̹Ƿ� ����.
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