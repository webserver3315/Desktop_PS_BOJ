/*
����� ���ؿ�

���� ���� �߰�/���������� �������µ� ������ �����ؾ� �ϹǷ� ���̴�.
*/

#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int N;

int get_midval(priority_queue<int,vector<int>, less<int>> pqpq) {//&���� �������� Call by Value��. �� ���� �����ص� �ȴ�.
	//int poppedkaisu = 0;
	int willpop = pqpq.size() / 2;
	while (willpop--) {//ó���� for(int i=0;i<pq.size()/2;i++) �ߴµ�, pq.size���� for�� ���ο��� pop�Կ� ���� �������� ����Ǵ� �Ǽ��� ��������.
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