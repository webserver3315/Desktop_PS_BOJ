#include <iostream>
#include <vector>
//#include <string>
#include <utility>
#include <deque>

#define MAX (int)1e3+1
#define endl '\n'
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)

//#define FIRE 'F'
//#define HITO 'J'
//#define AIDA '.'
//#define WALL '#'

#define HITO 0
#define AIDA -1
#define WALL -2
#define FIRE -3

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
	if (r == 0 || r == R - 1 || c == 0 || c == C - 1)
		return true;
	else if (r < 0 || c < 0 || r >= R || c >= 0) {
		//cout << "Boundary Error" << endl;
		return false;
	}
	return false;
}

bool CanBurn(int r, int c) {
	if (field[r][c] == WALL || field[r][c] == FIRE)
		return false;
	return true;
}

//나랑 똑같이 풀었는데, 이 쪽은 메모리초과가 안떴으니 참조 : https://jaimemin.tistory.com/834
int GetOut() {//같은 턴, 사람이 먼저 행동하고 불이 다음에 번지고 1초가 흐른다.
	int willCloneCnt = 1;
	while (!willBurn.empty()) {//공간이 전소하거나, 탈출할 때까지
		//printField();
		//여기는 탈출부
		int couldCloneCnt = 0;
		while (willCloneCnt--) {
			pii nowClone = clones.front();
			int rr = nowClone.ff; int cc = nowClone.ss;
			clones.pop_front();
			if (AtBorder(rr, cc)) {//탈출구라면 최소시간 출력하고 프로그램 터트림
				cout << field[rr][cc] + 1 << endl;
				exit(0);
			}
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (!(rrr < 0 || ccc < 0 || rrr >= R || ccc >= C)&&field[rrr][ccc]==AIDA) {//경계 내부이고 빈공간이라면
					field[rrr][ccc] = field[rr][cc] + 1;
					clones.push_back(mp(rrr, ccc));
					couldCloneCnt++;
				}
			}

		}
		willCloneCnt = couldCloneCnt;



		//아래는 전소부
		int couldBurnCnt = 0;//다음 초에 번질 칸의 개수
		while (willBurnCnt--) {
			pii nowBurn = willBurn.front();
			int rr = nowBurn.ff; int cc = nowBurn.ss;
			willBurn.pop_front();
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (!(rrr < 0 || ccc < 0 || rrr >= R || ccc >= C || CanBurn(rrr, ccc))) {//번질 수 있고, 경계 내부라면
					willBurn.push_back(mp(rrr, ccc));
					couldBurnCnt++;
				}
			}
		}
		willBurnCnt = couldBurnCnt;
	}
}

int main() {
	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		string line;
		cin >> line;
		//field.push_back(line);
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
	GetOut();
	cout << "IMPOSSIBLE" << endl;
	return 0;
}
/*
반례 2가지 있고
결정적으로 메모리초과뜸
4 7
###.###
#....*#
#@....#
.######
5 5
.....
.***.
.*@*.
.***.
.....
*/