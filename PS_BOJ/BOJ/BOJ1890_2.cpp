#include <iostream>
#define MAX 101
#define int long long//2e63-1 �̸��̹Ƿ� �ϴ� longlong���� �ٲ�
using namespace std;

int N;
int field[MAX][MAX];
int memo[MAX][MAX];
int cnt;

/*
�Ϲ����� ��Ʈ��ŷ�� ���� TE���.
���� DP��.
��� �����ұ�.

�빮���� �ҹ����κ��� ���Ⱑ���ϱ⿡, DP�� �ʿ������� �����Ѵ�.
MEMOĭ�� ���� ���� �� ĭ���� �ʿ��� �ּҺ���� �޸��ϸ鼭 ������ ����.
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
r,c�� ���µ� �ʿ��� ����� ���� ��ȯ�ϴ� �Լ��� ����°� ���� �ʴ�. ���Լ��� �������� �ʱ� �����̴�.
���ʿ� ��� ĭ�� ���µ� �ʿ��� ����� ���� ���� ����� �� ����� �̴� ���� ���� ������.

*/

int DFS(int r, int c) {
	if (r == N - 1 || c == N - 1)//�̤ä�����?
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