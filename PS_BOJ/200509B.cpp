#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

/*
¦���� ¦���� ���ҷ� ��Ÿ������ ���� ¦�� �Ǵ� Ȧ������ ��
Ȧ���� ���ҷ� ��Ÿ������ ���� ¦������ ��. �� ���� 2�ڰ� �������� ¦���ϱ� �׷��� ���. �����߸� �Ұ�.
Ȧ���� ¦���� ���ҷ� ��Ÿ���°� �Ұ���
Ȧ���� Ȧ���� ���ҷ� ��Ÿ������ ���� Ȧ������ ��
*/

int t;
int n, k;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n >> k;
		if (n & 1) {
			if (!(k & 1) || n - k + 1 <= 0) {
				cout << "NO" << endl;
				continue;
			}
			else {
				cout << "YES" << endl;
				for (int i = 0; i < k - 1; i++) cout << 1 << " ";
				cout << n - k + 1 << endl;
			}
		}
		else {
			if (k & 1) {
				if ((n - 2 * (k - 1) <= 0 || (n - 2 * (k - 1) & 1))) {
					cout << "NO" << endl;
					continue;
				}
				else {
					cout << "YES" << endl;
					for (int i = 0; i < k - 1; i++) cout << 2 << " ";
					cout << n - 2 * (k - 1) << endl;
				}
			}
			else {
				if (n - k + 1 <= 0) {
					cout << "NO" << endl;
					continue;
				}
				else {
					cout << "YES" << endl;
					for (int i = 0; i < k - 1; i++) cout << 1 << " ";
					cout << n - k + 1 << endl;
				}
			}
		}
	}

	return 0;
}