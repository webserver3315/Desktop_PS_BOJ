/*
가운데를 말해요

역시 잦은 추가/삭제연산이 벌어지는데 정렬을 유지해야 하므로 힙이다.

시간초과;;
일단 수의 크기는 10만인데
*/

#include <iostream>
#include <queue>
#include <ctime>
#define endl '\n'
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> pq;
vector<int> mybuffer;

/*처음엔 for(int i=0;i<pq.size()/2;i++) 했는데, pq.size값이 for문 내부에서 pop함에 따라 동적으로 변경되는 실수를 저질렀다.
그리고, 시간초과뜬다. 아마 priority_queue를 새로 매번 호출하게 되는데, 그 부분에서 시간초과가 나는건가 싶다.
그렇다면, vector를 선언해서 그쪽으로 임시버퍼로 해서 담고 다시 불러오는 식으로 하자.*/
int get_midval(priority_queue<int, vector<int>, less<int>> pqpq) {//&선언 안했으니 Call by Value다. 즉 맘껏 수정해도 된다.
	int willpop = pqpq.size() / 2;
	while (willpop--) 
		pqpq.pop();
	return pqpq.top();
}

void get_midval2() {
	int willpop = pq.size() / 2;
	while (willpop--) {
		mybuffer.push_back(pq.top());
		pq.pop();
	}
	cout << pq.top() << endl;
	while (!mybuffer.empty()) {
		pq.push(mybuffer.back());
		mybuffer.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;	
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		pq.push(tmp);
		//get_midval2();

		int willpop = pq.size() / 2;
		while (willpop--) {
			mybuffer.push_back(pq.top());
			pq.pop();
		}
		//cout << pq.top() << endl;
		while (!mybuffer.empty()) {
			pq.push(mybuffer.back());
			mybuffer.pop_back();
		}
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	cout << ctime_duration << " ms" << endl;
	return 0;
}