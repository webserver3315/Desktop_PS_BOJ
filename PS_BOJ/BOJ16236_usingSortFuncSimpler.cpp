/*
�Ʊ���

sort �� ���Լ��� �̿��Ͽ� �����ϰ� Ǫ�� ��
*/

#include <iostream>
#include <deque>
#include <vector>
#include <utility>//pair����
#include <algorithm>
#include <cstring>//memset ����

#define endl '\n'
#define MAX 21
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b) //�̰� A������ �����Ѱ�?
using namespace std;

struct shark {
	int r; int c;
	int size; int eatcnt;
	int time;
};

struct fish {
	int r; int c;
	int dist;
};

/*
�񱳼���:
�غ��Լ��� ��� ������ �� ������ ���Լ� ��� false�� ���� �����ϱ� ������, equal�� ��� �ϴ� false�� �����ؾ߸� ������ �߻����� �ʴ´�!
��sort �� ���� ���Լ��� bool��ȯ������ ���ڰ� �켱�õǸ� true, �����ϰų� ���ڰ� �켱�õǸ� false�� ��ȯ��� �����ϸ� �ȴ�.
1. �Ÿ��� ������ �����ҹ��ϰ� �켱�õȴ�
2. �Ÿ��� ������ ���, r�� ���� ��� �켱�õȴ�
3. r�� ������ ���, c�� ���� ��� �켱�õȴ�.
4. �Ÿ��� r�� c�� ��� ������ ���� ������ ����ȴ�.
*/
bool fishCompare(fish a, fish b) {//�켱������ ���� ��Ⱑ front(�ε���0) �� ������ �Ѵ�. ���ڰ� �켱�̸� true, ���ڰ� �켱�̸� false�̴�.
	if (a.dist <= b.dist) {
		if (a.dist == b.dist) {
			if (a.r <= b.r) {
				if (a.r == b.r) {
					if (a.c <= b.c) {
						if (a.c == b.c) {//������ equal�̶�� false �����°� �����̴�. �ƴϸ� �������.
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int N;
int field[MAX][MAX];
bool visit[MAX][MAX];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
shark S;
vector<fish> vctfish;

void BFS(int r, int c) {//r,c�κ��� ������ ���� �� �ִ� ������ �� ��� fish���� vctfish�� �ִ´�. fish���� �ʿ��� �ּҰ��� ������ ��������� ����ִ�. ������ ���� ���� visitó���ϰ� ���� �� memset������ �ʴ´�. 
	deque<pair<pair<int, int>, int>> dqppiii;
	dqppiii.push_back(mp(mp(r, c), 0));
	visit[r][c] = true;
	while (!dqppiii.empty()) {
		int rr = dqppiii.front().ff.ff; int cc = dqppiii.front().ff.ss;
		int dist = dqppiii.front().ss;
		dqppiii.pop_front();

		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr < 0 || ccc < 0 || rrr >= N || ccc >= N || visit[rrr][ccc])//�����ʰ��ų� visited�� �Ÿ���
				continue;
			if (field[rrr][ccc] == 0) {//������ ���� ���̸�
				visit[rrr][ccc] = true;
				dqppiii.push_back(mp(mp(rrr, ccc), dist + 1));
			}
			else if (field[rrr][ccc] < S.size) {//���� �� �ִ� ����
				fish tmpfish;
				tmpfish.r = rrr; tmpfish.c = ccc;
				tmpfish.dist = dist + 1;

				vctfish.push_back(tmpfish);
				visit[rrr][ccc] = true;
				dqppiii.push_back(mp(mp(rrr, ccc), dist + 1));
			}
			else if (field[rrr][ccc] == S.size) {//������ ���� �ִ� ����
				visit[rrr][ccc] = true;
				dqppiii.push_back(mp(mp(rrr, ccc), dist + 1));
			}
		}
	}
}

void solution() {
	while (true) {
		vctfish.clear();
		memset(visit, false, sizeof(visit));
		BFS(S.r, S.c);
		if (vctfish.empty()) {
			cout << S.time << endl;
			break;
		}
		else {
			sort(vctfish.begin(), vctfish.end(), fishCompare);

			int fr = vctfish.front().r; int fc = vctfish.front().c;//foodr, foodc
			field[fr][fc] = 9;
			field[S.r][S.c] = 0;
			S.r = fr; S.c = fc;
			S.eatcnt++;
			S.time += vctfish.front().dist;
			if (S.eatcnt == S.size) {
				S.eatcnt = 0;
				S.size++;
			}
		}
	}
}

void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			if (field[r][c] == 9) {
				S.r = r; S.c = c;
				S.size = 2; S.eatcnt = 0;
				S.time = 0;
			}
		}
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	return 0;
}