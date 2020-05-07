/*
치즈
*/
#include <iostream>
#include <utility>
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
#define ff first
#define ss second
typedef std::pair <int, int> pii;
#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

int dr[4] = { -1,1,0,0 };
int dc[4] = { 0.0, -1,1 };
int R, C;
int cheese[105][105] = { 2, };


/*주의해야할 점은, 밀폐된 구멍엔 공기가 없다고 쳐야한다는 것이다.

지도 받고, 외부공기를 2로 FLOOD FILL 해서 초기화한다.
외부공기유입은 어떻게 구현할 것인가?

이 step을 초마다 반복하도록 하자

공기 flood fill
2와 인접한 치즈 전부 큐에 넣기
큐에 들어있는 치즈 전부 삭제
반복

*/

void OxygenFlood() {//이건 시간별이 아니라 즉시 이루어져야한다.
	queue<pii> closedoxygen;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (cheese[r][c] != 2)
				continue;
			for (int i = 0; i < 4; i++) {
				int rr = r + dr[i]; int cc = c + dc[i];
				if (rr >= R || cc >= C || rr < 0 || cc < 0 || cheese[rr][cc] != 0)
					continue;

				cheese[rr][cc] = 2;
				closedoxygen.push(mp(rr, cc));
				while (!closedoxygen.empty()) {
					int rrr = closedoxygen.front().first; int ccc = closedoxygen.front().second;
					closedoxygen.pop();
					for (int ii = 0; ii < 4; ii++) {
						int rrrr = rrr + dr[ii]; int cccc = ccc + dc[ii];
						if (rrrr >= R || cccc >= C || rrrr < 0 || cccc < 0 || cheese[rrrr][cccc] != 0)
							continue;
						cheese[rrrr][cccc] = 2;
						closedoxygen.push(mp(rrrr, cccc));
					}
				}

			}
		}
	}

}

void killAdj() {
	queue<pair<int,int>> killqueue;//ㅅㅂ 큐가 at 접근이 안된다는걸 처음알았다
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (cheese[r][c] != 1)
				continue;
			for (int i = 0; i < 4; i++) {
				int rr = r + dr[i]; int cc = c + dc[i];
				if (rr >= R || cc >= C || rr < 0 || cc < 0 || cheese[rr][cc] != 2)
					continue;
				killqueue.push({ r,c });
			}
		}
	}
	for (int idx = 0; idx < killqueue.size(); idx++) {
		pii soonkill = killqueue.at(idx);
		cheese[soonkill.ff][soonkill.ss] = 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; r++) {
			cin >> cheese[r][c];
		}
	}
	int sec = 0;


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}