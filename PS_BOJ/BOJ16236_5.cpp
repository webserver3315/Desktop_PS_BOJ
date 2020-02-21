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

/*
�̴�� ���� �� �ϴ� ��� �׽�Ʈ���̽������� ������ ������� ����ȴ�.
�׷���, �����̶�� ���´�.
���� 5�� ������ ���� ��, �ִ��� �����丵�� �غ���.
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <climits>//INT_MAX�� gcc ������ cmath�� ���� climits���� �����Ѵ�
#define endl '\n'
#define MAX 21
#define ff first
#define ss second
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

int HowManyStepsNeededBFS(int r, int c, int ir, int ic) {//r,s = ������, ir, is = ������ġ, ���ϰ�: ���� ��(���� �Ұ����ϸ� 0 ���). ����� r,c ��ġ�� ������ �����ϱ⸸ �ϸ� ���� �� ������ ����� ����̴�.
	typedef pair<int, pii> pipii;
	deque<pipii> dqpipii;
	pii startpos = { ir,ic };
	pipii start = { 0,startpos };
	dqpipii.push_back(start);
	while (!dqpipii.empty()) {
		pipii nowpos = dqpipii.front();
		dqpipii.pop_front();
		int nowstep = nowpos.ff; int rr = nowpos.ss.ff; int cc = nowpos.ss.ss;
		if (rr == r && cc == c)//��ֹ� ������ ���� �����ϴ��� BFS�� ù������ ������ �� ���������� ����ȴ�.
			return nowstep;
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr >= N || ccc >= N || rrr < 0 || ccc < 0 || field[rrr][ccc] > ssize || visit[rrr][ccc] == true) {//�����ʰ��ų� ū���ų� �湮�ߴ���� ������ �� ����
				continue;
			}
			visit[rrr][ccc] = true;
			pii gopos = { rrr,ccc };
			pipii go = { nowstep + 1,gopos };
			dqpipii.push_back(go);
		}
	}
	return 0;
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

	/*pf();
	cout << endl;*/
	while (true) {
		int minDist = INT_MAX;//6��° ���� : �����ߴµ� MAX*2�� �ؼ� ��������.
		visit[sr][sc] = true;

		deque<pii> dqpii;
		for (int r = 0; r < N; r++) {//1. minDist�� ã�´�.
			for (int c = 0; c < N; c++) {
				if (field[r][c] == 0 || ssize <= field[r][c])//�� �Ǵ� ���Դ°� �ɷ����Ѵ�
					continue;
				int dist = HowManyStepsNeededBFS(r, c, sr, sc);
				if (dist != 0 && minDist > dist)//5��° ����: 0 �ƴϾ���Ѵٴ°� �����ߴ�;
					minDist = dist;
				clearvisit();
			}
		}
		//cout << "minDist�� " << minDist << endl;
		if (minDist == INT_MAX)
			break;
		for (int r = 0; r < N; r++) {//2. ���� �� �����鼭 minDist�� ���� �Ÿ��� �ִ� ��⸦ ���� ť�� �ִ´�
			for (int c = 0; c < N; c++) {
				if (field[r][c] != 0 && ssize > field[r][c]) {//�� �ƴϰ� ������ �ݵ�� �����鼭
					int dist = HowManyStepsNeededBFS(r, c, sr, sc);
					if (dist == minDist) {//�����Ÿ��� �ִܰŸ��� ������ ���� �Ŀ��ĺ��̴�.
						pii tmppii = { r,c };
						dqpii.push_back(tmppii);
					}
				}
				clearvisit();
			}
		}

		if (dqpii.empty())//���̻�������ѰԾ��ٸ� ���͵�����
			break;

		sort(dqpii.begin(), dqpii.end());//3. ���� ��, �� ���� ������ ���ĵ��� ����ȴ�.

		//���� dqpii�� ����ִ� ���� ���� �� ������ Ȯ���ϸ� ���� �ִܰ���ӵ� Ȯ���ϰ� �� �� �� ������ ���ĵǾ����� ���� ����Ǿ��ִ� ���� ������ ����ȴ�. ���� ��µǴ� �� ����.
		pii sacrifice = dqpii.front();
		int gor = sacrifice.ff; int goc = sacrifice.ss;
		field[gor][goc] = 9; field[sr][sc] = 0;
		sr = gor; sc = goc;
		second += minDist;
		eatkazu++;
		if (eatkazu == ssize) {
			eatkazu = 0;
			ssize++;
			//cout << ssize << " �� ������ ���׷��̵�!" << endl;
		}
		//cout << ssize << " : ������" << endl;
		clearvisit();
		/*pf();
		cout << endl;*/
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

/*
������ ��� Ǯ�̸� �߰��ߴµ�,
sort�Լ����� �����ϰ� ���Լ��� ���������ν� ���� ���� ���� Ǯ�̰� �־���.
https://yabmoons.tistory.com/160
�Ŀ� �ݵ�� �� ������ ������.
*/