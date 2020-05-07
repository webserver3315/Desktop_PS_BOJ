#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int t;
int n;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		int a = 2; int ans;
		while (1) {
			a <<= 1; a--;
			if (n % a == 0) {
				ans = n / a;
				break;
			}
			a++;
		}
		cout << ans << endl;
	}
	return 0;
}