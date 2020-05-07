#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

/*
bfs 각이다
*/

int t;
int n, e;
vector<int> adj[20002];
deque<int> dq;
int visited[20002];//1=청색 -1=적색 0=미방문

bool bfs() {
	dq.push_back(1); visited[1] = 1;
	while (!dq.empty()) {
		int cnt = dq.size();
		for (int i = 0; i < cnt; i++) {
			int now = dq.front(); dq.pop_front();
			int nowcolor = visited[now];
			for (auto next : adj[now]) {
				if (visited[next] == 0) {
					visited[next] = nowcolor * -1;
					dq.push_back(next);
				}
				else {
					if (visited[next] == nowcolor) {//안칠해져있으면서 다른 색으로 선점되었다면
						return false;
					}
					else continue;
				}
			}
		}
	}
	return true;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//cin >> t;
	t = 1;
	while (t--) {
		cin >> n >> e;
		memset(adj, 0, sizeof(adj)); memset(visited, false, sizeof(visited)); dq.clear();
		for (int i = 0; i < e; i++) {
			int a; int b;
			cin >> a >> b;
			adj[a].push_back(b); adj[b].push_back(a);
		}
		if (bfs()) {
			cout << "Y" << endl;
			//cout << "YES" << endl;
		}
		else {
			cout << "N" << endl;
			//cout << "NO" << endl;
		}
	}
	return 0;
}