#include <iostream>
#include <string>
using namespace std;

int t;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> str;
		int maxlenL = 0;
		bool beforeIsL = false;
		int cnt = 0;
		for (int i = 0; i < str.length(); i++) {
			if (beforeIsL) {
				if (str[i] == 'L') {
					cnt++;
				}
				else {
					if (maxlenL < cnt)
						maxlenL = cnt;
					cnt = 0;
					beforeIsL = false;
				}
			}
			else {
				if (str[i] == 'L') {
					beforeIsL = true;
					cnt = 1;
				}
				else {
					beforeIsL = false;
					continue;
				}
			}
		}
		if (maxlenL < cnt)
			maxlenL = cnt;
		cout << maxlenL + 1 << endl;
	}
	return 0;
}