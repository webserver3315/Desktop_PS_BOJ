/*
낚시왕
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
	int z; int num; int r; int c; int s; int d;//z 우선해서 정렬토록
};

bool CprShark(Shark a, Shark b) {
	/*if (a.z > b.z)
		return true;
	return false;*/
	return a.z > b.z;//방향 헷갈리지않게 숙달하자
}

int R, C, M;
int nokoriShark;
deque<Shark> queueShark;
int fishingPos;
int field[MAX][MAX];

void patrolUD(Shark& shk) {
	int cnt = shk.s % R;
	if (shk.d == 1) {//상향상어
		int goup = shk.r - 1;
		if (cnt < goup) {//끝에 도달하기 부족하면
			shk.r -= cnt;
			return;
		}
		else { //방향바꾸기
			int godown = cnt - goup;
			shk.r = 1 + godown;
			shk.d = 2;
			return;
		}

	}
	else {//하향상어
		int godown = R - shk.r;
		if (cnt < godown) {//끝에 도달하기 부족하면
			shk.r += cnt;
			return;
		}
		else { //방향바꾸기
			int goup = cnt - godown;
			shk.r = R - goup;
			shk.d = 1;
			return;
		}
	}
}

void patrolRL(Shark& shk) {
	int cnt = shk.s % C;
	if (shk.d == 3) {//우향상어
		int goright = C - shk.c;
		if (cnt < goright) {//끝에 도달하기 부족하면
			shk.c += cnt;
			return;
		}
		else { //방향바꾸기
			int goleft = cnt - goright;
			shk.c = C - goleft;
			shk.d = 4;
			return;
		}

	}
	else {//좌향상어
		int goleft = shk.c - 1;
		if (cnt < goleft) {//끝에 도달하기 부족하면
			shk.c -= cnt;
			return;
		}
		else { //방향바꾸기
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