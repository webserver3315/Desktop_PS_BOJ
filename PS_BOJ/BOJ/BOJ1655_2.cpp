/*
����� ���ؿ�

���� ���� �߰�/���������� �������µ� ������ �����ؾ� �ϹǷ� ���̴�.

�ð��ʰ�;;
�ϴ� ���� ũ��� 10���ε�
*/

#include <iostream>
#include <queue>
#include <ctime>
#define endl '\n'
using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> pq;
vector<int> mybuffer;

/*ó���� for(int i=0;i<pq.size()/2;i++) �ߴµ�, pq.size���� for�� ���ο��� pop�Կ� ���� �������� ����Ǵ� �Ǽ��� ��������.
�׸���, �ð��ʰ����. �Ƹ� priority_queue�� ���� �Ź� ȣ���ϰ� �Ǵµ�, �� �κп��� �ð��ʰ��� ���°ǰ� �ʹ�.
�׷��ٸ�, vector�� �����ؼ� �������� �ӽù��۷� �ؼ� ��� �ٽ� �ҷ����� ������ ����.*/
int get_midval(priority_queue<int, vector<int>, less<int>> pqpq) {//&���� �������� Call by Value��. �� ���� �����ص� �ȴ�.
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