/*
최소 힙

빈 힙에서 top, pop 연산이 되는가? 터지는가?
터진다. 즉, top이랑 pop은 쓸 때마다 empty 유무를 체크해줘야한다.
*/

#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(2);

	cout << pq.top() << endl;
	pq.pop();
	pq.pop();

	return 0;
}