/*
2020.03.08 ¿Á≈¡
*/
#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	while (N--) {
		cin >> tmp;
		if (tmp) {
			pq.push(tmp);
		}
		else {
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
	}

	return 0;
}