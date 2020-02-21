#include <iostream>
#include <string>
#define endl '\n'
#define int long long
using namespace std;

/**/


int n, k;
int a;
int aa;

bool IsBeautiful(string str) {
	for (int i = 0; i < str.length() - k; i++) {
		if (str[i] != str[i + k])
			return false;
	}
	return true;
}

signed main() {
	cin >> n >> k;
	cin >> a;
	aa = a;
	string tmpstr;
	while (1) {
		tmpstr = to_string(aa);
		if (IsBeautiful(tmpstr)) {
			cout << tmpstr.length() << endl;
			cout << aa << endl;
			return 0;
		}
		else {
			aa++;
		}
	}
	return 0;
}