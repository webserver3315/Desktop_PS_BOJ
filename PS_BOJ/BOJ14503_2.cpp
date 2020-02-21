#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <utility>
#define MAX (int)55
#define endl '\n'
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second

//후진==(방위+2)%4
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int t;
int R, C;
int rr, cc;
int mode;
int field[MAX][MAX];
bool cleaned[MAX][MAX];
int cnt;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

void printField() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
}

int CounterClockWise(int mode) {
	if (mode == NORTH)
		return WEST;
	else if (mode == EAST)
		return NORTH;
	else if (mode == SOUTH)
		return EAST;
	else
		return SOUTH;
	//return abs((mode - 1) % 4);
}

bool CanClean(int r, int c) {
	if (!cleaned[r][c] && field[r][c] == 0)//벽 아니고 청소도 안되어있으면
		return true;
	return false;
}

int Soji() {
	while (1) {
		if (rr == 0 || cc == 0 || rr == R - 1 || cc == C - 1)
			cout << "checkpoint" << endl;
		if (!cleaned[rr][cc]) {//1번 행위
			field[rr][cc] = 2;
			cleaned[rr][cc] = true;
			cnt++;
		}
		/*printField();
		cout << endl;*/
		for (int i = 0; i < 5; i++) {//2번 행위
			//cout << "i는 " << i << endl;
			mode = CounterClockWise(mode);//반시계회전
			int rrr = rr + dr[mode]; int ccc = cc + dc[mode];
			if (i == 4) {//한바퀴 돌았으면
				mode = CounterClockWise(mode);
				rrr = rr + dr[mode]; ccc = cc + dc[mode];//rrr,ccc==후진좌표
				mode = CounterClockWise(mode);
				mode = CounterClockWise(mode);
				if (field[rrr][ccc] == 1)//뒤가 벽이면 여기까지다.
					return cnt;
				else {//사면클린인데 뒤가 벽은 아닌 경우, 후진하고 2번부터 계속한다.
					rr = rrr; cc = ccc;
					break;
				}
			}
			if (!cleaned[rrr][ccc] && field[rrr][ccc] == 0) {//벽 아니고 청소 안된 칸 있으면 예스답.
				rr = rrr; cc = ccc;
				break;
			}
		}
	}
	return -1;
}


int main() {
	//cin >> t;
	t = 1;
	while (t--) {
		cnt = 0;
		cin >> R >> C;
		cin >> rr >> cc >> mode;
		for (int i = 0; i < MAX; i++) {
			memset(field[i], 0, MAX);
			memset(cleaned[i], false, MAX);
		}
		int numofzero = 0;
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> field[r][c];
				if (field[r][c] == 0)
					numofzero++;
			}
		}
		int ans = Soji();
		cout << cnt << endl;
		//cout << numofzero << endl;
		//cout << ans << endl;
	}
	return 0;
}