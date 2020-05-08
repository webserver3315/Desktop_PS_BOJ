#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const int MAX = 2e5 + 1;
int N;
ll ans[MAX];
tuple<ll, ll, int> skill[MAX]; //(s, e, idx)
vector<int> tmp;

ll t[4 * MAX];
void modify(int p, int value) {
	for (t[p += 2 * MAX] += value; p > 1; p >>= 1)
		t[p >> 1] = t[p] + t[p ^ 1];
}
int query(int l, int r) {
	int ret = 0;
	for (l += 2 * MAX, r += 2 * MAX; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ret += t[l++];
		if (r & 1) ret += t[--r];
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll a, b; cin >> a >> b;
		skill[i] = { a, b, i };
		tmp.push_back(get<0>(skill[i]));
		tmp.push_back(get<1>(skill[i]));
	}

	//ÁÂÇ¥¾ÐÃà
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for (int i = 0; i < N; i++) {
		int a = lower_bound(tmp.begin(), tmp.end(), get<0>(skill[i])) - tmp.begin();
		int b = lower_bound(tmp.begin(), tmp.end(), get<1>(skill[i])) - tmp.begin();
		skill[i] = { a, b, i };
	}
	sort(skill, skill + N);

	for (int i = 0; i < N; i++) {
		ll s, e, idx;
		s = get<0>(skill[i]), e = get<1>(skill[i]), idx = get<2>(skill[i]);
		ans[idx] = query(s + 1, 2 * MAX);
		modify(e, 1);
	}
	for (int i = 0; i < N; i++) cout << ans[i] << '\n';
	return 0;
}