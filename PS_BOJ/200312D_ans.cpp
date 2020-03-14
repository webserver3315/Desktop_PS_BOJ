#include <bits/stdc++.h>
//#include <iostream>
//#include <vector>
//#include <utility>
//#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	vector<int> v(n);
	for (int i = 0; i < n; i++) v[i] = a[i] - b[i];
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int it = upper_bound(v.begin(), v.end(), -v[i]) - v.begin();
		it = max(it, i + 1);
		ans += n - it;
	}
	cout << ans << '\n';
	return 0;
}