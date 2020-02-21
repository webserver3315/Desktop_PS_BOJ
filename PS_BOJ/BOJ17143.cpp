/*
���ÿ�
*/

#include <iostream>
#include <deque>
#include <algorithm>
#define endl '\n'
#define MAX 105
using namespace std;

/*

*/

struct Shark {
	int z; int num; int r; int c; int s; int d;//z �켱�ؼ� �������
};

bool CprShark(Shark a, Shark b) {
	/*if (a.z > b.z)
		return true;
	return false;*/
	return a.z > b.z;//���� �򰥸����ʰ� ��������
}

int R, C, M;
int nokoriShark;
deque<Shark> queueShark;
int fishingPos;
int field[MAX][MAX];

void patrolUD(Shark& shk) {
	int cnt = shk.s % R;
	if (shk.d == 1) {//������
		int goup = shk.r - 1;
		if (cnt < goup) {//���� �����ϱ� �����ϸ�
			shk.r -= cnt;
			return;
		}
		else { //����ٲٱ�
			int godown = cnt - goup;
			shk.r = 1 + godown;
			shk.d = 2;
			return;
		}

	}
	else {//������
		int godown = R - shk.r;
		if (cnt < godown) {//���� �����ϱ� �����ϸ�
			shk.r += cnt;
			return;
		}
		else { //����ٲٱ�
			int goup = cnt - godown;
			shk.r = R - goup;
			shk.d = 1;
			return;
		}
	}
}

void patrolRL(Shark& shk) {
	int cnt = shk.s % C;
	if (shk.d == 3) {//������
		int goright = C - shk.c;
		if (cnt < goright) {//���� �����ϱ� �����ϸ�
			shk.c += cnt;
			return;
		}
		else { //����ٲٱ�
			int goleft = cnt - goright;
			shk.c = C - goleft;
			shk.d = 4;
			return;
		}

	}
	else {//������
		int goleft = shk.c - 1;
		if (cnt < goleft) {//���� �����ϱ� �����ϸ�
			shk.c -= cnt;
			return;
		}
		else { //����ٲٱ�
			int goright = cnt - goleft;
			shk.c = 1 + goright;
			shk.d = 3;
			return;
		}
	}
}

void printfield() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> M;
	nokoriShark = M;
	for (int i = 1; i <= M; i++) {
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark newshark = { z,i,r,c,s,d };
		queueShark.push_back(newshark);
	}
	sort(queueShark.front(), queueShark.back(), CprShark);

	int imax = queueShark.size();
	for (int i = 0; i < imax; i++) {
		Shark imaShark = queueShark[i];
		int rr = imaShark.r; int cc = imaShark.c;
		field[rr][cc] = imaShark.num;
	}

	printfield();

	while (fishingPos++ <= C) {

	}

	return 0;
}