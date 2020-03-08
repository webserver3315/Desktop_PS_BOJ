#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

int K, N;
int prime[100];
priority_queue<int> pq;//크기가 절대 N을 초과하지 않도록 유지해야함

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
			cout << num << "푸시" << endl;
			pq.push(num);
			num += num;
		}
		while (pq.top() > num) {
			int top = pq.top();
			cout << top << "팝" << endl;
			pq.pop();
			pq.push(num);
			cout << num << "푸시" << endl;
			num += num;
		}
	}

	cout << pq.top() << endl;

	return 0;
}