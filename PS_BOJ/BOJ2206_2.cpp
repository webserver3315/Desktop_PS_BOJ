/*
�� �μ��� �̵��ϱ�
2��

���μ��� 1000 ������ ���� �־�����.
R,C�� 1,1���� �����̴�
0�� ����, 1�� ���̴�
1,1���� R,C���� �̵��Ѵ�. �� ĭ�� �׻� �������� ����ȴ�.
�̵��ϴ� ���� ���� �μ��°� �� �����ٸ�, 1������ �μ��� ���� ����Ѵ�
���� �־����� �� �ִܰ�κ���� ���س���
���� �Ұ����ϸ� -1�� ����϶�
*/
#include <iostream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//�������
//pair<int, int> mypair = make_pair(1, 2);//C++11 �������� �̷���
//P mypair = { 1,2 };//C++11 ���ĺ��͸� ����
//P mypair(1, 2);//�������̿�

struct Position {
	int r;
	int c;
	int cnt;//����ĭ�� ��ĭ�� cnt�� ����
	bool breaked = false;//�⺻�� �̷��� �����ϴ°� �³�?
};
queue<Position> pque;
int R, C;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int field[1005][1005];//-1�� ��, 0�� ����, 1�� Ƚ��
int nonbk_memo[1005][1005];//�Ⱥμ��� �� ĭ���� �ּҺ��
int bk_memo[1005][1005];//�μ� �� �� ĭ���� �ּҺ��
bool visit[1005][1005];//bfs�� ��� ���ѵڿ� üũ�� �ƴ϶� Ǫ���� ���� üũ�� �Ѵ�

/*���� �μ� ������ �ִ����� ���� �� ������ġ �� �������� ����� QUEUE�� �����ϸ鼭 BFS�� �� ��ť�� �����ظ� �׻� ������ �� �ִ�.

*/

void printmemo() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cout << nonbk_memo[r][c] << ' ';
		}
		cout << endl;
	}
}

void BFS() {
	Position hatsu = { 1,1,1,false };
	nonbk_memo[1][1] = 1;
	pque.push(hatsu);

	while (!pque.empty()) {
		printmemo();
		cout << endl;
		Position nowpos = pque.front();
		pque.pop();
		int rr = nowpos.r; int cc = nowpos.c;
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr > R || ccc > C || rrr <= 0 || ccc <= 0) {//����ʰ���
				continue;
			}
			if (rrr == R && ccc == C) {
				bk_memo[R][C] = nowpos.cnt + 1;
				return;
			}

			if (nowpos.breaked) {//�μ� ���� ���� ���
				if (field[rrr][ccc] == -1)//���̸� ���
					continue;
				if (bk_memo[rrr][ccc] != 0 && bk_memo[rrr][ccc] < nowpos.cnt + 1)//�� ��ġ�� ������
					continue;
				pque.push({ rrr,ccc,nowpos.cnt + 1,nowpos.breaked });
				bk_memo[rrr][ccc] = nowpos.cnt + 1;
			}

			else {//�Ⱥν��� ���
				if (field[rrr][ccc] != -1) {//�� �ƴϸ�
					if (nonbk_memo[rrr][ccc] != 0 && nonbk_memo[rrr][ccc] < nowpos.cnt + 1)//�� ��ġ�� ������ �����ϰ� ������ �н��Ѵ�
						continue;
					pque.push({ rrr,ccc,nowpos.cnt + 1,nowpos.breaked });
					nonbk_memo[rrr][ccc] = nowpos.cnt + 1;
					bk_memo[rrr][ccc] = nonbk_memo[rrr][ccc];
				}
				else {//�μ� �� ����
					if (bk_memo[rrr][ccc] != 0 && nonbk_memo[rrr][ccc] < nowpos.cnt + 1)//�� ��ġ�� ������ �����ϰ� ������ �н��Ѵ�
						continue;
					pque.push({ rrr,ccc,nowpos.cnt + 1,true });
					nonbk_memo[rrr][ccc] = nowpos.cnt + 1;
					continue;
					}
				}

			}
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C;
	for (int r = 1; r <= R; r++) {//��������־����°� ������
		for (int c = 1; c <= C; c++) {
			int tmp;
			scanf("%1d", &tmp);
			if (tmp == 1)
				field[r][c] = -1;
		}
	}

	BFS();

	if (nonbk_memo[R][C] || bk_memo[R][C])
		cout << bk_memo[R][C] << endl;
	else
		cout << -1 << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}