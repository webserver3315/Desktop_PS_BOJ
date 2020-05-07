/*
일단 사람부터 탈출시키고 불을 최대한 번지게 한다.
아니면 불을 최대한 번지게 하고 사람을 탈출시킬까?

불을 번지게 한다. 밟은 칸마다 몇초인지를 각인시킨다.
그 뒤 지금 시간 이상의 정수값이 각인된 칸만을 밟아서 탈출시킨다.
가장자리에 터치다운 성공 시 탈출. 실패시 IMPOSSIBLE
*/

#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#define endl '\n'
#define MAX (int)1e3+1
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>//시간, 좌표
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)

#define AIDA -1
#define WALL -2
#define HITO -3
#define FIRE 0

using namespace std;

int R, C;
int field[MAX][MAX];
deque<pii> FireQ;
deque<pipii> AsiAto;//발자취
int sec = 0;//현재시각
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };



bool IsExit(int r, int c) {
	if (r == 0 || c == 0 || r == R - 1 || c == C - 1)
		return true;
	return false;
}

bool AtBoundary(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C)
		return false;
	return true;
}

bool CanGo(int r, int c, int time) {
	if (!AtBoundary(r, c))
		return false;

	if (field[r][c] == AIDA)
		return true;
	else if (field[r][c] <= time)
		return false;
	else
		return true;
}

bool CanBurn(int r, int c) {
	if (!AtBoundary(r, c))
		return false;

	if (field[r][c] == HITO || field[r][c] == AIDA)
		return true;
	else
		return false;
}

void BFS_FIRE() {
	while (!FireQ.empty()) {
		pii now = FireQ.front();
		int rr = now.ff; int cc = now.ss;
		FireQ.pop_front();
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (AtBoundary(rrr, ccc) && CanBurn(rrr,ccc)) {//가장자리고, 빈공간이어야만 번질 수 있다.
				field[rrr][ccc] = field[rr][cc] + 1;
				FireQ.push_back(mp(rrr, ccc));
			}
		}
	}
}

void BFS_GetOut() {
	while (!AsiAto.empty()) {
		pipii now = AsiAto.front();
		int nowtime = now.ff;
		pii nowpos = now.ss;
		int rr = nowpos.ff; int cc = nowpos.ss;
		AsiAto.pop_front();
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (CanGo(rrr, ccc, nowtime)) {
				if (IsExit(rrr, ccc)) {
					cout << nowtime + 2 << endl;
					exit(0);
				}
				pii nextpos = mp(rrr, ccc);
				pipii next = mp(nowtime + 1, nextpos);
				AsiAto.push_back(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		string line;
		cin >> line;
		for (int c = 0; c < C; c++) {
			if (line[c] == 'J' || line[c] == '@') {
				field[r][c] = HITO;
				pii pos = mp(r, c);
				pipii timepos = mp(0, pos);
				AsiAto.push_back(timepos);
			}
			else if (line[c] == 'F' || line[c] == '*') {
				field[r][c] = FIRE;
				FireQ.push_back(mp(r, c));
			}
			else if (line[c] == '.') {
				field[r][c] = AIDA;
			}
			else if (line[c] == '#') {
				field[r][c] = WALL;
			}
			else {
				cout << "입력오류" << endl;
				return -1;
			}
		}
	}
	BFS_FIRE();
	BFS_GetOut();
	cout << "IMPOSSIBLE" << endl;

	return 0;
}