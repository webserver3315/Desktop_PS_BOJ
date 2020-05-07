#include <iostream>
#define MAX ((int)1e6)+1
using namespace std;

/*
������ ������� �Ⱥ����� ���� �ô�.
����� ���������� �ƴ϶�, ������ �������µ�
���� ������ ����, 1e100 �� �Ѱ��ε� int�� �޾Ҵٴ� ���̴�.
100���̸�, ��� long long���ε� Ŀ�� �ȵǰ� string���� �޾ƾ� �ϴ� �����̴�.
*/

bool isNotPrime[MAX] = { true,true, };
int t;

void MakeEratos() {
	for (int i = 2; i < MAX; i++) {
		if (isNotPrime[i] == false) {
			int tmp = i;
			while (tmp + i < MAX) {
				tmp += i;
				isNotPrime[tmp] = true;
			}
		}
	}
	return;
}

int StrDivInt(string a, int b) {//string a�� b�� ������ int�� ���
	int tmp = 0;
	int idx = 0;
	while (idx < a.length()) {
		while (tmp < b && idx < a.length()) {
			tmp = tmp * 10 + a[idx++] - '0';
		}
		tmp %= b;
	}
	return tmp;
}

int IsGood(string p, int k) {//���� �Ҽ��̸� 0 ����. ���� �Ҽ��̸� ������ �����Ҽ� ����
	for (int i = 2; i < k; i++) {
		if (isNotPrime[i] == true)
			continue;
		else {
			if (StrDivInt(p, i) == 0) {//i�� p�� ���� Ű�Ҽ��̸鼭 k ���� ������
				return i;
			}
			else
				continue;
		}
	}
	return 0;
}

void solve(string p, int k) {
	MakeEratos();
	int ans = IsGood(p, k);
	//cout << "ans = " << ans << endl;
	if (ans == 0) {
		cout << "GOOD" << endl;
	}
	else {
		cout << "BAD " << ans << endl;
	}
}

int main() {
	//cin >> t;
	t = 1;
	string p;
	int k;
	while (t--) {
		cin >> p >> k;
		solve(p, k);
	}

	return 0;
}