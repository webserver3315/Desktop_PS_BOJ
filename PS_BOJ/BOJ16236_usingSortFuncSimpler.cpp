/*
아기상어

sort 및 비교함수를 이용하여 영리하게 푸는 법
*/

#include <iostream>
#include <deque>
#include <vector>
#include <utility>//pair때문
#include <algorithm>
#include <cstring>//memset 때문

#define endl '\n'
#define MAX 21
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b) //이거 A형에서 ㄱㄴ한가?
using namespace std;

struct shark {
	int r; int c;
	int size; int eatcnt;
	int time;
};

struct fish {
	int r; int c;
	int dist;
};

/*
비교순위:
※비교함수의 경우 동등을 두 차례의 비교함수 모두 false인 경우로 정의하기 때문에, equal의 경우 일단 false로 리턴해야만 오류가 발생하지 않는다!
※sort 에 들어가는 비교함수는 bool반환형으로 전자가 우선시되면 true, 동등하거나 후자가 우선시되면 false를 반환토록 설정하면 된다.
1. 거리가 가까우면 이유불문하고 우선시된다
2. 거리가 동일할 경우, r이 작을 경우 우선시된다
3. r이 동일할 경우, c가 작을 경우 우선시된다.
4. 거리와 r과 c가 모두 동일한 경우는 없음이 보장된다.
*/
bool fishCompare(fish a, fish b) {//우선적으로 먹을 고기가 front(인덱스0) 에 오도록 한다. 전자가 우선이면 true, 후자가 우선이면 false이다.
	if (a.dist <= b.dist) {
		if (a.dist == b.dist) {
			if (a.r <= b.r) {
				if (a.r == b.r) {
					if (a.c <= b.c) {
						if (a.c == b.c) {//완전히 equal이라면 false 때리는게 국룰이다. 아니면 에러뜬다.
							return false;
						}
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}

int N;
int field[MAX][MAX];
bool visit[MAX][MAX];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
shark S;
vector<fish> vctfish;

void BFS(int r, int c) {//r,c로부터 도보로 먹을 수 있는 가능한 한 모든 fish들을 vctfish에 넣는다. fish에는 필요한 최소걸음 수까지 멤버변수로 들어있다. 지나간 곳을 전부 visit처리하고 터질 때 memset하지는 않는다. 
	deque<pair<pair<int, int>, int>> dqppiii;
	dqppiii.push_back(mp(mp(r, c), 0));
	visit[r][c] = true;
	while (!dqppiii.empty()) {
		int rr = dqppiii.front().ff.ff; int cc = dqppiii.front().ff.ss;
		int dist = dqppiii.front().ss;
		dqppiii.pop_front();

		for (int i = 0; i < 4; i++) {
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (rrr < 0 || ccc < 0 || rrr >= N || ccc >= N || visit[rrr][ccc])//범위초과거나 visited면 거른다
				continue;
			if (field[rrr][ccc] == 0) {//가보지 않은 물이면
				visit[rrr][ccc] = true;
				dqppiii.push_back(mp(mp(rrr, ccc), dist + 1));
			}
			else if (field[rrr][ccc] < S.size) {//먹을 수 있는 고기면
				fish tmpfish;
				tmpfish.r = rrr; tmpfish.c = ccc;
				tmpfish.dist = dist + 1;

				vctfish.push_back(tmpfish);
				visit[rrr][ccc] = true;
				dqppiii.push_back(mp(mp(rrr, ccc), dist + 1));
			}
			else if (field[rrr][ccc] == S.size) {//지나갈 수만 있는 고기면
				visit[rrr][ccc] = true;
				dqppiii.push_back(mp(mp(rrr, ccc), dist + 1));
			}
		}
	}
}

void solution() {
	while (true) {
		vctfish.clear();
		memset(visit, false, sizeof(visit));
		BFS(S.r, S.c);
		if (vctfish.empty()) {
			cout << S.time << endl;
			break;
		}
		else {
			sort(vctfish.begin(), vctfish.end(), fishCompare);

			int fr = vctfish.front().r; int fc = vctfish.front().c;//foodr, foodc
			field[fr][fc] = 9;
			field[S.r][S.c] = 0;
			S.r = fr; S.c = fc;
			S.eatcnt++;
			S.time += vctfish.front().dist;
			if (S.eatcnt == S.size) {
				S.eatcnt = 0;
				S.size++;
			}
		}
	}
}

void input() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			if (field[r][c] == 9) {
				S.r = r; S.c = c;
				S.size = 2; S.eatcnt = 0;
				S.time = 0;
			}
		}
	}
}

void solve() {
	input();
	solution();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	solve();

	return 0;
}