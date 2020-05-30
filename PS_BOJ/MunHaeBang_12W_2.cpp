#include <bits/stdc++.h>
#define endl '\n'
#include <bits/stdc++.h>
#define int long long
#define pii pair<long long, long long>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;

int N;
//char field[300][300];//x,y
string key;
map<pii, char> m;

bool UR(int x, int y, string& sch) {//X증가, Y유지
	for (char c : sch) {
		if (m.find(mp(x, y)) == m.end() || c != m[mp(x, y)]) {
			return false;
		}
		x++;
	}
	return true;
}
bool UL(int x, int y, string& sch) {//X감소, Y증가
	for (char c : sch) {
		if (m.find(mp(x, y)) == m.end() || c != m[mp(x, y)]) {
			return false;
		}
		x--; y++;
	}
	return true;
}
bool U(int x, int y, string& sch) {//X유지, Y증가
	for (char c : sch) {
		if (m.find(mp(x, y)) == m.end() || c != m[mp(x, y)]) {
			return false;
		}
		y++;
	}
	return true;
}
bool DL(int x, int y, string& sch) {//X감소, Y유지
	for (char c : sch) {
		if (m.find(mp(x, y)) == m.end() || c != m[mp(x, y)]) {
			return false;
		}
		x--;
	}
	return true;
}
bool DR(int x, int y, string& sch) {//X증가, Y감소
	for (char c : sch) {
		if (m.find(mp(x, y)) == m.end() || c != m[mp(x, y)]) {
			return false;
		}
		x++; y--;
	}
	return true;
}
bool D(int x, int y, string& sch) {//X유지, Y감소
	for (char c : sch) {
		if (m.find(mp(x, y)) == m.end() || c != m[mp(x, y)]) {
			return false;
		}
		y--;
	}
	return true;
}

bool SearchAll(int x, int y, string& sch) {//오른위, 오른아래, 왼위, 왼아래, 위, 아래 방향 모두 수색. 하나라도 맞으면 true.
	if (U(x, y, sch)) return true;
	if (UR(x, y, sch)) return true;
	if (UL(x, y, sch)) return true;
	if (D(x, y, sch)) return true;
	if (DR(x, y, sch)) return true;
	if (DL(x, y, sch)) return true;
	return false;
}

void searchMap(string& sch) {
	for (auto& a : m) {
		if (a.second == sch[0]) {
			if (SearchAll(a.ff.ff, a.ff.ss, sch)) {
				cout << a.ff.ff << " " << a.ff.ss << endl;
				return;
			}
		}
		else continue;
	}
	cout << -1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	string tmp;
	cin >> tmp;
	m.insert(mp(mp(0, 0), tmp[0]));

	for (int r = 1; r < N; r++) {
		int x = 0; int y = r;
		cin >> tmp;
		int i = 0;
		while (y != 0) {//y줄이면서 x올리기
			m.insert(mp(mp(x, y), tmp[i])); i++;
			y--; x++;
		}
		while (y != -1 * r) {//y줄이면서 x유지
			m.insert(mp(mp(x, y), tmp[i])); i++;
			y--;
		}
		while (x != 0) {//y유지하면서 x감소
			m.insert(mp(mp(x, y), tmp[i])); i++;
			x--;
		}
		while (y != 0) {//y 증가하면서 x 감소
			m.insert(mp(mp(x, y), tmp[i])); i++;
			x--; y++;
		}
		while (y != r) {//x 유지하면서 y 증가
			m.insert(mp(mp(x, y), tmp[i])); i++;
			y++;
		}
		while (x != 0) {//x 증가하면서 y 유지
			m.insert(mp(mp(x, y), tmp[i])); i++;
			x++;
		}
	}
	cin >> key;
	searchMap(key);
	//cout << "END" << endl;
	return 0;
}