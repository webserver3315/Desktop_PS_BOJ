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
deque<pii> person;//����� �̵����
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

bool InBound(int r, int c) {//��������������
	if (r < 0 || c < 0 || r >= R || c >= C)
		return false;
	return true;
}

bool AtBound(int r, int c) {//�ⱸ�ΰ�?
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
				if (InBound(rrr, ccc) && field[rrr][ccc] == '.') {//����� �������� .�� J�� �Ǿ��ٰ� �ص�, �ű⸦ �¿� �ʿ�� ����. �̹� �ʾ��� �����̴�. �� ���� ����� ���ų� ���� �� ����. ���� ������ ��ĭ�� �¿� �ʿ䰡 �ִ�.
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