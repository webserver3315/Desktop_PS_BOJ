#include <bits/stdc++.h>
#define endl '\n'
#define MAX 53
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
using namespace std;

int T;
int R, C;
int field[MAX][MAX];
vector<pii> loc;//1�� ��ǥ ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		memset(field, 0, sizeof(field));
		loc.clear();
		cin >> R >> C;
		for (int r = 1; r <= R; r++) {
			for (int c = 1; c <= C; c++) {
				cin >> field[r][c];
				if (field[r][c] == 1)
					loc.push_back(mp(r, c));
			}
		}

		bool no = false;
		for (pii now : loc) {
			int rr = now.ff; int cc = now.ss;
			//1 �¿� �Ǵ� ���Ͽ� 0���� ������ġ�� 1�� �ϳ��� �ִٸ� no, �ƴϸ� yes
			if ((field[rr + 1][cc] == 0 && field[rr - 1][cc] == 0) || (field[rr][cc + 1] == 0 && field[rr][cc - 1] == 0)) {
				//cout << rr << ' ' << cc << "���� break" << endl;
				no = true;
				break;
			}
		}
		if (no)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}



	return 0;
}