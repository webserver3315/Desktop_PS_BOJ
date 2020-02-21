#include <iostream>
#include <deque>
#include <vector>
#include <string>
#include <utility>
#define MAX (int)50+5
#define endl '\n'
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;

int t;
int R, C;
int DR, DC;
int SR, SC;
vector<string> field;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
deque<pii> Hedgehog;
deque<pii> Water;

bool InBound(int r, int c) {
	if (r < 0 || c < 0 || r >= R || c >= C)
		return false;
	return true;
}

void printField() {
	for (string str : field) {
		cout << str << endl;
	}
	return;
}

int GetOut() {
	int sec = 0;
	while (!Hedgehog.empty() || !Water.empty()) {
		/*cout << sec << " 초 " << endl;
		printField();
		cout << endl;*/
		int watercnt = Water.size();
		while (watercnt--) {
			pii nowWater = Water.front();
			Water.pop_front();
			int rr = nowWater.ff; int cc = nowWater.ss;
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBound(rrr, ccc) && field[rrr][ccc] == '.' && !(rrr == DR && ccc == DC)) {
					//cout << "물 " << rrr << " " << ccc << " 로 진출 " << endl;
					Water.push_back(mp(rrr, ccc));
					field[rrr][ccc] = '*';
				}
			}
		}

		int hedgecnt = Hedgehog.size();
		while (hedgecnt--) {
			pii nowHedge = Hedgehog.front();
			Hedgehog.pop_front();
			int rr = nowHedge.ff; int cc = nowHedge.ss;
			if (rr == DR && cc == DC)
				return sec;
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBound(rrr, ccc) && field[rrr][ccc] == '.') {
					//cout << "고슴도치 " << rrr << " " << ccc << " 로 진출 " << endl;
					Hedgehog.push_back(mp(rrr, ccc));
					field[rrr][ccc] = 'S';
				}
			}
		}
		sec++;
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	//cin >> t;
	while (t--) {
		cin >> R >> C;
		field.clear(); Hedgehog.clear(); Water.clear();
		for (int r = 0; r < R; r++) {
			string line;
			cin >> line;
			field.push_back(line);
			for (int c = 0; c < line.length(); c++) {//S에서 D로
				if (line[c] == 'D') {
					DR = r; DC = c;
					field[r][c] = '.';
				}
				else if (line[c] == 'S') {
					SR = r; SC = c;
					Hedgehog.push_back(mp(r, c));
				}
				else if (line[c] == '*') {
					Water.push_back(mp(r, c));
				}
			}
		}
		int ans = GetOut();
		if (ans == -1)
			cout << "KAKTUS" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}