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
priority_queue<int, vector<int>, less<int>> leftpq;
priority_queue<int, vector<int>, greater<int>> rightpq;

void get_midval3(int n) {//������ �ִ���, ������ �ּ����� �ְ� ������ ���� ���Ұ� �ּ��� ���ų� ������ ��������. �׷��� �������� ž���Ұ� �߾Ӱ����� ��������ʴ°�. ��, �������� �������� ũ�����̰� 2 �̻��� ���� �ȵȴ�.��
	if (leftpq.size() == rightpq.size()) {
		if (!rightpq.empty() && n > rightpq.top()) {
			rightpq.push(n);
			leftpq.push(rightpq.top());
			rightpq.pop();
		}
		else{
			leftpq.push(n);
		}
		cout << leftpq.top() << endl;
	}
	else if (leftpq.size() > rightpq.size()) {
		leftpq.push(n);
		rightpq.push(leftpq.top());
		leftpq.pop();
		cout << leftpq.top() << endl;
	}
	else
		cout << "ERROR" << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	/*double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();*/

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int tmp;
		cin >> tmp;
		get_midval3(tmp);
	}

	/*ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	cout << ctime_duration << " ms" << endl;*/
	return 0;
}