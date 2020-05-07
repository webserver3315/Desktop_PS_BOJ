#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int t;
int n;
string a, b;
string bmin, bmax;

//string strplus(const string& a, const string& b) {
string strplus(string a, string b) {
	//reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
	string ans;
	if (a.length() < b.length()) {//a가 항상 b보다 같거나 길도록
		string tmp = a;
		a = b; b = tmp;
	}
	bool carry = false;
	int i;
	for (i = 0; i < b.length(); i++) {
		int val = 0;
		if (carry) val++;
		if (a[i] == '1') val++;
		if (b[i] == '1') val++;

		if (val == 3) {
			carry = true;
			ans.push_back('1');
		}
		else if (val == 2) {
			carry = true;
			ans.push_back('0');
		}
		else if (val == 1) {
			carry = false;
			ans.push_back('1');
		}
		else if (val == 0) {
			carry = false;
			ans.push_back('0');
		}
		else {
			cerr << "에러상황발생" << endl;
		}
	}
	//i--;
	for (; i < a.length(); i++) {
		int val = 0;
		if (carry) val++;
		if (a[i] == '1') val++;

		if (val == 2) {
			carry = true;
			ans.push_back('0');
		}
		else if (val == 1) {
			carry = false;
			ans.push_back('1');
		}
		else if (val == 0) {
			carry = false;
			ans.push_back('0');
		}
		else {
			cerr << "에러상황발생" << endl;
		}
	}
	if (carry) ans.push_back('1');

	return ans;
}

int strbinmult(string a, string b) {//자릿수는 같음이 보장된다.
	int hidden = 0;
	string buf;
	if (b[0] == '0') {
		for (int i = 0; i < b.length(); i++) buf.push_back('0');
	}
	else {
		buf = a;
	}

	for (int i = 1; i < a.length(); i++) {
		buf.pop_back(); hidden++;
		string aite;
		if (b[i] == '1') {
			for (int i = 0; i < b.length(); i++) aite.push_back('1');
			buf = strplus(buf, aite);
		}
	}
	int ret = buf.length() + hidden;
	for (int i = buf.length() - 1; i >= 0; i--) {
		if (buf[i] == '1') break;
		else ret--;
	}
	return ret;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		a.clear(); b.clear(); bmin.clear(); bmax.clear();
		cin >> n;
		cin >> b;
		reverse(b.begin(), b.end());
		for (char c : b) {
			a.push_back('1');
			if (c == '?') {
				bmax.push_back('1');
				bmin.push_back('0');
			}
			else {
				bmax.push_back(c);
				bmin.push_back(c);
			}
		}
		cout << "a: " << a << " b: " << b <<  " bmax : " << bmax << " bmin : " << bmin << endl;

		cout << strbinmult(a, bmax) << " " << strbinmult(a, bmin) << endl;
		}


	return 0;
}