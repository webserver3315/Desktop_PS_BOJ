#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int t;
int n;
int arr[(int)2e5 + 5];
bool isNegativeMode;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		int ans = 0;
		int maxval = INTMAX_MIN;
		cin >> arr[0];
		arr[0] > 0 ? isNegativeMode = false : isNegativeMode = true;
		for (int i = 1; i < n; i++) {
			cin >> arr[i];
			if (isNegativeMode) {
				if (arr[i] < 0 || i==n-1) {
					if (arr[i] > maxval)
						maxval = arr[i];
				}
				else {
					ans += maxval;
					cout << maxval << " 더했다 " << endl;
					maxval = arr[i];
					isNegativeMode = !isNegativeMode;
				}
			}
			else {
				if (arr[i] > 0 || i == n - 1) {
					if (arr[i] > maxval)
						maxval = arr[i];
				}
				else {
					ans += maxval;
					cout << maxval << " 더했다 " << endl;
					maxval = arr[i];
					isNegativeMode = !isNegativeMode;
				}
			}
		}
		cout << ans << endl;
	}

	return 0;
}