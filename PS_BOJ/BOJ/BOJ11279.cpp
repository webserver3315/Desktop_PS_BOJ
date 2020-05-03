/*
�ִ� ��
*/

#include <iostream>
//#include <deque>
#include <queue>
#define endl '\n'
using namespace std;

/*
C������ �� �ڷᱸ���� ���� �����ߴٸ�,
C++������ ���� ����ü�� �켱����ť�� stl���� �����Ѵ�.
�켱���� ť�� ����.
*/

/*
stl�� priority queue�� queue ����� �ִ�.(�� ���� deque�� �ƴ϶� queue��; ���� �ε����� ���� �ȵǰ� clear�Լ� ���� �׷����ʰ���?
����; ������ insert, pop, top, empty, size ���̴�. �翬�Ѱǰ��ͱ������� ������ front, back�� ����.
front�� �ƴ϶� top�̶�� ���� �����Ҹ��ϴ�.
�׾� �� ���ʿ� �켱����ť�� �̸��� ť�̰� ���δ� ����Ʈ���̴ϱ�;

������ priority_queue<int, vector<int>, compare<int> > �� �Ѵ�.

���� ������� �ڷ���, ����ü, �񱳿������ε�
�ڷ����� ���״�� ����, �Ǽ�, Ŭ���� ���� �����ϰ�
����ü�� default ���� vector<�ڷ���> ���� �Ǿ��ִ�. ���� �������� �����Ѵ�
���Լ��� ���״�� �񱳿� ����� �Լ��� ���´�.
���Լ��� �⺻���� less�� ��Ʈ���� ���������̶�� ��, �� �ִ����̰�(���� �켱����ť���� �켱������ ���ٴ� ���� �켱�������� ũ�ٴ°� �ǹ��ϴ�) greater�� ���� ��Ʈ���� ���������̶�� ���̹Ƿ� �ּ����̴�.

���� ��� priority_queue<int, vector<int>, greater<int>> pq;
�̷��� �����ϸ� �Ϻ��ϴ�.
���� �ڷ����� pair��� �� �׷��� ù ���ں��� �˻������� �����ϸ� �� ��° ���ڸ� �˻��Ѵ�.
insert, pop�� �ҿ�Ǵ� �ð��� logN�̴�.
*/

int N;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, less<int>> pq;

	cin >> N;

	while (N--) {
		int tmp;
		cin >> tmp;
		if (tmp == 0)
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top() << endl;
				pq.pop();
			}
		else
			pq.push(tmp);

	}

	return 0;
}