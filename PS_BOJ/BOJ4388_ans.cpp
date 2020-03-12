#include <iostream>
#include <algorithm> // min
#include <functional>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <sstream>
#include <queue>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false); cin.tie(0);

	while (true) {
		int n, k; cin >> n >> k;

		// 종료 조건
		if (n == 0 && k == 0) {
			break;
		}
		int sol = 0;
		while (n && k) {
			int carry = 0;
			int cand = (n % 10 + k % 10) / 10;
			if (cand) {
				carry = cand;
			}
			n = n / 10;
			k = k / 10;

			if (n > k) {
				k += carry;
			}
			else {
				n += carry;
			}

			if (carry) {
				sol++;
			}
		}
		cout << sol << endl;
	}
	return 0;
}
