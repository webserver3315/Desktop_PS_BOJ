#include <bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
using namespace std;

int t;
int N;
int kr, kc;//knight position
int mr, mc;//destination
int dr[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int dc[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int field[300][300];
deque<pii> buff;

bool isIn(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= N)
		return false;
	return true;
}

int BFS() {
	buff.push_back(mp(kr, kc));
	field[kr][kc] = 1;
	while (!buff.empty()) {
		int rr, cc; rr = buff.front().ff; cc = buff.front().ss;
		buff.pop_front();
		if (rr == mr && cc == mc) {
			return field[rr][cc] - 1;
		}
		for (int i = 0; i < 8; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (isIn(rrr, ccc) && field[rrr][ccc] == 0) {
				buff.push_back(mp(rrr, ccc));
				field[rrr][ccc] = field[rr][cc] + 1;
			}
		}
	}
	return -10;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(field, 0, sizeof(field)); buff.clear();
		cin >> N; cin >> kr >> kc; cin >> mr >> mc;
		cout << BFS() << endl;
	}

	return 0;
}