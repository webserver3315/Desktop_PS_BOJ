#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define endl '\n'
#define MAX (int)105

#define NORTH 1
#define	SOUTH 2
#define EAST 3
#define WEST 4

typedef struct Shark {
	int r; int c;
	int spd; int dir;
	int siz;
}shk;

int gotshk;
int R, C;
int M;
int aquarium[MAX][MAX];//해당 칸의 상어 수
bool dirChanged;
deque<shk> dqshk;

void printAqua() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << aquarium[r][c] << ' ';
		}
		cout << endl;
	}
}

bool shkcmp(const shk& a, const shk& b) {
	if (a.r < b.r)
		return true;
	else if (a.r == b.r)
		return a.c < b.r;
	else
		return false;
}

int turn(int dir) {
	switch (dir) {
	case NORTH:
		return SOUTH;
	case SOUTH:
		return NORTH;
	case EAST:
		return WEST;
	case WEST:
		return EAST;
	}
	return -1;
}

pii shkMove(int r, int c, int spd, int dir) {
	pii nowpos = mp(r, c);
	switch (dir) {
	case NORTH:
		if (r - spd < 0) {
			spd -= r;
			dirChanged = true;
			return mp(spd, c);
		}
		else {
			return mp(r - spd, c);
		}
	case SOUTH:
		if (R - 1 - r < spd) {
			spd -= R - 1 - r;
			dirChanged = true;
			return mp(R - 1 - spd, c);
		}
		else {
			return mp(r + spd, c);
		}

	case EAST:
		if (C - 1 - c < spd) {
			spd -= C - 1 - c;
			dirChanged = true;
			return mp(r, C - 1 - spd);
		}
		else {
			return mp(r, c + spd);
		}
	case WEST:
		if (c - spd < 0) {
			spd -= c;
			dirChanged = true;
			return mp(r, spd);
		}
		else {
			return mp(r, c - spd);
		}
	}
}

void GetOne(int fk) {
	bool got = false;
	for (int r = 0; r < R; r++) {//지상에 제일 가까운 1마리 낚기
		if (aquarium > 0) {
			shk tmpshk;
			for (int i = 0; i < dqshk.size(); i++) {
				if (dqshk[i].r == r && dqshk[i].c == fk) {
					tmpshk = dqshk[i];
					dqshk.erase(dqshk.begin() + i);
					got = true;
					break;
				}
			}
			if (got)
				gotshk += tmpshk.siz;
		}
	}
}

void SharkEat() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (aquarium[r][c] > 1) {//상어가 겹쳤다는 소리
				bool firstShk = true;
				shk maximumShk;
				int kasaneta = aquarium[r][c];
				for (int i = 0; i < dqshk.size() && kasaneta>0; i++) {
					shk nowshk = dqshk[i];
					if (nowshk.r == r && nowshk.c == c) {
						kasaneta--;
						dqshk.erase(dqshk.begin() + i);
						if (firstShk) {
							maximumShk = nowshk;
							firstShk = false;
						}
						else {
							aquarium[nowshk.r][nowshk.c]--;
							if (maximumShk.siz < nowshk.siz)
								maximumShk = nowshk;
						}
					}
				}
				dqshk.push_back(maximumShk);
			}
		}
	}
}

void SharkMove() {
	int cnt = dqshk.size();
	while (cnt--) {
		dirChanged = false;
		shk nowshk = dqshk.front();
		dqshk.pop_front();
		int rr = nowshk.r; int cc = nowshk.c; int spd = nowshk.spd; int dir = nowshk.dir; int siz = nowshk.siz;
		pii nextpos = shkMove(rr, cc, spd, dir);
		int rrr = nextpos.ff; int ccc = nextpos.ss;
		aquarium[rr][cc]--; aquarium[rrr][ccc]++;
		if (dirChanged)
			dir = turn(dir);
		shk newshk = { rrr,ccc,spd,dir,siz };
		dqshk.push_back(newshk);
	}
	sort(dqshk.begin(), dqshk.end(), shkcmp);
	SharkEat();
}

void solve() {
	for (int fk = 0; fk < C; fk++) {//fk=fishking 위치
		cout << fk << "에 있을 때" << endl;
		printAqua();
		cout << endl;
		GetOne(fk);
		SharkMove();
	}
}

int main() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		/*int r, int c, int spd, int dir, int siz;*/
		int r; int c; int spd; int dir; int siz;
		cin >> r >> c >> spd >> dir >> siz;
		if (dir == NORTH || dir == SOUTH)
			spd %= 2 * r;
		else
			spd %= 2 * c;
		shk newShark = { r,c,spd,dir,siz };
		aquarium[r][c]++;
		dqshk.push_back(newShark);
	}
	solve();
	cout << gotshk << endl;
	return 0;
}