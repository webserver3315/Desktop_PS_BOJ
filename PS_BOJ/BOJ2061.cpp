#include <iostream>
#define MAX (int)1e6+1
using namespace std;

bool IsComposite[MAX] = { true, true, };
string k;
int l;

void makeEratos() {
	for (int i = 2; i < MAX; i++) {
		if (IsComposite[i] == false) {
			int tmp = i;
			while (tmp + i < MAX) {
				tmp += i;
				IsComposite[tmp] = true;
			}
		}
	}
	return;
}

int StringMod(string a, int b) {
	int tmp = 0;
	int idx;
	for (idx = 0; idx < a.length();) {//�� for������ i++�� ������ �ȵȴ�!
		while (idx < a.length() && tmp < b) {
			int tmptmp = a[idx++] - '0';
			tmp = tmp * 10 + tmptmp;
		}
		tmp %= b;
	}
	return tmp;
}

int IsGood(string a, int b) {
	int ans;
	int i;
	for (i = 2; i < l; i++) {
		ans = StringMod(a, i);
		if (ans == 0) {//���� Ű���̸� ���� ��
			return i;
		}
	}
	return 0;//0�̸� ���� ��
}

void solve() {
	makeEratos();
	int ans = IsGood(k, l);
	if (ans == 0) {
		cout << "GOOD" << endl; 
	}
	else {
		cout << "BAD " << ans << endl;
	}
	return;
}

int main() {//�̰� C�� ��� k ����? //�̰� char[102] �� ���� ��, strlen �Լ��� �����ؼ� len�� ���� ���� �� ���� �ȴ�.
	cin >> k >> l;
	solve();
	return 0;
}