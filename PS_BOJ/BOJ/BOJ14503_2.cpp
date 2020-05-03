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

//����==(����+2)%4
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
	if (!cleaned[r][c] && field[r][c] == 0)//�� �ƴϰ� û�ҵ� �ȵǾ�������
		return true;
	return false;
}

int Soji() {
	while (1) {
		if (rr == 0 || cc == 0 || rr == R - 1 || cc == C - 1)
			cout << "checkpoint" << endl;
		if (!cleaned[rr][cc]) {//1�� ����
			field[rr][cc] = 2;
			cleaned[rr][cc] = true;
			cnt++;
		}
		/*printField();
		cout << endl;*/
		for (int i = 0; i < 5; i++) {//2�� ����
			//cout << "i�� " << i << endl;
			mode = CounterClockWise(mode);//�ݽð�ȸ��
			int rrr = rr + dr[mode]; int ccc = cc + dc[mode];
			if (i == 4) {//�ѹ��� ��������
				mode = CounterClockWise(mode);
				rrr = rr + dr[mode]; ccc = cc + dc[mode];//rrr,ccc==������ǥ
				mode = CounterClockWise(mode);
				mode = CounterClockWise(mode);
				if (field[rrr][ccc] == 1)//�ڰ� ���̸� ���������.
					return cnt;
				else {//���Ŭ���ε� �ڰ� ���� �ƴ� ���, �����ϰ� 2������ ����Ѵ�.
					rr = rrr; cc = ccc;
					break;
				}
			}
			if (!cleaned[rrr][ccc] && field[rrr][ccc] == 0) {//�� �ƴϰ� û�� �ȵ� ĭ ������ ������.
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