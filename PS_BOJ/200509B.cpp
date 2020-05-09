#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

/*
짝수를 짝수개 원소로 나타내려면 전부 짝수 또는 홀수여야 함
홀수개 원소로 나타내려면 전부 짝수여야 함. 걍 전부 2박고도 나머지가 짝수니까 그렇게 출력. 음수뜨면 불가.
홀수를 짝수개 원소로 나타내는건 불가능
홀수를 홀수개 원소로 나타내려면 전부 홀수여야 함
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