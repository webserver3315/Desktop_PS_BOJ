/*
벽부수고 이동하기

이번에는 최적해를 구하기 위해 완전탐색을 해야만 한다는 단점을 감수하고서라도, 벽을 부수는 기회의 사용여부유지의 용이성을 취하기 위해 DFS 를 이용하기로 한다
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

/*이 풀이의 경우, 소규모가 아니라 대규모 필드에서 공백이 많으면 질러가야되는것도 뱅뱅 돌아서 모든 경로의 수를 계산하느라 굉장히 많은 비용을 소모한다.
결국 시간초과띄운다. 또는 콜스택 오버플로우를 일으킬 것이다.

*/

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
vector<int> ways;
//int memo[1005][1005];//안부수고 각 칸마다 최소비용


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
		//cout << cnt << " 정답으로써 푸시" << endl;
		ways.push_back(cnt);
		return cnt;
	}
	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i]; int cc = c + dc[i];
		if (rr > R || cc > C || rr <= 0 || cc <= 0) {//경계초과면 거른다
			continue;
		}
		else if (!used && field[rr][cc] == -1) {//벽부술 수 있고 벽이라면 부순다
			//cout << "벽을 부쉈습니다 " << rr << " " << cc << "바사삭" << endl;
			field[rr][cc] = cnt + 1;
			DFS(rr, cc, cnt + 1, true);
			field[rr][cc] = -1;
			//cout << "벽을 고쳤습니다 " << rr << " " << cc << "뚝딱" << endl;
			continue;
		}
		else if (used && field[rr][cc] == -1) {//전방에 벽인데 벽을 부술 수 없다면
			continue;
		}
		else if (field[rr][cc] == 0) {//공간이라면 전진한다
			field[rr][cc] = cnt + 1;
			DFS(rr, cc, cnt + 1, used);
			field[rr][cc] = 0;
			continue;
		}
		else {//나머지는 되돌아감을 뜻하는 것이므로 거른다.
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