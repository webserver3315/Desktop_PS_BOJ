#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define MAX (int)1e3+5

using namespace std;

int t;
int R, C;
vector<string> field;
deque<pii> fire;
deque<pii> person;//사람의 이동경로
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

bool InBound(int r, int c) {//참조오류방지용
	if (r < 0 || c < 0 || r >= R || c >= C)
		return false;
	return true;
}

bool AtBound(int r, int c) {//출구인가?
	if (r == 0 || c == 0 || r == R - 1 || c == C - 1)
		return true;
	return false;
}

int GetOut() {
	int sec = 0;
	while (!fire.empty() || !person.empty()) {
		int fireRepeat = fire.size();
		while (fireRepeat--) {
			pii nowFire = fire.front();
			fire.pop_front();
			int rr = nowFire.ff; int cc = nowFire.ss;
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBound(rrr, ccc) && field[rrr][ccc] == '.') {//사람이 지나가서 .이 J가 되었다고 해도, 거기를 태울 필요는 없다. 이미 늦었기 때문이다. 그 불은 사람을 막거나 죽일 수 없다. 따라서 오로지 빈칸만 태울 필요가 있다.
					fire.push_back(mp(rrr, ccc));
					field[rrr][ccc] = 'F';
				}
			}
		}
		int personRepeat = person.size();
		while (personRepeat--) {
			pii nowPerson = person.front();
			person.pop_front();
			int rr = nowPerson.ff; int cc = nowPerson.ss;
			if (AtBound(rr, cc)) {
				return sec + 1;
			}
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (InBound(rrr, ccc) && field[rrr][ccc] == '.') {
					person.push_back(mp(rrr, ccc));
					field[rrr][ccc] = 'J';
				}
			}
		}
		sec++;
	}
	return -1;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> C >> R;
		field.clear(); fire.clear(); person.clear();
		for (int r = 0; r < R; r++) {
			string line;
			cin >> line;
			for (int c = 0; c < line.length(); c++) {
				char chr = line[c];
				if (chr == '@') {
					person.push_back(mp(r, c));
				}
				else if (chr == '*') {
					fire.push_back(mp(r, c));
				}
			}
			field.push_back(line);
		}
		int ans = GetOut();
		if (ans == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}