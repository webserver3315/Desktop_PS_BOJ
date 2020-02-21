/*
���� ��
*/

#include <iostream>
#include <queue>
#include <cmath>
#define endl '\n'
using namespace std;

int N;

bool IsPriorThan(int a, int b) {
	if (abs(a) > abs(b))
		return true;
	else if (abs(a) < abs(b))
		return false;
	else
		if (a > b)
			return false;
		else
			return true;
}/*sort�Լ��� �޸� �̷��� �����ϸ� �ȵǳ�����; �Լ������Ͱ� �ƴ϶� ������ struct ���ο� () �����ڿ����ε����� �ؾ��ҵ�
�׸��� �߰�������, sort�� ��� ������������ �ϱ� ���ؼ��� return a<b; �ϸ� �Ǵµ� priority queue������ return a>b; ���־�� �Կ� ����!
��, �켱���� ť������ ������ �켱�õǱ� ���ؼ��� �ش� ��쿡�� true�� ������Ѵ�*/

struct cmp {//�����ߴ�. ���� �ٸ��� ���� ū �� �켱, ���� ������ ������ ���� �� �켱���� �����ߴµ� �� �� ���� �� �켱�̾���.
	public:
		/*bool IsPriorThan(int a, int b) {
			if (abs(a) > abs(b))
				return true;
			else if (abs(a) < abs(b))
				return false;
			else
				if (a > b)
					return false;
				else
					return true;
		}*/
		bool operator() (const int& a, const int& b) {
			if (abs(a) > abs(b))
				return false;
			else if (abs(a) < abs(b))
				return true;
			else
				if (a < b)
					return false;
				else
					return true;
		}
};

struct mycmp2 {//�����ߴ�. ���� �ٸ��� ���� ū �� �켱, ���� ������ ������ ���� �� �켱���� �����ߴµ� �� �� ���� �� �켱�̾���.
	//public://�⺻�� public�̴�. ����ü��. class�� private�̰�.
	/*bool IsPriorThan(int a, int b) {
		if (abs(a) > abs(b))
			return true;
		else if (abs(a) < abs(b))
			return false;
		else
			if (a > b)
				return false;
			else
				return true;
	}*/
	bool operator() (const int& a, const int& b) {
		if (abs(a) > abs(b))
			return true;
		else if (abs(a) < abs(b))
			return false;
		else
			if (a <= b)//��ȣ �ٿ����Ҵ�. ��ȣ�� ������. ��ȣ�� �ٿ��߸� �Ѵ�.
				return false;
			else
				return true;
	}
};

struct cmp2 {
	bool operator()(const int& a, const int& b) {//priority_queue ��Ư�� �����ؾ��Ѵ�. true�� ��µǸ� ���ڸ�, false�� ��µǸ� ���ڸ� �켱���Ѵ�. �׷��ϱ� ������ ���Լ��� IsPriorThan���� ¥�� true false�� ���µ�, �켱����ť�� IsMinorThan ���� ����ؾ��Ѵ�.
		if (abs(a) == abs(b))//���񰪰����� ������ �켱�̴�. �׷��� priority_queue ���Լ� ��Ư�� �ݴ�� �����Ѵ�.
			return a > b;
		return abs(a) > abs(b);//�� �����ϴ� ������ true�϶���. ���ʿ��� swap�� ���� �ʱ� ���ؼ���, ������ �� false�� ��ȯ�ϵ��� �ؾ��ϹǷ� ��ȣ�� �ʿ����. ������ ��ȣ���̸� �������.
	}
};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int, vector<int>, mycmp2> pq;

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
		else {
			pq.push(tmp);
		}
	}

	return 0;
}