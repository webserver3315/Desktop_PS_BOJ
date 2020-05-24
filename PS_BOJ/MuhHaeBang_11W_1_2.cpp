#include <bits/stdc++.h>
#define endl '\n'
#define int long long
#define pii pair<long long, long long>
#define ppiii pair<pair<long long, long long>, long long>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
using namespace std;

int N;
vector<ppiii> vct;
int memo[1001];
int par[1001];//부모노드

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		vct.push_back(mp(mp(a, b), i));
	}
	sort(vct.begin(), vct.end());

	memset(par, -1, sizeof(par));

	int fin = 0;
	int maxlen = 1;
	for (int i = 0; i < N; i++) {
		memo[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (vct[i].ff.ss < vct[j].ff.ss && memo[j] + 1>memo[i]) {
				memo[i] = memo[j] + 1;
				par[i] = j;
				fin = i;
				if (memo[i] >= maxlen) {
					maxlen = memo[i];
				}
			}
		}
	}
/*
	int k = 0;
	for (auto a : vct) {
		cout << k << " " << a.ff.ff << " " << a.ff.ss << " " << a.ss << " " << memo[k] << " " << par[k] << endl;
		k++;
	}*/


	int cur = fin;
	vector<int> ans;
	while (1) {
		ans.push_back(vct[cur].ss);
		if (par[cur] == -1) break;
		cur = par[cur];
	}
	cout << maxlen << endl;
	//cout << cur << endl;
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << endl;
	}

	return 0;
}