#include <bits/stdc++.h>
#define pii pair<long long, long long>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define int long long
#define endl '\n'
using namespace std;

int n;
int totsum;
int mindiff = INT32_MAX;
vector<int> vct;
pii ans;
bool picked[21];

void dfs(int cur, int sum) {
	if (cur >= n) {
		if (abs(totsum - 2 * sum) < mindiff) {
			mindiff = abs(totsum - 2 * sum);
			ans.ff = min(sum, totsum - sum);
			ans.ss = max(sum, totsum - sum);

			for (int i = 0; i < n; i++) {
				if (picked[i]) cout << vct[i] << "+";
			}
			cout << endl;

		}
		return;
	}
	picked[cur] = true;
	dfs(cur + 1, sum + vct[cur]);
	picked[cur] = false;
	dfs(cur + 1, sum);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		vct.push_back(tmp);
		totsum += tmp;
	}
	dfs(0, 0);
	cout << ans.ff << " " << ans.ss << endl;
	return 0;
}