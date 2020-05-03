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
		/*printfield();
		cout << endl;*/
		int cnt = KatsuseiChuVirus.size();
		sec++;
		while (cnt--) {
			pii vir = KatsuseiChuVirus.front();
			KatsuseiChuVirus.pop_front();
			int rr = vir.ff; int cc = vir.ss;
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBound(rrr, ccc) && field[rrr][ccc] == 0) {
					field[rrr][ccc] = 3 + sec;
					KatsuseiChuVirus.push_back(mp(rrr, ccc));
					spreaded++;
				}
				else if (InBound(rrr, ccc) && field[rrr][ccc] == 2) {
					field[rrr][ccc] = 3 + sec;
					KatsuseiChuVirus.push_back(mp(rrr, ccc));
				}
			}
		}
	}
	if (zerocnt == spreaded)
		return sec;
	else
		return -1;
}

void DFS(int start) {
	if (KatsuseiVirus.size() == M) {
		//cout << "새로운 시작" << endl;
		fieldReset();
		KatsuseiChuVirus.clear();
		int ans = BakuHatsu();
		if (ans != -1) {
			if (ans < minans) {
				//cout << "최저값 경신 : " << ans << endl;
				minans = ans;
			}
		}
		return;
	}
	else {
		for (int i = start; i < HikatsuseiVirus.size(); i++) {
			pii virus = HikatsuseiVirus[i];
			KatsuseiVirus.push_back(virus);
			DFS(i + 1);//여기서 런타임에러뜨지는 않겠지?
			KatsuseiVirus.pop_back();
		}
	}
}

int main() {
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			OriginalField[r][c] = field[r][c];
			if (field[r][c] == 0) {
				zerocnt++;
			}
			else if (field[r][c] == 2) {
				pii vir = mp(r, c);
				HikatsuseiVirus.push_back(vir);
			}
		}
	}
	DFS(0);
	if (minans == INTINF)
		cout << -1 << endl;
	else
		cout << minans << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;

}