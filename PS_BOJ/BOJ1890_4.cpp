/*
DFS, BFS ���� �ʰ����. DFS�� �ð��ʰ�, BFS�� �޸��ʰ���.
�׷��ٰ� visited �ڱ⿣ �ָ��ߴ�. �󿡼�, �¿��� �����ϴ� �� 2���� visited ������ �����ϱ� �����̴�.
������ visited, ������ visited �� ���� �θ� �Ǳ�� �ϳ�,
https://kswims.tistory.com/140

�� ��α׸� ���� ������ ���� �ִٴ� ���� ������.
r,c���� r+jump,c ���̿� �ִ� ��� ĭ�� �� ���� ���ٴ� ���̴�.
����, �׳� ���߹ݺ����� ���� �������� Ǯ� ��������.
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