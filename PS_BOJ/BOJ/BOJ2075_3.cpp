/*
2000*2000의 int의 경우 4메가바이트밖에 안되는데, 왜 10메가 제한에 걸리는지 노이해지만;
일단 그게 원인이라니 뭐 N 내에서 해결해야지
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	for (int i = 0; i < N * N; i++) {
		cin >> tmp;
		if (pq.size() >= N) {
			if (pq.top() < tmp) {
				pq.pop();
				pq.push(tmp);
			}
		}
		else
			pq.push(tmp);
		
	}
	cout << pq.top() << endl;

	return 0;
}