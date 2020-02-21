/*
가운데를 말해요

역시 잦은 추가/삭제연산이 벌어지는데 정렬을 유지해야 하므로 힙이다.
*/

#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N;

int get_midval(priority_queue<int,vector<int>, less<int>> pqpq) {//&선언 안했으니 Call by Value다. 즉 맘껏 수정해도 된다.
	//int poppedkaisu = 0;
	int willpop = pqpq.size() / 2;
	while (willpop--) {//처음엔 for(int i=0;i<pq.size()/2;i++) 했는데, pq.size값이 for문 내부에서 pop함에 따라 동적으로 변경되는 실수를 저질렀다.
		//int soonpop = pqpq.top();
		//cout << "popped : " << soonpop << ' ';
		pqpq.pop();
		//poppedkaisu++;
	}
	//cout << "poppedkaisu: " << poppedkaisu << endl;
	//int top = pqpq.top();
	return pqpq.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	priority_queue<int, vector<int>, less<int>> pq;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
		cout << get_midval(pq) << endl;
	}

	return 0;
}