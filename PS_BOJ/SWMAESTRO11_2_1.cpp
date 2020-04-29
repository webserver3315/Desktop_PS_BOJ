#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int n;
vector<int> vct;
int memo[(int)1e5 + 5];
int maxval = -987654321;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		vct.push_back(tmp);
	}

	memo[0] = vct[0];
	maxval = memo[0];
	for (int i = 1; i < n; i++) {
		if (memo[i - 1] < 0) memo[i] = vct[i];
		else memo[i] = memo[i - 1] + vct[i];
		if (maxval < memo[i]) maxval = memo[i];
	}
	cout << maxval << endl;
	return 0;
}