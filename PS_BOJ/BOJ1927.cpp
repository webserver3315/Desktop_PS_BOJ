/*
최소 힙
*/

#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

/*
C에서는 힙 자료구조를 직접 구현했다면,
C++에서는 힙의 구현체인 우선순위큐를 stl에서 지원한다.
우선순위 큐를 쓰자.
*/

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;
	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
			pq.push(tmp);
	}

	return 0;
}