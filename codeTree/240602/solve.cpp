#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
#define MAX 101
using namespace std;

int R, C, T;
int field[MAX][MAX];
int gram;
int memo[MAX][MAX];
bool visited[MAX][MAX];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
deque<pii> dq;


bool isBound(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C) {
		return false;
	}
	else return true;
}

void BFS() {
	int cnt;
	dq.push_back(mp(0, 0));
	memo[0][0] = 0; visited[0][0] = true;
	while (!dq.empty()) {
		int run = dq.size();
		while (run--) {
			int rr = dq.front().ff; int cc = dq.front().ss;
			dq.pop_front();
			if (field[rr][cc] == 2) {
				int diff = abs(R - 1 - rr) + abs(C - 1 - cc);
				gram = memo[rr][cc] + diff;
			}
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (isBound(rrr, ccc) && !visited[rrr][ccc] && field[rrr][ccc]!=1) {
					visited[rrr][ccc] = true;
					memo[rrr][ccc] = memo[rr][cc] + 1;
					dq.push_back(mp(rrr, ccc));
				}
				else continue;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C >> T;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> field[r][c];
		}
	}

	BFS();

	int ans;
	if (gram == 0 && memo[R - 1][C - 1] == 0) {
		cout << "Fail" << endl;
		return 0;
	}
	else if (memo[R - 1][C - 1] == 0 || gram < memo[R - 1][C - 1]) {
		ans = gram;
	}
	else ans = memo[R - 1][C - 1];

	if (ans <= T) cout << ans << endl;
	else cout << "Fail" << endl;

	return 0;
}