#include <iostream>
#define endl '\n'
using namespace std;

//��� ¦���̰ų� ��� Ȧ���ų�

int t;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	/*cin >> t;
	int tmp;
	while (t--) {
		if (t == 0)
			cout << "koko";
		cin >> n;
		n--;
		cin >> tmp;
		int ki = tmp % 2;
		bool NO = false;
		while (n--) {
			cin >> tmp;
			if (tmp % 2 != ki) {
				NO = true;
				break;
			}
		}
		if (!NO)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}*/

	cin >> t;
	int tmp;
	while(t--) {
		cin >> n;
		cin >> tmp;
		int ki = tmp % 2;
		bool no = false;
		for (int i = 1; i < n; i++) {
			cin >> tmp;
			if (tmp % 2 != ki) {
				no = true;
			}
		}
		if (!no)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
/*
���Ű��� �߰��� break�ɾ ���� ���� ���� �ع��ȴ�
*/