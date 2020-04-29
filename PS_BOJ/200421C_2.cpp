#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

int t;
int n;
int arr[(int)2e5 + 5];
bool nm;//negative mode

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		int maxval=INTMAX_MIN;
		int ans = 0;
		for (int i = 0; i < n-1; i++) {
			if (i == 6)
				//cout << "koko";
			if ((arr[i] ^ arr[i + 1]) >= 0) {//sign same
				if (maxval < arr[i]) {
					maxval = arr[i];
				}
			}
			else {
				if (maxval < arr[i]) {
					maxval = arr[i];
				}
				//cout << maxval << " 더하기" << endl;
				//cout << ans << "세이브" << endl;
				ans += maxval;
				maxval = arr[i + 1];
			}
		}
		if ((arr[n - 2] ^ arr[n - 1]) >= 0) {
			if (maxval < arr[n - 1]) {
				maxval = arr[n - 1];
			}
			/*cout << maxval << " 더하기" << endl;
			cout << ans << "세이브" << endl;*/
			ans += maxval;
		}
		else {
			/*cout << maxval << " 더하기" << endl;
			cout << ans << "세이브" << endl;*/
			ans += maxval;
		}

		cout <<"답: "<< ans << endl;
	}

	return 0;
}