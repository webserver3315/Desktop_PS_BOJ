#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int N;
deque<int> diff;
deque<int> divisable;

int solve() {

	for (int i = 0; i < divisable.size()-1; i++) {
		int tmp = divisable[i + 1] - divisable[i];
		diff.push_front(tmp);
	}
	int ret = 0;
	for (int i = 0; i < diff.size(); i++) {
		ret += diff[i] * divisable[i+1];
	}
	ret++;
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			divisable.push_front(i);
		}
	}
	for (auto a : divisable) {
		divisable.push_front(N / a);
	}
	reverse(divisable.begin(), divisable.end());

	int ans = solve();
	cout << ans << endl;

	return 0;
}