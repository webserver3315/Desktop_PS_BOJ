/*
2000*2000�� int�� ��� 4�ް�����Ʈ�ۿ� �ȵǴµ�, �� 10�ް� ���ѿ� �ɸ����� ����������;
�ϴ� �װ� �����̶�� �� N ������ �ذ��ؾ���
*/

#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	for (int i = 0; i < N * N; i++) {
		cin >> tmp;
		if (pq.size() >= N) {
			if (pq.top() < tmp) {
				pq.pop();
				pq.push(tmp);
			}
		}
		else
			pq.push(tmp);
		
	}
	cout << pq.top() << endl;

	return 0;
}