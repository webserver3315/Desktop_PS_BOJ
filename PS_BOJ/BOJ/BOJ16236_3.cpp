/*
�Ʊ���

���� ������ ������ �� ���ٴ� ���� ��������.
DFS�� �� �̵��켱������ ��, ��, ��, �� ������ for���� �����ٸ�
�������ľ��ϰ� �ڿ��� ù��°�� �ɸ��� �Ŀ밡�� ����Ⱑ �ɸ��� �ʰڴ°�?

������, �� ������ "�ִܰŸ� �����" ��� ������ �켱�̴�.

field ����Ž���� ���� ��� �Ŀ밡�� ����⿡ ���� ��ü �ִܰŸ��� ���ϰ�
��ü �ִܰŸ��� depth limit�� �����Ͽ�, dfs�� �����ϴµ� ù������ �ɸ� ����⸦ ä���Ѵ�.
Ž���� ���� field�� ������ ũ���� visited �迭�� �ʿ��ϴ�. ���� ���� �� ���� ���곶��ϱ�.

minDist ã��
�� �� �� ������Ž���� minDist�̸鼭 ũ�� ���� ������ pair queue�� ����ִ´�.
������ pairqueue front ���鿡 ���� minDist ���� depthlim���� ���ٰ������� ���θ� ����
���� ���ٺҰ��� �׳� pop. ���ٰ��ɽ� �װ����� �̵�
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define MAX 21
using namespace std;

int N;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };
int field[MAX][MAX];
bool visit[MAX][MAX];
int sr, sc;//�����ġ
int ssize = 2;//���ũ��
int eatkazu;//��������
int second;
bool hasEaten;//DFS�� ���������׸� ���ϰ� �������� �α׸� �����ϸ� �ȴ�.

typedef pair<int, int> pii;

void pf() {//printfield
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
}

void clearvisit() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			visit[r][c] = false;
		}
	}
}
/*
���� ù ����) ũ�Ⱑ ũ�ų� ���� ������ ������ �� ����.

�� ������ ������ �ִ�.
ũ�Ⱑ ���� ������ ���� ���� ������, ������ ���� �ִٴ� �̰� ���� ���峭�ΰ�..

�߰�) �� �߸� ������ �κ��� �ִ�.
�� �������� ���� ��, ���� ���� ����Ⱑ �ƴ϶�
������ ��ġ�� �������� ���� ��, ���� ���� ������...
�ƴϾƴ� �̰� ������ݳ�?

�ƴϴ�. ũ�Ⱑ 4�� ��
5 4 9 0 3 4
4 3 0 3 4 5
3 2 0 5 6 6
2 0 0 3 4 5
3 2 0 6 5 4
6 6 6 6 6 6
�� ��ġ���� 0,4�� �Ծ���ϴµ� �� �˰����� 1,1�� �Դ´�.

4�� ����)
���� �ҽ��� �ݷʴ� �̰��̴�
6
1 1 1 1 1 1
2 2 6 2 2 3
2 2 5 2 2 3
2 2 2 4 6 3
0 0 0 0 0 6
0 0 0 0 0 9
minDist�� ��������Ͽ� 5�ε�, ������ 5�� ������� 1�� ���ε� �� �� ����.
�̷��� �ּҺ��� ������ �ݿ��� ������ �ּҺ���� �ٸ� �� �ִ�.
*/

bool tadoritsuita = false;
bool CanItGoDFS(int r, int c, int ir, int ic, int depthlimit, int depth) {//r,s = ������, ir, is = ������ġ
	if (depthlimit == depth) {
		if (r != ir || c != ic) {
			return false;
		}
		tadoritsuita = true;
		return true;
	}
	for (int i = 0; i < 4; i++) {
		int rr = ir + dr[i]; int cc = ic + dc[i];
		if (rr >= N || cc >= N || rr < 0 || cc < 0 || field[rr][cc] > ssize || visit[rr][cc] == true) {//�����ʰ��ų� ū���ų� �湮�ߴ���� ������ �� ����
			continue;
		}
		visit[rr][cc] = true;
		CanItGoDFS(r, c, rr, cc, depthlimit, depth + 1);

		if (tadoritsuita)
			return true;

		visit[rr][cc] = false;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			if (field[r][c] == 9) {
				sr = r; sc = c;
			}
		}
	}

	pf();
	hasEaten = true;
	while (hasEaten) {
		int minDist = MAX * 3;
		hasEaten = false;
		visit[sr][sc] = true;

		deque<pii> dqpii;
		for (int r = 0; r < N; r++) {//minDist�� ã�� ����
			for (int c = 0; c < N; c++) {
				if (field[r][c] == 0 || ssize <= field[r][c])//�� �Ǵ� ���Դ°� �ɷ����Ѵ�
					continue;
				if (minDist > abs(sr - r) + abs(sc - c))
					minDist = abs(sr - r) + abs(sc - c);
			}
		}
		cout << "minDist�� " << minDist << endl;
		for (int r = 0; r < N; r++) {//minDist�� �Ŀ밡�ɰ�� ���� piiť�� ó�ִ´�
			for (int c = 0; c < N; c++) {
				if (minDist == abs(sr - r) + abs(sc - c) && field[r][c] != 0 && ssize > field[r][c]) {
					pii tmppii = { r,c };
					dqpii.push_back(tmppii);
				}
			}
		}

		if (dqpii.empty())//���̻�������ѰԾ��ٸ� ���͵�����
			break;

		while (!dqpii.empty()) {
			pii tmppii = dqpii.front();
			dqpii.pop_front();
			int rr = tmppii.first; int cc = tmppii.second;
			/*DFS�� ã�ڸ��� ��Ʈ���� �������ϴ�. BFS����.*/
			if (CanItGoDFS(rr, cc, sr, sc, minDist, 0)) {//���ް����ϸ�, �� ���� �� �ִٸ�
				field[rr][cc] = 9; field[sr][sc] = 0; sr = rr; sc = cc;
				hasEaten = true;
				second += minDist;
				eatkazu++;
				if (eatkazu == ssize) {
					eatkazu = 0;
					ssize++;
					cout << ssize << " �� ������ ���׷��̵�!" << endl;
				}
				break;//�� �̻� ť�� �� �ʿ����
			}
			clearvisit();
		}
		tadoritsuita = false;
		clearvisit();
	}

	cout << second << endl;

	return 0;
}

/*
for (int r = 0; r < N; r++) {
	for (int c = 0; c < N; c++) {

	}
}
*/