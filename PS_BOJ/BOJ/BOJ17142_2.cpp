#include <iostream>
#include <string>
#include <string.h>
#include <utility>
#include <algorithm>
#include <deque>
#include <vector>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define MAX (int)55
#define endl '\n'
using namespace std;

int t;
int N, M;
int OriginalField[MAX][MAX];
int field[MAX][MAX];//0:����, 1:��, 2:��Ȱ��, 3~: Ȱ��, �׸��� �ʰ���
int aidacnt;//����� ����
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
vector<pii> HikatsuseiVirus;//���� ��Ȱ�����̷�����ġ
vector<pii> KatsuseiVirus;//���� Ȱ�����̷�����ġ
deque<pii> KatsuseichuVirus;//Ȱ������ ���̷��� ť
int kotae = (int)1e5 + 1;

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
	for (pii stvir : KatsuseiVirus) {
		KatsuseichuVirus.push_back(stvir);
		int rr = stvir.ff; int cc = stvir.ss;
		field[rr][cc] = 3;
	}
	while (!KatsuseichuVirus.empty() && spreaded != aidacnt) {//Ȱ��ȭ���̷����� ������ ���ڴ� �ð�+3�̴�.
		/*cout << sec << " �� °: " << endl;
		printfield();*/
		sec++;
		int cnt = KatsuseichuVirus.size();
		while (cnt--) {
			pii virus = KatsuseichuVirus.front();
			KatsuseichuVirus.pop_front();
			int rr = virus.ff; int cc = virus.ss;
			for (int i = 0; i < 4; i++) {
				int rrr = rr + dr[i]; int ccc = cc + dc[i];
				if (field[rrr][ccc] == 0 && InBound(rrr, ccc)) {
					KatsuseichuVirus.push_back(mp(rrr, ccc));
					field[rrr][ccc] = sec + 3;
					spreaded++;
				}
				else if (field[rrr][ccc] == 2 && InBound(rrr, ccc)) {
					KatsuseichuVirus.push_back(mp(rrr, ccc));
					field[rrr][ccc] = sec + 3;
				}
			}
		}
	}
	if (spreaded == aidacnt)
		return sec;
	else
		return -1;
}

int DFS(int start) {
	if (KatsuseiVirus.size() == M) {//Ȱ�����̷��� ��ġ M �� Ȯ��������
		int ans;
		KatsuseichuVirus.clear();
		ans = BakuHatsu();
		//cout << "���ʼ���: ";
		for (pii firstvir : KatsuseiVirus) {
			int rr = firstvir.ff; int cc = firstvir.ss;
			//cout << rr << "," << cc << endl;
		}
		if (ans != -1) {
			if (kotae > ans) {
				//cout << "�ּ� �� ��� : " << ans << endl;
				kotae = ans;
			}
		}
		/*printfield();
		cout << endl;*/

		fieldReset();
		return ans;
	}
	else {
		for (int i = start; i < HikatsuseiVirus.size(); i++) {
			pii now = HikatsuseiVirus[i];
			KatsuseiVirus.push_back(now);
			DFS(i + 1);
			KatsuseiVirus.pop_back();
		}
	}
}

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);*/
	//cin >> t;
	t = 1;
	while (t--) {
		cin >> N >> M;
		kotae = (int)1e5 + 1;
		aidacnt = 0;
		HikatsuseiVirus.clear(); HikatsuseiVirus.clear(); KatsuseichuVirus.clear();
		for (int r = 0; r < N; r++) {
			memset(field[r], 0, MAX);
		}

		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				cin >> field[r][c];
				OriginalField[r][c] = field[r][c];
				if (field[r][c] == 2) {
					HikatsuseiVirus.push_back(mp(r, c));
				}
				else if (field[r][c] == 0) {
					aidacnt++;
				}
			}
		}
		DFS(0);
		if (kotae != (int)1e5 + 1)
			cout << kotae << endl;
		else
			cout << -1 << endl;
	}

	return 0;
}

/*
���� ���� �� ����� �����µ�, ��Ÿ�ӿ����� ���.
��� ������.
*/