/*
���Ҿ����� Ǯ���
*/

#include <iostream>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
#define MAX (int)1e4+1
#define INF 987654321
using namespace std;

int N, K;
vector<int> coin;
deque<int> buffer;
int memo[MAX];

/*
������ ������������ a1������ an���������� �ִٰ� �ϸ�,
an���� ǥ���� �� �ִ� �ּҰ������� �����ϸ� �ȴ�.
an �ʰ���, an���� ���� ���� ���ϰ�.

�� �ƴ϶�,
�׳� ť�� ����ְ� ���� �� 1�� ������.
���ϴ� �� ���� ������.
BFS�� ������ �ظ� �����ϴ�.
*/

int bfs(int n) {
	int cnt = 1;
	for (int co : coin) {
		buffer.push_back(co);
		memo[co] = cnt;
	}
	
	while (!buffer.empty()) {
		cnt++;
		int size = buffer.size();
		while (size--) {
			int frt = buffer.front();
			buffer.pop_front();
			for (int co : coin) {
				int tmp = frt + co;
				if (tmp > K)
					continue;
				if (memo[tmp] == -1) {
					memo[tmp] = cnt;
					buffer.push_back(tmp);
				}
				if (tmp == n)
					return memo[tmp];
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(memo, -1, sizeof(memo));

	cin >> N >> K;
	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp < MAX) {
			coin.push_back(tmp);
		}
	}

	sort(coin.begin(), coin.end());
	int smallest = coin.front();
	int largest = coin.back();
	for (int co : coin) {
		memo[co] = 1;
	}

	int ans = bfs(K);

	cout << ans << endl;

	return 0;
}