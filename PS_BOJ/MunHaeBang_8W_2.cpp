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
//int sum;
int mindiff=INT32_MAX;
vector<int> vct;
pii ans;

void dfs(int start, int sum) {//µÎ ÆÀÀÇ Â÷ÀÌ: abs(totsum-2*sum)
	if (start == n) {
		if (abs(totsum - 2 * sum) < mindiff) {
			mindiff = abs(totsum - 2 * sum);
			ans.ff = min(sum, totsum - sum);
			ans.ss = max(sum, totsum - sum);
		}
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

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		vct.push_back(tmp);
		totsum += tmp;
	}
	dfs(0,0);
	cout << ans.ff << " " << ans.ss << endl;

	return 0;
}