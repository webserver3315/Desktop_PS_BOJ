#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <ctime>
#define ff first
#define ss second
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define endl '\n'
#define MAX (int)55
#define INTINF 987654321
using namespace std;

int minans = INTINF;
int N, M;
int OriginalField[MAX][MAX];
int field[MAX][MAX];
int zerocnt;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
deque<pii> HikatsuseiVirus;
deque<pii> KatsuseiVirus;
deque<pii> KatsuseiChuVirus;

void printfield() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void fieldReset() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			field[r][c] = OriginalField[r][c];
		}
	}
	return;
}

bool InBound(int r, int c) {
	if (r < 0 || c < 0 || r >= N || c >= N)
		return false;
	return true;
}

int BakuHatsu() {
	int spreaded = 0;
	int sec = 0;
	for (int i = 0; i < KatsuseiVirus.size(); i++) {
		pii saishoVirus = KatsuseiVirus[i];
		int rr = saishoVirus.ff; int cc = saishoVirus.ss;
		field[rr][cc] = 3;
		KatsuseiChuVirus.push_back(saishoVirus);
	}
	while (zerocnt != spreaded && !KatsuseiChuVirus.empty()) {
		sec++;
		int cnt = KatsuseiChuVirus.size();
		while (cnt--) {
			pii vir = KatsuseiChuVirus.front();
			KatsuseiChuVirus.pop_front();
			int rr = vir.ff; int cc = vir.ss;
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBound(rrr, ccc) && field[rrr][ccc] == 0) {
					field[rrr][ccc] = sec + 3;
					KatsuseiChuVirus.push_back(mp(rrr, ccc));
					spreaded++;
				}
				else if (InBound(rrr, ccc) && field[rrr][ccc] == 2) {
					field[rrr][ccc] = sec + 3;
					KatsuseiChuVirus.push_back(mp(rrr, ccc));
				}
			}
		}
	}
	if (spreaded == zerocnt)
		return sec;
	else
		return -1;
}

int DFS(int start) {//ㅆㅂ 이게 문제였다.
	if (KatsuseiVirus.size() == M) {
		fieldReset();
		KatsuseiChuVirus.clear();
		int ans = BakuHatsu();
		if (ans != -1) {
			if (minans > ans) {
				minans = ans;
			}
		}
		return ans;
	}
	else {
		for (int i = start; i < HikatsuseiVirus.size(); i++) {
			pii virus = HikatsuseiVirus[i];
			KatsuseiVirus.push_back(virus);
			DFS(i + 1);
			KatsuseiVirus.pop_back();
		}
	}
	return 0;
}

int main() {
	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			OriginalField[r][c] = field[r][c];
			if (field[r][c] == 2) {
				HikatsuseiVirus.push_back(mp(r, c));
			}
			else if (field[r][c] == 0) {
				zerocnt++;
			}
		}
	}
	DFS(0);
	if (minans != INTINF)
		cout << minans << endl;
	else
		cout << -1 << endl;
	return 0;
}

/*
답은 전부 다 제대로 나오는데, 런타임에러가 뜬다.
어디서 떴을까.
*/