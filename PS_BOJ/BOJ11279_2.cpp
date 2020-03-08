/*
2020.03.08 ¿Á≈¡
*/
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
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