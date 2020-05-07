/*
미로 탐색
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
#define endl '\n'
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)
typedef std::pair<int, int> P;//error C2143: 구문 오류 : ';'이(가) '<' 앞에 없습니다.가 발생하므로 std:: 을 붙여서 충돌을 없애주었다.
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용


using namespace std;

/*미로가 주어진다. 길은 1, 벽은 0이다.
0열 0행은 없다. 1부터 시작이다.
1,1부터 출발하여 n,m까지 도달하기 위해 지나야 하는 최소의 칸 수를 구하라.

최소의 칸 수이므로 bfs가 가장 적절하다.
만일 DFS를 했다가 루프가 있는 미로를 입력받는다면 빠져나올 수 없을지도 모른다.
혹여나 빠져나온다고 해도 DFS로 최적해를 찾기 위해서는 모든 경우를 뒤져봐야만 할 것이다.
따라서 BFS다.

미로 가로세로는 각각 100 이하다.
*/

int Map[102][102];
bool visit[102][102];
typedef pair< pair <int, int>, int > PointArrivalTime;//좌표 r, c, 걸리는 최소시간
queue<PointArrivalTime> Queue;
int R, C;
int dr[4] = { 1,-1,0,0 }; int dc[4] = { 0,0,-1,1 };

void PrintMap() {
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			cout << Map[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void BFS() {
	visit[1][1] = true;
	Queue.push({ {1,1},1 });//걸린시간이 아니라 지나간 칸의 수이므로, 처음부터 ss 인자는 1로 찍어야 한다.
	while (!Queue.empty()) {
		/*PrintMap();
		cout << endl;*/
		PointArrivalTime nowStruct = Queue.front();
		Queue.pop();
		P Point = nowStruct.ff;
		int rr = Point.ff; int cc = Point.ss;
		if (rr == R && cc == C) {//도달하면
			cout << nowStruct.ss << endl;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr > R || ccc > C || rrr <= 0 || ccc <= 0 || visit[rrr][ccc]) {
				continue;
			}
			Map[rrr][ccc] = -1;
			Queue.push({ { rrr,ccc }, nowStruct.ss + 1 });
			visit[rrr][ccc] = true;
		}
	}

	return;
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
			scanf("%1d", &Map[r][c]);
			if (Map[r][c] == 0) {
				visit[r][c] = true;
			}
		}
	}

	BFS();

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}