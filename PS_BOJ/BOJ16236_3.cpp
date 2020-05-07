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

#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
#define endl '\n'
#define MAX 21
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
bool hasEaten;//DFS시 최초포착항만 겟하고 나머지는 싸그리 무시하면 된다.

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

bool tadoritsuita = false;
bool CanItGoDFS(int r, int c, int ir, int ic, int depthlimit, int depth) {//r,s = 목적지, ir, is = 지금위치
	if (depthlimit == depth) {
		if (r != ir || c != ic) {
			return false;
		}
		tadoritsuita = true;
		return true;
	}
	for (int i = 0; i < 4; i++) {
		int rr = ir + dr[i]; int cc = ic + dc[i];
		if (rr >= N || cc >= N || rr < 0 || cc < 0 || field[rr][cc] > ssize || visit[rr][cc] == true) {//범위초과거나 큰고기거나 방문했던경우 지나갈 수 없다
			continue;
		}
		visit[rr][cc] = true;
		CanItGoDFS(r, c, rr, cc, depthlimit, depth + 1);

		if (tadoritsuita)
			return true;

		visit[rr][cc] = false;
	}
	return false;
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

	pf();
	hasEaten = true;
	while (hasEaten) {
		int minDist = MAX * 3;
		hasEaten = false;
		visit[sr][sc] = true;

		deque<pii> dqpii;
		for (int r = 0; r < N; r++) {//minDist를 찾기 위함
			for (int c = 0; c < N; c++) {
				if (field[r][c] == 0 || ssize <= field[r][c])//물 또는 못먹는건 걸러야한다
					continue;
				if (minDist > abs(sr - r) + abs(sc - c))
					minDist = abs(sr - r) + abs(sc - c);
			}
		}
		cout << "minDist는 " << minDist << endl;
		for (int r = 0; r < N; r++) {//minDist인 식용가능고기 전부 pii큐에 처넣는다
			for (int c = 0; c < N; c++) {
				if (minDist == abs(sr - r) + abs(sc - c) && field[r][c] != 0 && ssize > field[r][c]) {
					pii tmppii = { r,c };
					dqpii.push_back(tmppii);
				}
			}
		}

		if (dqpii.empty())//더이상먹을만한게없다면 볼것도없다
			break;

		while (!dqpii.empty()) {
			pii tmppii = dqpii.front();
			dqpii.pop_front();
			int rr = tmppii.first; int cc = tmppii.second;
			/*DFS는 찾자말자 터트리기 부적합하다. BFS쓰자.*/
			if (CanItGoDFS(rr, cc, sr, sc, minDist, 0)) {//도달가능하면, 즉 먹을 수 있다면
				field[rr][cc] = 9; field[sr][sc] = 0; sr = rr; sc = cc;
				hasEaten = true;
				second += minDist;
				eatkazu++;
				if (eatkazu == ssize) {
					eatkazu = 0;
					ssize++;
					cout << ssize << " 로 사이즈 업그레이드!" << endl;
				}
				break;//더 이상 큐를 볼 필요없다
			}
			clearvisit();
		}
		tadoritsuita = false;
		clearvisit();
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