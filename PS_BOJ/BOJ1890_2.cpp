#include <iostream>
#define MAX 101
#define int long long//2e63-1 미만이므로 일단 longlong으로 바꿈
using namespace std;

int N;
int field[MAX][MAX];
int memo[MAX][MAX];
int cnt;

/*
일반적인 백트래킹만 쓰면 TE뜬다.
답은 DP다.
어떻게 적용할까.

대문제는 소문제로부터 도출가능하기에, DP의 필요조건은 만족한다.
MEMO칸을 만들어서 따로 각 칸마다 필요한 최소비용을 메모하면서 가도록 하자.
*/

//int dpDFS(int r, int c, int depth) {
//	int jump = field[r][c];
//	int rr = r + jump;
//	int cc = c + jump;
//	if (rr < N) {
//		memo[rr][c]++;
//
//	}
//	if (cc < N) {
//
//	}
//}
//
//int DP(int r, int c, int depth) {
//	if (memo[r][c])
//		return memo[r][c];
//	else {
//		int bigger = memo[r][c] < depth ? depth : memo[r][c];
//		memo[r][c] = bigger;
//		int jump = field[r][c];
//		if (r + jump < N)
//			memo[r + jump][c] += DP(r + jump, c, depth + 1);
//		if (c + jump < N)
//			memo[r + jump][c] += DP(r, c + jump, depth + 1);
//		return memo[r][c];
//	}
//}

/*
r,c로 가는데 필요한 경로의 수를 반환하는 함수를 만드는건 쉽지 않다. 역함수가 존재하지 않기 때문이다.
애초에 모든 칸을 가는데 필요한 경로의 수를 전부 계산한 후 결과만 뽑는 것이 차라리 빠르다.

*/

int DFS(int r, int c) {
	if (r == N - 1 || c == N - 1)//이ㅓㄱㄴ가?
		return 0;
	int jump = field[r][c];
	int rr = r + jump;
	int cc = c + jump;
	if (rr < N) {
		memo[rr][c] += memo[r][c];
		if (r != N - 1)
			DFS(rr, c);
	}
	if (cc < N) {
		memo[r][cc] += memo[r][c];
		if (c != N - 1)
			DFS(r, cc);
	}
	return 0;
}


signed main() {
	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
		}
	}
	memo[0][0] = 1;
	DFS(0, 0);
	cout << memo[N - 1][N - 1] << endl;
	return 0;
}