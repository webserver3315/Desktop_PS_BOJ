#include <bits/stdc++.h>
#define int long long
#define pii pair<long long, long long>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define endl '\n'
#define mymax INT_MAX
using namespace std;

/*
최소비용구하기 문제.
int 내로 해결된다.
*/

int R, C;
int V, E;
int A, B;
int field[1001][1001];
vector<pii> adj[1000001];
bool visited[1000001];
int dist[1000001];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

int mkadd(int r, int c) {
	return r * C + c;
}

bool isIn(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C) return false;
	else return true;
}

void dik() {
	fill(dist, dist + V + 1, mymax);
	dist[A] = field[0][0];
	pq.push(mp(0, A));
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (visited[cur.ss]) continue;
		visited[cur.ss] = true;
		for (auto& next : adj[cur.ss]) {
			if (dist[next.ss] > dist[cur.ss] + next.ff) {//if문 구현 실수해서 디버깅에 10분 날렸다.
				//cout << dist[next.ss] << " 를 " << dist[next.ss] + next.ff << "로 업데이트" << endl;
				dist[next.ss] = dist[cur.ss] + next.ff;
				pq.push(mp(dist[next.ss], next.ss));
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	V = R * C; E = (R - 1) * C + (C - 1) * R;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> field[r][c];
		}
	}
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			int cur = mkadd(r, c);
			for (int i = 0; i < 4; i++) {
				int rr = r + dr[i]; int cc = c + dc[i];
				if (!isIn(rr, cc)) continue;
				int next = mkadd(rr, cc);
				adj[next].push_back(mp(field[r][c], cur));
				//adj[cur].push_back(mp(field[rr][cc], next));
			}
		}
	}
	int A = 0; int B = mkadd(R - 1, C - 1);
	dik();
	cout << dist[B] << endl;

	return 0;
}