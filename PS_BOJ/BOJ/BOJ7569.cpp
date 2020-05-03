/*
�丶��

�丶�䰡 ���ڻ��ڿ� �����Ǿ��ִ�.
������ �丶��� ������ ���� �丶���� ������ �޾� �Ͱ� �Ǹ�, ������ ���������¿� ���������̴�.
������ �Ϻ� ĭ���� �丶�䰡 ���� ���� ������, ���� �丶���� ���� ���� �丶���� ������ �־�����.
��� �丶�䰡 �ʹ� �ּҽð��� ���϶�.

ó�� ���� �丶��� 1, 0�� �������丶��, -1�� ��ĭ
>>2��° ���� �丶��� 2, 3��° ���� �丶��� 3 �̷� ������ ���� ����
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

struct position {
	int r;
	int c;
	int h;
};

int R, C, H;//��� 1���� ����, 100����
int dr[6] = { 0,0,-1,1,0,0 };
int dc[6] = { 0,0,0,0,-1,1 };
int dh[6] = { -1,1,0,0,0,0 };
int box[105][105][105];//r,c,h��
int cnt0;
int changed_cnt;
queue<position> quepos;
int sec;

void printbox() {
	for (int h = 1; h <= H; h++) {
		for (int c = 1; c <= C; c++) {
			for (int r = 1; r <= R; r++) {
				cout << box[r][c][h] << ' ';
			}
			cout << endl;
		}
		cout << endl;
	}
}

void BFS() {
	while (!quepos.empty()) {
		/*cout << sec++ << "��° ��" << endl;
		printbox();*/
		position now = quepos.front();
		quepos.pop();
		int rr = now.r; int cc = now.c; int hh = now.h; int zikan = box[rr][cc][hh];
		for (int i = 0; i < 6; i++) {//���� ��ġ�������������¿쿡 ���Ͽ�
			int rrr = rr + dr[i]; int ccc = cc + dc[i]; int hhh = hh + dh[i];
			if (rrr <= 0 || ccc <= 0 || hhh <= 0 || rrr > R || ccc > C || hhh > H)//�����ʰ���
				continue;
			if (box[rrr][ccc][hhh] == -1 || box[rrr][ccc][hhh] > 0)//�丶�䰡 ���ų� �̹� �;��� ���
				continue;
			box[rrr][ccc][hhh] = zikan + 1;
			changed_cnt++;
			quepos.push({ rrr,ccc,hhh });
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C >> H;
	for (int h = 1; h <= H; h++) {
		for (int c = 1; c <= C; c++) {
			for (int r = 1; r <= R; r++) {
				cin >> box[r][c][h];
				if (box[r][c][h] == 0)
					cnt0++;
				else if (box[r][c][h] == 1) {
					position tmp = { r,c,h };
					quepos.push(tmp);
				}
			}
		}
	}

	BFS();

	if (changed_cnt != cnt0) {//���� ���� �ʾ��� ���
		cout << -1 << endl;
		return 0;
	}

	int maxtime = 0;
	for (int h = 1; h <= H; h++) {
		for (int c = 1; c <= C; c++) {
			for (int r = 1; r <= R; r++) {
				if (maxtime < box[r][c][h])
					maxtime = box[r][c][h];
			}
		}
	}
	cout << maxtime - 1 << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}