/*
2020.03.08 ����

��ü ����ü�� ���� < �����ڸ� �����ε��ؼ� PRIORITY�� DIY �Ǻ��������� ������ ��.
�̻��ϰ� PAIR�� ����, �����ε��� �⺻������ �ڲ� ������ �������� �߻��ؼ�
�ƿ� ����PAIR�� stc ����ü�� �������.
*/
#include <iostream>
#include <queue>
#include <utility>
#define endl '\n'
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;

struct stc {
	int key;
	int val;
};

bool operator<(stc a, stc b) {
	if (a.key > b.key)
		return true;
	else if (a.key == b.key)
		if (a.val > b.val)
			return true;
	return false;
}

int myabs(int n) {
	return n > 0 ? n : -n;
}

int N;
priority_queue<stc> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	while (N--) {
		cin >> tmp;
		if (tmp) {
			int abstmp = myabs(tmp);
			stc stctmp = { abstmp,tmp };
			pq.push(stctmp);
		}
		else {
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top().val << endl;
				pq.pop();
			}
		}
	}
	return 0;
}