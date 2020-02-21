/*
DFS, BFS 전부 초과뜬다. DFS는 시간초과, BFS는 메모리초과다.
그렇다고 visited 박기엔 애매했다. 상에서, 좌에서 접근하는 총 2가지 visited 허용수가 존재하기 때문이다.
상접근 visited, 좌접근 visited 를 따로 두면 되기는 하나,
https://kswims.tistory.com/140

이 블로그를 보고 간과한 것이 있다는 것을 느꼈다.
r,c에서 r+jump,c 사이에 있는 모든 칸은 갈 일이 없다는 것이다.
따라서, 그냥 이중반복문을 통해 선형으로 풀어도 문제없다.
*/

#include <iostream>
#define endl '\n'
#define MAX 101
using namespace std;

int N;
int field[MAX][MAX];
int memo[MAX][MAX];

int main() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
		}
	}
	memo[0][0] = 1;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (r == N - 1 && c == N - 1) {
				continue;
			}
			int rr = r + field[r][c]; int cc = c + field[r][c];
			if (rr < N) {
				memo[rr][c] += memo[r][c];
			}
			if (cc < N) {
				memo[r][cc] += memo[r][c];
			}
		}
	}
	cout << memo[N - 1][N - 1] << endl;
	return 0;
}