/*
바텀업으로 풀어보자
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
동전이 오름차순으로 a1원부터 an원종류까지 있다고 하면,
an까지 표현할 수 있는 최소가짓수를 유지하면 된다.
an 초과시, an으로 나눈 몫을 더하고.

가 아니라,
그냥 큐에 집어넣고 동전 수 1씩 더하자.
원하는 수 나올 때까지.
BFS는 최적의 해를 보장하니.
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