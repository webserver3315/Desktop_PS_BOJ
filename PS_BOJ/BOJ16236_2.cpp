/*
아기상어
*/

#include <iostream>
#include <cmath>
#define endl '\n'
#define MAX 21
using namespace std;


/*갇힌 물고기는 접근할 수 없다는 것을 유의하자.
DFS할 때 이동우선순위를 상, 좌, 하, 우 순으로 for문을 돌린다면
벡터정렬안하고도 자연히 첫번째로 걸리는 식용가능 물고기가 걸리지 않겠는가?

하지만, 그 이전에 "최단거리 물고기" 라는 조건이 우선이다.

field 전수탐색을 통해 모든 식용가능 물고기에 대해 전체 최단거리를 구하고
전체 최단거리를 depth limit로 설정하여, dfs를 수행하는데 첫빠따로 걸린 물고기를 채택한다.
탐색을 위해 field와 동일한 크기의 visited 배열이 필요하다. 갔던 곳을 또 가면 연산낭비니까.
*/

int N;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,-1,0,1 };
int field[MAX][MAX];
bool visit[MAX][MAX];
int osr, osc;//ㄹㅇ 오리지날 상어위치
int sr, sc;//상어위치
int ssize = 2;//상어크기
int eatkazu;//먹은갯수
int second;
bool hasEaten;//DFS시 최초포착항만 겟하고 나머지는 싸그리 무시하면 된다.

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

void DFS(int maxlim, int depth) {
	
	if (depth == maxlim && hasEaten == false) {//IsComplete
		if (field[sr][sc] == 0 || ssize <= field[sr][sc]) {//도달한 곳이 물이거나 못먹는 고기면
			//cout << sr << " " << sc << " 에 도달했지만, 물이었거나 같거나 큰고기인지라 걸렀습니다" << endl;
			/*pf();
			cout << endl;*/
			return;
		}
		cout << sr << " " << sc << " 의 물고기를 먹었다!" << endl;
		field[sr][sc] = 9;
		field[osr][osc] = 0;
		osr = sr; osc = sc;
		/*pf();
		cout << endl;*/
		second += maxlim;
		eatkazu++;
		if (eatkazu == ssize) {
			eatkazu = 0;
			ssize++;
			cout << ssize << " 로 사이즈 업그레이드!" << endl;
		}
		hasEaten = true;
		return;
	}


	int tmpr = sr; int tmpc = sc;
	for (int i = 0; i < 4; i++) {
		int rr = sr + dr[i]; int cc = sc + dc[i];
		if (rr >= N || cc >= N || rr < 0 || cc < 0 || field[rr][cc] > ssize || visit[rr][cc] == true) {//지나갈 수 있는 조건: 범위내이면서 크기가 0, 또는 자신보다 작거나 같아야한다. 즉 자신보다 작거나 같아야한다. 그러나 마지막이라면 자신보다 반드시 작아야만 가능하다. 그러나 그건 IsComplete문에서 처리하자.
			//cout << rr << " " << cc << " 는 걸렀습니다. 범위초과거나 지날 수 없는 고기입니다." << endl;
			continue;
		}

		//field[sr][sc] = 0;//트래킹용
		sr = rr; sc = cc;
		//field[sr][sc] = 9;
		visit[sr][sc] = true;

		//cout << i << " 대로 가자" << endl;
		DFS(maxlim, depth + 1);

		if (hasEaten) {
			//cout << tmpr << ' ' << tmpc << "의 field 0으로!" << endl;
			return;
		}

		visit[sr][sc] = false;
		//field[sr][sc] = 0;
		sr = tmpr; sc = tmpc;
		//field[sr][sc] = 9;
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
의 위치에서 0,4를 먹어야하는데 본 알고리즘은 1,1을 먹는다.*/
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

	osr = sr; osc = sc;
	pf();
	hasEaten = true;
	while (hasEaten) {
		int minDist = MAX * 3;
		for (int r = 0; r < N; r++) {//minDist를 찾기 위함
			for (int c = 0; c < N; c++) {
				if (field[r][c] == 0 || ssize <= field[r][c])//물 또는 못먹는건 걸러야한다
					continue;
				if (minDist > abs(sr - r) + abs(sc - c))
					minDist = abs(sr - r) + abs(sc - c);
			}
		}

		cout << "minDist는 " << minDist << endl;

		if (minDist == MAX * 3)//더이상먹을게없다면 볼것도없다
			break;

		hasEaten = false;
		visit[sr][sc] = true;
		DFS(minDist, 0);
		clearvisit();
		pf();
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