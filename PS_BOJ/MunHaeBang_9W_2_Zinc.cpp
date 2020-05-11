#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

bool connect(string a, string b) {
	if (a.size() > b.size()) swap(a, b);
	int asz = a.size(), bsz = b.size();
	if (bsz - asz > 1) return 0;

	int le = 0, ri = bsz - 1;
	while (le < asz && a[le] == b[le]) le++;
	if (asz == bsz) while (ri >= 0 && a[ri] == b[ri]) ri--;
	else while (ri - 1 >= 0 && a[ri - 1] == b[ri]) ri--;
	return le == ri;
}

int N;
queue<int> q;
string word[25000];
vector<int> adj[25000];
int ind[25000];
int longest[25000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> word[i];

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (connect(word[i], word[j])) {
				adj[i].push_back(j);
				ind[j]++;
			}

	//위상정렬 사용
	for (int i = 0; i < N; i++) if (ind[i] == 0) q.push(i);
	while (q.size()) {
		int cur = q.front(); q.pop();
		for (int nxt : adj[cur]) {
			longest[nxt] = max(longest[nxt], longest[cur] + 1);
			if (--ind[nxt] == 0) q.push(nxt);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++) ans = max(ans, longest[i]);
	cout << ans + 1 << '\n';
	return 0;
}