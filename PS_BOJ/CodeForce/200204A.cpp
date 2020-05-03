#include <iostream>
#include <vector>
using namespace std;

/*
홀수 없으면 무조건 노답.
짝수 없으면서 홀수 갯수가 짝수면 노답.
홀수, 짝수 각각 1개 이상은 있다면 무조건 ㄱㄴ
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