/*
�ּ� ��
*/

#include <iostream>
#include <queue>
#define endl '\n'
using namespace std;

/*
C������ �� �ڷᱸ���� ���� �����ߴٸ�,
C++������ ���� ����ü�� �켱����ť�� stl���� �����Ѵ�.
�켱���� ť�� ����.
*/

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;
	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
			pq.push(tmp);
	}

	return 0;
}