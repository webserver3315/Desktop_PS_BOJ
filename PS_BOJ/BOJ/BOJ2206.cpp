/*
벽 부수고 이동하기
2초

가로세로 1000 이하의 맵이 주어진다.
R,C는 1,1부터 시작이다
0은 공간, 1은 벽이다
1,1부터 R,C까지 이동한다. 두 칸은 항상 공백임이 보장된다.
이동하는 도중 벽을 부수는게 더 빠르다면, 1번까지 부수는 것을 허용한다
맵이 주어졌을 때 최단경로비용을 구해내라
절대 불가능하면 -1을 출력하라
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

struct Position {
	int r;
	int c;
	int cnt;//시작칸과 끝칸도 cnt에 포함
	bool breaked = false;//기본값 이렇게 설정하는거 맞나?
};
queue<Position> pque;
int R, C;
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int field[1005][1005];//-1은 벽, 0은 공간, 1은 횟수
int memo[1005][1005];//각 칸마다 최소비용
bool visit[1005][1005];//bfs의 경우 팝한뒤에 체크가 아니라 푸시한 직후 체크를 한다

/*벽을 부순 전적이 있는지의 여부 및 현재위치 및 유지중인 비용을 QUEUE로 유지하면서 BFS할 시 원큐에 최적해를 항상 보장할 수 있다.

*/

void printmemo() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cout << memo[r][c] << ' ';
		}
		cout << endl;
	}
}

void BFS() {
	Position hatsu = { 1,1,1,false };
	memo[1][1] = 1;
	pque.push(hatsu);

	while (!pque.empty()) {
		printmemo();
		cout << endl;
		Position nowpos = pque.front();
		pque.pop();
		int rr = nowpos.r; int cc = nowpos.c;
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr > R || ccc > C || rrr <= 0 || ccc <= 0) {//경계초과면
				continue;
			}
			if (field[rrr][ccc] != -1) {//벽 아니면
				if (memo[rrr][ccc] != 0 && memo[rrr][ccc] < nowpos.cnt + 1)//갈 가치가 있으면 진출하고 없으면 패스한다
					continue;
				pque.push({ rrr,ccc,nowpos.cnt + 1,nowpos.breaked });
				memo[rrr][ccc] = nowpos.cnt + 1;
			}
			else {//벽이면
				if (nowpos.breaked) {//저번에 부쉈으면 노답
					continue;
				}
				else {//아직 안부쉈으면 부술 수 있음
					if (memo[rrr][ccc] != 0 && memo[rrr][ccc] < nowpos.cnt + 1)//갈 가치가 있으면 진출하고 없으면 패스한다
						continue;
					pque.push({ rrr,ccc,nowpos.cnt + 1,true });
					memo[rrr][ccc] = nowpos.cnt + 1;
					continue;
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
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				field[r][c] = -1;
		}
	}

	BFS();

	if (memo[R][C])
		cout << memo[R][C] << endl;
	else
		cout << -1 << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}