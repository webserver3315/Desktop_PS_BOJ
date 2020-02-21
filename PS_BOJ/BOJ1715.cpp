/*
카드 정렬하기
*/

#include <iostream>
#include <queue>
using namespace std;


int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
	}
	int sum = 0;
	while (pq.size() > 1) {
		int popped1 = pq.top();
		pq.pop();
		int popped2 = pq.top();
		pq.pop();
		//cout << "sum=sum+popped : "
		sum += popped1 + popped2;
		pq.push(popped1 + popped2);
	}
	cout << sum << endl;

	return 0;
}