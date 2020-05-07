#include <iostream>
#include <string>
#include <vector>
#define endl '\n'
#define int long long
using namespace std;

/*20000 자리까지 가능하다. 즉 무조건 스트링으로만 다뤄야한다.*/
int n, k;
string str_a;
vector<char> reversevct;

void printvector() {
	for (char tmp : reversevct)
		cout << tmp;
	cout << endl;
}

void VectorPlus() {
	//printvector();
	int idx = 0;
	while (idx < reversevct.size()) {
		reversevct[idx]++;
		if (reversevct[idx] > '9') {
			reversevct[idx] = '0';
			idx++;
			continue;
		}
		break;
	}
	if (idx == reversevct.size()) {
		reversevct.push_back('1');
	}
	return;
}

bool IsBeautiful(vector<char> vct) {
	for (int i = 0; i < vct.size() - k; i++) {
		if (vct[i] != vct[i + k])
			return false;
	}
	return true;
}

signed main() {
	cin >> n >> k;
	cin >> str_a;
	for (int i = str_a.length() - 1; i >= 0; i--) {
		reversevct.push_back(str_a[i]);
	}

	while (1) {
		if (IsBeautiful(reversevct)) {
			cout << reversevct.size() << endl;
			for (int idx = reversevct.size() - 1; idx >= 0;idx--) {
				cout << reversevct[idx];
			}
			cout << endl;
			return 0;
		}
		else {
			VectorPlus();
		}
	}
	return 0;
}