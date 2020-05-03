/*
아기상어

갇힌 물고기는 접근할 수 없다는 것을 유의하자.
DFS할 때 이동우선순위를 상, 좌, 하, 우 순으로 for문을 돌린다면
벡터정렬안하고도 자연히 첫번째로 걸리는 식용가능 물고기가 걸리지 않겠는가?

하지만, 그 이전에 "최단거리 물고기" 라는 조건이 우선이다.

field 전수탐색을 통해 모든 식용가능 물고기에 대해 전체 최단거리를 구하고
전체 최단거리를 depth limit로 설정하여, dfs를 수행하는데 첫빠따로 걸린 물고기를 채택한다.
탐색을 위해 field와 동일한 크기의 visited 배열이 필요하다. 갔던 곳을 또 가면 연산낭비니까.

minDist 찾고
한 번 더 선형완탐으로 minDist이면서 크기 작은 고기들을 pair queue에 집어넣는다.
각각의 pairqueue front 고기들에 대해 minDist 내의 depthlim으로 접근가능한지 여부를 조사
만약 접근불가시 그냥 pop. 접근가능시 그곳으로 이동
*/

/*
이대로 제출 시 일단 모든 테스트케이스에서는 정답을 출력함이 보장된다.
그러나, 오답이라고 나온다.
따라서 5번 파일을 만든 뒤, 최대한 리팩토링을 해본다.
*/

#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#include <climits>//INT_MAX는 gcc 에서는 cmath에 없고 climits에서 존재한다
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
int sr, sc;//상어위치
int ssize = 2;//상어크기
int eatkazu;//먹은갯수
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
어제 첫 간과) 크기가 크거나 같은 물고기는 지나갈 수 없다.

또 간과한 조건이 있다.
크기가 같은 물고기는 먹을 수는 없지만, 지나갈 수는 있다니 이게 무슨 말장난인가..

추가) 또 잘못 이해한 부분이 있다.
상어를 기준으로 가장 위, 가장 좌측 물고기가 아니라
절대적 위치를 기준으로 가장 위, 가장 좌측 물고기다...
아니아니 이거 상관없잖나?

아니다. 크기가 4일 때
5 4 9 0 3 4
4 3 0 3 4 5
3 2 0 5 6 6
2 0 0 3 4 5
3 2 0 6 5 4
6 6 6 6 6 6
의 위치에서 0,4를 먹어야하는데 본 알고리즘은 1,1을 먹는다.

4차 간과)
현재 소스의 반례는 이것이다
6
1 1 1 1 1 1
2 2 6 2 2 3
2 2 5 2 2 3
2 2 2 4 6 3
0 0 0 0 0 6
0 0 0 0 0 9
minDist는 수직상승하여 5인데, 실제로 5의 비용으로 1은 어디로도 갈 수 없다.
이론적 최소비용과 제약을 반영한 실질적 최소비용은 다를 수 있다.
*/

int HowManyStepsNeededBFS(int r, int c, int ir, int ic) {//r,s = 목적지, ir, is = 지금위치, 리턴값: 걸음 수(만약 불가능하면 0 출력). 참고로 r,c 위치의 물고기는 도달하기만 하면 먹을 수 있음이 보장된 고기이다.
	typedef pair<int, pii> pipii;
	deque<pipii> dqpipii;
	pii startpos = { ir,ic };
	pipii start = { 0,startpos };
	dqpipii.push_back(start);
	while (!dqpipii.empty()) {
		pipii nowpos = dqpipii.front();
		dqpipii.pop_front();
		int nowstep = nowpos.ff; int rr = nowpos.ss.ff; int cc = nowpos.ss.ss;
		if (rr == r && cc == c)//장애물 에도는 것을 감안하더라도 BFS라 첫빠따가 가능한 한 최적해임이 보장된다.
			return nowstep;
		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr >= N || ccc >= N || rrr < 0 || ccc < 0 || field[rrr][ccc] > ssize || visit[rrr][ccc] == true) {//범위초과거나 큰고기거나 방문했던경우 지나갈 수 없다
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
		int minDist = INT_MAX;//6번째 삽질 : 설마했는데 MAX*2로 해서 에러떴다.
		visit[sr][sc] = true;

		deque<pii> dqpii;
		for (int r = 0; r < N; r++) {//1. minDist를 찾는다.
			for (int c = 0; c < N; c++) {
				if (field[r][c] == 0 || ssize <= field[r][c])//물 또는 못먹는건 걸러야한다
					continue;
				int dist = HowManyStepsNeededBFS(r, c, sr, sc);
				if (dist != 0 && minDist > dist)//5번째 삽질: 0 아니어야한다는걸 간과했다;
					minDist = dist;
				clearvisit();
			}
		}
		//cout << "minDist는 " << minDist << endl;
		if (minDist == INT_MAX)
			break;
		for (int r = 0; r < N; r++) {//2. 먹을 수 있으면서 minDist와 같은 거리에 있는 고기를 전부 큐에 넣는다
			for (int c = 0; c < N; c++) {
				if (field[r][c] != 0 && ssize > field[r][c]) {//물 아니고 사이즈 반드시 작으면서
					int dist = HowManyStepsNeededBFS(r, c, sr, sc);
					if (dist == minDist) {//실제거리가 최단거리와 동일한 고기는 식용후보이다.
						pii tmppii = { r,c };
						dqpii.push_back(tmppii);
					}
				}
				clearvisit();
			}
		}

		if (dqpii.empty())//더이상먹을만한게없다면 볼것도없다
			break;

		sort(dqpii.begin(), dqpii.end());//3. 높은 순, 또 좌측 순으로 정렬됨이 보장된다.

		//이제 dqpii에 들어있는 수는 먹을 수 있음이 확실하며 실제 최단경로임도 확실하고 상 및 좌 순으로 정렬되어있음 또한 보장되어있는 고기들 뿐임이 보장된다. 먼저 출력되는 놈 ㅈㅈ.
		pii sacrifice = dqpii.front();
		int gor = sacrifice.ff; int goc = sacrifice.ss;
		field[gor][goc] = 9; field[sr][sc] = 0;
		sr = gor; sc = goc;
		second += minDist;
		eatkazu++;
		if (eatkazu == ssize) {
			eatkazu = 0;
			ssize++;
			//cout << ssize << " 로 사이즈 업그레이드!" << endl;
		}
		//cout << ssize << " : 사이즈" << endl;
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
마음에 드는 풀이를 발견했는데,
sort함수에서 교묘하게 비교함수를 설계함으로써 거의 날로 먹은 풀이가 있었다.
https://yabmoons.tistory.com/160
후에 반드시 내 것으로 만들자.
*/