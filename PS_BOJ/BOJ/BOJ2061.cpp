#include <iostream>
#define MAX (int)1e6+1
using namespace std;

bool IsComposite[MAX] = { true, true, };
string k;
int l;

void makeEratos() {
	for (int i = 2; i < MAX; i++) {
		if (IsComposite[i] == false) {
			int tmp = i;
			while (tmp + i < MAX) {
				tmp += i;
				IsComposite[tmp] = true;
			}
		}
	}
	return;
}

int StringMod(string a, int b) {
	int tmp = 0;
	int idx;
	for (idx = 0; idx < a.length();) {//이 for문에서 i++을 박으면 안된다!
		while (idx < a.length() && tmp < b) {
			int tmptmp = a[idx++] - '0';
			tmp = tmp * 10 + tmptmp;
		}
		tmp %= b;
	}
	return tmp;
}

int IsGood(string a, int b) {
	int ans;
	int i;
	for (i = 2; i < l; i++) {
		ans = StringMod(a, i);
		if (ans == 0) {//작은 키값이면 나쁜 수
			return i;
		}
	}
	return 0;//0이면 좋은 수
}

void solve() {
	makeEratos();
	int ans = IsGood(k, l);
	if (ans == 0) {
		cout << "GOOD" << endl; 
	}
	else {
		cout << "BAD " << ans << endl;
	}
	return;
}

int main() {//이거 C로 어떻게 k 받음? //이거 char[102] 로 받은 뒤, strlen 함수를 구현해서 len을 직접 구한 뒤 쓰면 된다.
	cin >> k >> l;
	solve();
	return 0;
}