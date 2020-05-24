#include <bits/stdc++.h>
#define int long long
#define pii pair<long long, long long>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define endl '\n'
using namespace std;

int N, M;
bool visited[1001];
vector<pii> adj[1001];//가중치, 목적지
priority_queue<pii, vector<pii>, greater<pii>> pq;//가중치기준 최소힙

int prim() {
	int ans = 0;
	pq.push(mp(0, 1));
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (visited[cur.ss]) continue;//방문했으면 거른다.
		visited[cur.ss] = true;
		ans += cur.ff;
		for (auto& next : adj[cur.ss]) {
			if (!visited[next.ss]) {
				pq.push(next);
			}
		}
	}
	return ans;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back(mp(c, b));
		adj[b].push_back(mp(c, a));
	}
	int result = prim();
	cout << result << endl;

	return 0;
}