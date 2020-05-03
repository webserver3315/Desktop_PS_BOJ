#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pll pair<long long, long long>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
using namespace std;

int a;
int b;
vector<pll> vct;

signed main() {

	cin >> a >> b;
	while (a != 0 || b != 0) {
		vct.push_back(mp(a, b));
		cin >> a >> b;
	}

	for (auto a : vct) {
		int f = a.ff;
		int s = a.ss;
		int cnt = 0;
		int carry = 0;
		while (f != 0 || s != 0) {
			int fff = f % 10; int sss = s % 10;
			f /= 10; s /= 10;
			if (fff + sss + carry >= 10) {
				cnt++;
				carry = 1;
			}
			else
				carry = 0;
		}
		cout << cnt << endl;
	}

	return 0;
}