#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX (int)1e4+5
#define endl '\n'
using namespace std;

int N;
vector<int> adj[MAX];
vector<int> value(MAX, -1);
vector<int> parent(MAX, -1);
vector<int> child[MAX];
//int memo[2][MAX];//0:isBad, 1:IsGood
int memo[MAX][2];//0:isBad, 1:IsGood
bool visited[MAX];

int DP(int nd, bool isGood) {
	int& ret = memo[nd][isGood];
	if (ret != -1)
		return ret;

	int tmp;
	int ans = 0;
	for (int next : child[nd]) {
		tmp = DP(next, false);
		if (!isGood) {
			tmp = max(tmp, DP(next, true));
		}
		else {
			tmp += value[nd];
		}
		ans += tmp;
	}
	ret = ans;
	return ret;
}

void maketree(int nd) {
	visited[nd] = true;
	for (int chd : adj[nd]) {
		if (!visited[chd]) {
			child[nd].push_back(chd);
			parent[chd] = nd;
			maketree(chd);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> value[i];
	}
	int a, b;
	for (int i = 1; i < N; i++) {
		cin >> a >> b;
		adj[a].push_back(b); adj[b].push_back(a);
	}
	memset(memo, -1, sizeof(memo));
	maketree(1);
	int ans = max(DP(1, true), DP(1, false));
	cout << ans << endl;

	return 0;
}