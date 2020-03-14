#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int N, K;
vector<int> vct;
priority_queue<int> diff;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vct.push_back(tmp);
	}
	for (int i = 1; i < N; i++) {
		int dif = vct[i] - vct[i - 1];
		diff.push(dif);
	}
	for (int i = 0; i < K - 1; i++) {
		diff.pop();
	}
	int ans = 0;
	while (!diff.empty()) {
		ans += diff.top();
		diff.pop();
	}
	cout << ans << endl;
	return 0;
}