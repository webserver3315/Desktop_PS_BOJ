#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int K, N;
int prime[100];
priority_queue<int> pq;//ũ�Ⱑ ���� N�� �ʰ����� �ʵ��� �����ؾ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		cin >> prime[i];
	}

	for (int i = 0; i < K; i++) {
		int num = prime[i];
		while (pq.size() < N) {
			cout << num << "Ǫ��" << endl;
			pq.push(num);
			num += num;
		}
		while (pq.top() > num) {
			int top = pq.top();
			cout << top << "��" << endl;
			pq.pop();
			pq.push(num);
			cout << num << "Ǫ��" << endl;
			num += num;
		}
	}

	cout << pq.top() << endl;

	return 0;
}