#include <iostream>
#include <queue>
#define MAX 1501
using namespace std;
//��������?
int N;
//priority_queue<int,vector<int>,less<int>> pq;//�ִ���
priority_queue<int> pq;//�ִ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	for (int i = 0; i < N * N; i++) {
		cin >> tmp;
		pq.push(tmp);
	}

	for (int i = 0; i < N - 1; i++) {
		pq.pop();
	}

	cout << pq.top() << endl;

	return 0;
}