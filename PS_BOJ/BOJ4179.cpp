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
���μ��� 1000�̴�.
�� ĭ�� 6���̰�,
���� BFS�� ���� �ȴٸ� 2����Ʈ*6�º��� �ξ� Ŭ ��.
�뷮�� 256�ް��̹Ƿ�
256*6��.
�񺭺����Ѱ�?

������ BFS�� �ϴ� �񺭺���.
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

//���� �Ȱ��� Ǯ���µ�, �� ���� �޸��ʰ��� �ȶ����� ���� : https://jaimemin.tistory.com/834
int GetOut() {//���� ��, ����� ���� �ൿ�ϰ� ���� ������ ������ 1�ʰ� �帥��.
	int willCloneCnt = 1;
	while (!willBurn.empty()) {//������ �����ϰų�, Ż���� ������
		//printField();
		//����� Ż���
		int couldCloneCnt = 0;
		while (willCloneCnt--) {
			pii nowClone = clones.front();
			int rr = nowClone.ff; int cc = nowClone.ss;
			clones.pop_front();
			if (AtBorder(rr, cc)) {//Ż�ⱸ��� �ּҽð� ����ϰ� ���α׷� ��Ʈ��
				cout << field[rr][cc] + 1 << endl;
				exit(0);
			}
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (!(rrr < 0 || ccc < 0 || rrr >= R || ccc >= C)&&field[rrr][ccc]==AIDA) {//��� �����̰� ������̶��
					field[rrr][ccc] = field[rr][cc] + 1;
					clones.push_back(mp(rrr, ccc));
					couldCloneCnt++;
				}
			}

		}
		willCloneCnt = couldCloneCnt;



		//�Ʒ��� ���Һ�
		int couldBurnCnt = 0;//���� �ʿ� ���� ĭ�� ����
		while (willBurnCnt--) {
			pii nowBurn = willBurn.front();
			int rr = nowBurn.ff; int cc = nowBurn.ss;
			willBurn.pop_front();
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (!(rrr < 0 || ccc < 0 || rrr >= R || ccc >= C || CanBurn(rrr, ccc))) {//���� �� �ְ�, ��� ���ζ��
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
				cout << "�Է¿���" << endl;
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
�ݷ� 2���� �ְ�
���������� �޸��ʰ���
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