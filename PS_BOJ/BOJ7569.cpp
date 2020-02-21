/*
토마토

토마토가 격자상자에 적층되어있다.
안익은 토마토는 인접한 익은 토마토의 영향을 받아 익게 되며, 인접은 상하전후좌우 여섯방향이다.
상자의 일부 칸에는 토마토가 없을 수도 있으며, 익은 토마토들과 익지 않은 토마토의 정보가 주어진다.
모든 토마토가 익는 최소시간을 구하라.

처음 익은 토마토는 1, 0은 안익은토마토, -1은 빈칸
>>2일째 익은 토마토는 2, 3일째 익은 토마토는 3 이런 식으로 유지 ㄱㄴ
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
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

struct position {
	int r;
	int c;
	int h;
};

int R, C, H;//모두 1부터 시작, 100이하
int dr[6] = { 0,0,-1,1,0,0 };
int dc[6] = { 0,0,0,0,-1,1 };
int dh[6] = { -1,1,0,0,0,0 };
int box[105][105][105];//r,c,h순
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
		/*cout << sec++ << "번째 팝" << endl;
		printbox();*/
		position now = quepos.front();
		quepos.pop();
		int rr = now.r; int cc = now.c; int hh = now.h; int zikan = box[rr][cc][hh];
		for (int i = 0; i < 6; i++) {//현재 위치에서상하전후좌우에 대하여
			int rrr = rr + dr[i]; int ccc = cc + dc[i]; int hhh = hh + dh[i];
			if (rrr <= 0 || ccc <= 0 || hhh <= 0 || rrr > R || ccc > C || hhh > H)//범위초과시
				continue;
			if (box[rrr][ccc][hhh] == -1 || box[rrr][ccc][hhh] > 0)//토마토가 없거나 이미 익었을 경우
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

	if (changed_cnt != cnt0) {//전부 익지 않았을 경우
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