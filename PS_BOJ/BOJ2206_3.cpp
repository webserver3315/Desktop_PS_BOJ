/*
���μ��� �̵��ϱ�

�̹����� �����ظ� ���ϱ� ���� ����Ž���� �ؾ߸� �Ѵٴ� ������ �����ϰ���, ���� �μ��� ��ȸ�� ��뿩�������� ���̼��� ���ϱ� ���� DFS �� �̿��ϱ�� �Ѵ�
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

/*�� Ǯ���� ���, �ұԸ� �ƴ϶� ��Ը� �ʵ忡�� ������ ������ �������ߵǴ°͵� ��� ���Ƽ� ��� ����� ���� ����ϴ��� ������ ���� ����� �Ҹ��Ѵ�.
�ᱹ �ð��ʰ�����. �Ǵ� �ݽ��� �����÷ο츦 ����ų ���̴�.

*/

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
vector<int> ways;
//int memo[1005][1005];//�Ⱥμ��� �� ĭ���� �ּҺ��


void printfield() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
}

int DFS(int r, int c, int cnt, bool used) {
	/*printfield();
	cout << endl;*/
	if (r == R && c == C) {
		//cout << cnt << " �������ν� Ǫ��" << endl;
		ways.push_back(cnt);
		return cnt;
	}
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i]; int cc = c + dc[i];
		if (rr > R || cc > C || rr <= 0 || cc <= 0) {//����ʰ��� �Ÿ���
			continue;
		}
		else if (!used && field[rr][cc] == -1) {//���μ� �� �ְ� ���̶�� �μ���
			//cout << "���� �ν����ϴ� " << rr << " " << cc << "�ٻ��" << endl;
			field[rr][cc] = cnt + 1;
			DFS(rr, cc, cnt + 1, true);
			field[rr][cc] = -1;
			//cout << "���� ���ƽ��ϴ� " << rr << " " << cc << "�ҵ�" << endl;
			continue;
		}
		else if (used && field[rr][cc] == -1) {//���濡 ���ε� ���� �μ� �� ���ٸ�
			continue;
		}
		else if (field[rr][cc] == 0) {//�����̶�� �����Ѵ�
			field[rr][cc] = cnt + 1;
			DFS(rr, cc, cnt + 1, used);
			field[rr][cc] = 0;
			continue;
		}
		else {//�������� �ǵ��ư��� ���ϴ� ���̹Ƿ� �Ÿ���.
			continue;
		}
	}
}

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);*/
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C;
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			int tmp;
			scanf("%1d", &tmp);
			if (tmp == 1)
				field[r][c] = -1;
		}
	}

	field[1][1] = 1;
	DFS(1, 1, 1, false);

	
	if (ways.empty())
		cout << -1 << endl;
	else {
		sort(ways.begin(), ways.end());
		cout << ways.front() << endl;
	}
	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}