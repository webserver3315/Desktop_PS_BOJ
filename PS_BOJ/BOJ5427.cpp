/*
�ϴ� ������� Ż���Ű�� ���� �ִ��� ������ �Ѵ�.
�ƴϸ� ���� �ִ��� ������ �ϰ� ����� Ż���ų��?

���� ������ �Ѵ�. ���� ĭ���� ���������� ���ν�Ų��.
�� �� ���� �ð� �̻��� �������� ���ε� ĭ���� ��Ƽ� Ż���Ų��.
�����ڸ��� ��ġ�ٿ� ���� �� Ż��. ���н� IMPOSSIBLE
*/

#include <iostream>
#include <vector>
#include <utility>
#include <deque>
#include <string>
#define endl '\n'
#define MAX (int)1e3+1
#define pii pair<int,int>
#define pipii pair<int,pair<int,int>>//�ð�, ��ǥ
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)

#define AIDA -1
#define WALL -2
#define HITO -3
#define FIRE 0

using namespace std;

int t;
int R, C;
int field[MAX][MAX];
deque<pii> FireQ;
deque<pipii> AsiAto;//������
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
bool simai;


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
	else if (field[r][c] > time)
		return true;
	else
		return false;
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
			if (AtBoundary(rrr, ccc) && CanBurn(rrr, ccc)) {//�����ڸ���, ������̾�߸� ���� �� �ִ�.
				field[rrr][ccc] = field[rr][cc] + 1;
				FireQ.push_back(mp(rrr, ccc));
			}
		}
	}
}

void BFS_GetOut() {
	while (!AsiAto.empty() && !simai) {
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
					simai = true;
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
	cin >> t;
	while (t--) {
		cin >> C >> R;
		FireQ.clear(); AsiAto.clear();
		simai = false;
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
					cout << "�Է¿���" << endl;
					return -1;
				}
			}
		}
		BFS_FIRE();
		BFS_GetOut();
		if (!simai)
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}

/*
�̰͵� �޸��ʰ����.
�ϴ� �־��� ���ɿ� ���ؼ��� ���� ������ ����ϱ�� �ϴµ�,
���� ������?
���۸����� �� �ַ�ǵ��� ���´�.
���� �� ���̵� ���µ��ѵ�, ��� �޸����̰� ������ �ִٰ� Ȯ���غ���.
����ġ�⿡�� ���ʿ��� �б⸦ �߰������� �߶󳻴� ������ �ʿ��Ѱ�?

�׷��� 256�ް��� 128�ް��� ���� �����ߴٴ°� ������ ������ �ִٴ� �ɷ� ���Ǵµ�...
���� 1000*1000 �迭�̶�� �ص�.
6���ε� �̰� 100�ް�
��, ���.
Ǫ���� ����� �ȵǸ� ���簣���ѵ�.

Ȥ�� �� ó���� �߸��߳�?
�ϴ� ������� 1�ð� 45�� �ɷȴ�.
*/