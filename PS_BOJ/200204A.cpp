#include <iostream>
#include <vector>
using namespace std;

/*
Ȧ�� ������ ������ ���.
¦�� �����鼭 Ȧ�� ������ ¦���� ���.
Ȧ��, ¦�� ���� 1�� �̻��� �ִٸ� ������ ����
*/

int t;
int n;
vector<int> buf;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int even = 0;
		int odd = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (tmp % 2 == 0)
				even++;
			else
				odd++;
		}
		if (odd == 0) {
			cout << "NO" << endl;
		}
		else if (even == 0) {
			if ((even + odd) % 2 == 0) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
		else {
			cout << "YES" << endl;
		}
	}

	return 0;
}