/*
�Ʊ���
*/

#include <iostream>
#include <cmath>
#define endl '\n'
#define MAX 21
using namespace std;


/*���� ������ ������ �� ���ٴ� ���� ��������.
DFS�� �� �̵��켱������ ��, ��, ��, �� ������ for���� �����ٸ�
�������ľ��ϰ� �ڿ��� ù��°�� �ɸ��� �Ŀ밡�� ����Ⱑ �ɸ��� �ʰڴ°�?

������, �� ������ "�ִܰŸ� �����" ��� ������ �켱�̴�.

field ����Ž���� ���� ��� �Ŀ밡�� ����⿡ ���� ��ü �ִܰŸ��� ���ϰ�
��ü �ִܰŸ��� depth limit�� �����Ͽ�, dfs�� �����ϴµ� ù������ �ɸ� ����⸦ ä���Ѵ�.
Ž���� ���� field�� ������ ũ���� visited �迭�� �ʿ��ϴ�. ���� ���� �� ���� ���곶��ϱ�.
*/

int N;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };
int field[MAX][MAX];
bool visit[MAX][MAX];
int osr, osc;//���� �������� �����ġ
int sr, sc;//�����ġ
int ssize = 2;//���ũ��
int eatkazu;//��������
int second;
bool hasEaten;//DFS�� ���������׸� ���ϰ� �������� �α׸� �����ϸ� �ȴ�.

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

void DFS(int maxlim, int depth) {
	
	if (depth == maxlim && hasEaten == false) {//IsComplete
		if (field[sr][sc] == 0 || ssize <= field[sr][sc]) {//������ ���� ���̰ų� ���Դ� ����
			//cout << sr << " " << sc << " �� ����������, ���̾��ų� ���ų� ū��������� �ɷ����ϴ�" << endl;
			/*pf();
			cout << endl;*/
			return;
		}
		cout << sr << " " << sc << " �� ����⸦ �Ծ���!" << endl;
		field[sr][sc] = 9;
		field[osr][osc] = 0;
		osr = sr; osc = sc;
		/*pf();
		cout << endl;*/
		second += maxlim;
		eatkazu++;
		if (eatkazu == ssize) {
			eatkazu = 0;
			ssize++;
			cout << ssize << " �� ������ ���׷��̵�!" << endl;
		}
		hasEaten = true;
		return;
	}


	int tmpr = sr; int tmpc = sc;
	for (int i = 0; i < 4; i++) {
		int rr = sr + dr[i]; int cc = sc + dc[i];
		if (rr >= N || cc >= N || rr < 0 || cc < 0 || field[rr][cc] > ssize || visit[rr][cc] == true) {//������ �� �ִ� ����: �������̸鼭 ũ�Ⱑ 0, �Ǵ� �ڽź��� �۰ų� ���ƾ��Ѵ�. �� �ڽź��� �۰ų� ���ƾ��Ѵ�. �׷��� �������̶�� �ڽź��� �ݵ�� �۾ƾ߸� �����ϴ�. �׷��� �װ� IsComplete������ ó������.
			//cout << rr << " " << cc << " �� �ɷ����ϴ�. �����ʰ��ų� ���� �� ���� ����Դϴ�." << endl;
			continue;
		}

		//field[sr][sc] = 0;//Ʈ��ŷ��
		sr = rr; sc = cc;
		//field[sr][sc] = 9;
		visit[sr][sc] = true;

		//cout << i << " ��� ����" << endl;
		DFS(maxlim, depth + 1);

		if (hasEaten) {
			//cout << tmpr << ' ' << tmpc << "�� field 0����!" << endl;
			return;
		}

		visit[sr][sc] = false;
		//field[sr][sc] = 0;
		sr = tmpr; sc = tmpc;
		//field[sr][sc] = 9;
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
�� ��ġ���� 0,4�� �Ծ���ϴµ� �� �˰����� 1,1�� �Դ´�.*/
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

	osr = sr; osc = sc;
	pf();
	hasEaten = true;
	while (hasEaten) {
		int minDist = MAX * 3;
		for (int r = 0; r < N; r++) {//minDist�� ã�� ����
			for (int c = 0; c < N; c++) {
				if (field[r][c] == 0 || ssize <= field[r][c])//�� �Ǵ� ���Դ°� �ɷ����Ѵ�
					continue;
				if (minDist > abs(sr - r) + abs(sc - c))
					minDist = abs(sr - r) + abs(sc - c);
			}
		}

		cout << "minDist�� " << minDist << endl;

		if (minDist == MAX * 3)//���̻�����Ծ��ٸ� ���͵�����
			break;

		hasEaten = false;
		visit[sr][sc] = true;
		DFS(minDist, 0);
		clearvisit();
		pf();
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