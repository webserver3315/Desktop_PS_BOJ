//저장한 뒤 일괄출력시키는 버전
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int n;
vector<int> inputs;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	while (n) {
		inputs.push_back(n);
		cin >> n;
	}
	for (auto a : inputs) {
		int cnt = 0;
		int cmp = 1;
		while (cmp * 2 <= a) {
			cmp *= 2;
			cnt++;
		}
		cout << cnt << endl;
		cin >> n;
	}

	return 0;
}