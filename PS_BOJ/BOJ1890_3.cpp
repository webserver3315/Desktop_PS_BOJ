#include <iostream>
#include <deque>
#define endl '\n'
#define MAX 101
#define pii pair<int,int>
#define ff first
#define ss second
using namespace std;

/*
2020.02.06(��) ��Ʋ���� �絵���Ѵ�. ���͵� �ƴ� �����ε� ���� ���� �߸�������.
*/

int N;
int field[MAX][MAX];
int memo[MAX][MAX];
deque<pii> buffer;
/*
DP�� Ǯ �� �ֳ�? �κй����κ��� ���������� ����ǳ�?
ť�� �̿��� BFS�� DP�� �ƴ϶� �ܼ��޸� ����̸� �� �� ���� �ѵ�
*/

void BFS() {
	memo[0][0] = 1;
	pii tmp = make_pair(0, 0);
	buffer.push_back(tmp);
	while (!buffer.empty()) {
		pii now = buffer.front();
		buffer.pop_front();
		int r = now.ff; int c = now.ss;
		if (r == N - 1 && c == N - 1)
			continue;
		int jump = field[r][c];
		int rr = r + jump; int cc = c + jump;
		if (rr < N) {
			pii reload = make_pair(rr, c);
			buffer.push_back(reload);
			memo[rr][c] += memo[r][c];//�� ��ġ�� �ִ°� �³�?
		}
		if (cc < N) {
			pii reload = make_pair(r, cc);
			buffer.push_back(reload);
			memo[r][cc] += memo[r][c];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
		}
	}

	BFS();
	cout << memo[N - 1][N - 1] << endl;

	return 0;
}