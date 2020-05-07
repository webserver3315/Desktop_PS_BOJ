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
priority_queue<int, vector<int>, less<int>> leftpq;
priority_queue<int, vector<int>, greater<int>> rightpq;

void get_midval3(int n) {//좌측에 최대힙, 우측에 최소힙을 넣고 우측의 힙이 원소가 최소한 같거나 많도록 유지하자. 그러면 우측힙의 탑원소가 중앙값임이 보장되지않는가. 단, 우측힙과 좌측힙의 크기차이가 2 이상은 나면 안된다.ㄴ
	if (leftpq.size() == rightpq.size()) {
		if (!rightpq.empty() && n > rightpq.top()) {
			rightpq.push(n);
			leftpq.push(rightpq.top());
			rightpq.pop();
		}
		else{
			leftpq.push(n);
		}
		cout << leftpq.top() << endl;
	}
	else if (leftpq.size() > rightpq.size()) {
		leftpq.push(n);
		rightpq.push(leftpq.top());
		leftpq.pop();
		cout << leftpq.top() << endl;
	}
	else
		cout << "ERROR" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	/*double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();*/

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		get_midval3(tmp);
	}

	/*ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	cout << ctime_duration << " ms" << endl;*/
	return 0;
}