#include <iostream>
#define MAX ((int)1e6)+1
using namespace std;

/*
���� �ô�.
���� ������ ����, 1e100 �� �Ѱ��ε� int�� �޾Ҵٴ� ���̴�.
100���̸�, ��� long long���ε� Ŀ�� �ȵǰ� string���� �޾ƾ� �ϴ� �����̴�.
*/

bool isNotPrime[MAX] = { true,true, };
int t;

void MakeEratos() {
	for (int i = 2; i < MAX; i++) {
		if (isNotPrime[i] == false){
			int tmp = i;
			while (tmp + i < MAX) {
				tmp += i;
				isNotPrime[tmp] = true;
			}
		}
	}
	return;
}

int IsGood(int p, int k) {//���� �Ҽ��̸� 0 ����. ���� �Ҽ��̸� ������ �����Ҽ� ����
	for (int i = 2; i < k; i++) {
		if (isNotPrime[i] == true)
			continue;
		else {
			if (p % i == 0) {//i�� p�� ���� Ű�Ҽ��̸鼭 k ���� ������
				return i;
			}
			else
				continue;
		}
	}
	return 0;
}

void solve(int p, int k) {
	MakeEratos();
	int ans = IsGood(p, k);
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
	int p, k;
	while (t--) {
		cin >> p >> k;
		solve(p, k);
	}

	return 0;
}