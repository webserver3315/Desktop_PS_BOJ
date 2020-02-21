#include <iostream>
#include <vector>
//#include <string>
#include <utility>
#include <deque>

#define MAX (int)1e3+10
#define endl '\n'
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)

//#define FIRE 'F'
//#define HITO 'J'
//#define AIDA '.'
//#define WALL '#'

#define HITO 1
#define AIDA 2
#define WALL 3
#define FIRE 4

using namespace std;

/*
가로세로 1000이다.
총 칸은 6승이고,
만일 BFS로 가게 된다면 2바이트*6승보다 훨씬 클 것.
용량은 256메가이므로
256*6승.
비벼볼만한가?

뇌비우고 BFS로 일단 비벼보자.
*/

int t;
int R, C;
int JR, JC;
//vector<string> field;
int field[MAX][MAX];
//char field[MAX][MAX];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
deque<pii> clones;
deque<pii> willBurn;
int willBurnCnt;
int willCloneCnt;

void printField() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

bool AtBorder(int r, int c) {
	if ((r == 0 || r == R - 1 || c == 0 || c == C - 1) && field[r][c] != FIRE)
		return true;
	else if (r < 0 || c < 0 || r >= R || c >= 0) {
		//cout << "Boundary Error" << endl;
		return false;
	}
	return false;
}

bool InBorder(int r, int c) {
	if (r >= R || c >= C || r < 0 || c < 0)
		return false;
	return true;
}

bool CanBurn(int r, int c) {
	if (field[r][c] == WALL || field[r][c] == FIRE)
		return false;
	return true;
}

//나랑 똑같이 풀었는데, 이 쪽은 메모리초과가 안떴으니 참조 : https://jaimemin.tistory.com/834
int GetOut() {//같은 턴, 이번엔 불이 먼저 행동하도록 해보자.
	int sec = 0;
	while (!clones.empty()) {
		//전소부 먼저
		sec++;
		int willBurnCnt = willBurn.size();//다음 초에 번질 칸의 개수
		while (willBurnCnt--) {
			pii nowBurn = willBurn.front();
			int rr = nowBurn.ff; int cc = nowBurn.ss;
			willBurn.pop_front();
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBorder(rrr, ccc) && CanBurn(rrr, ccc)) {//번질 수 있고, 경계 내부라면
					field[rrr][ccc] = FIRE;
					willBurn.push_back(mp(rrr, ccc));
				}
			}
		}
		//탈출부가 2번째
		int willCloneCnt = clones.size();
		while (willCloneCnt--) {
			pii nowClone = clones.front();
			int rr = nowClone.ff; int cc = nowClone.ss;
			clones.pop_front();
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBorder(rrr, ccc) && field[rrr][ccc] == AIDA) {//경계 내부이고 빈공간이라면
					field[rrr][ccc] = HITO;
					clones.push_back(mp(rrr, ccc));
					if (AtBorder(rrr, ccc)) {
						cout << sec + 1 << endl;
						return 0;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> t;
	while (t--) {
		clones.clear();
		willBurn.clear();
		//cin >> R >> C;
		cin >> C >> R;
		for (int r = 0; r < R; r++) {
			string line;
			cin >> line;
			for (int c = 0; c < C; c++) {
				if (line[c] == 'J' || line[c] == '@') {
					JR = r;
					JC = c;
					field[r][c] = HITO;
				}
				else if (line[c] == 'F' || line[c] == '*') {
					willBurnCnt++;
					willBurn.push_back(mp(r, c));
					field[r][c] = FIRE;
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
		clones.push_back(mp(JR, JC));
		if (GetOut() == -1)
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}