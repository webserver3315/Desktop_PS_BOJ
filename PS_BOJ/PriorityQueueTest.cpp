/*
�ּ� ��

�� ������ top, pop ������ �Ǵ°�? �����°�?
������. ��, top�̶� pop�� �� ������ empty ������ üũ������Ѵ�.
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