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

		int ans = 0;
		int maxval;
		bool isn;
		for(int i=0;i<n;i++){
			if (i == 0) {
				if (arr[i] > 0) isn = false; else isn = true;
				maxval = arr[i];
				continue;
			}
			if (arr[i - 1] * arr[i] < 0) {
				ans += maxval;
				maxval = arr[i];
			}
			else {
				if (maxval < arr[i])
					maxval = arr[i];
			}
		}
		ans += maxval;
		cout << ans << endl;
	}

	return 0;
}//¾¾¹ß ÀÌ°Ô ¹¹¶ó°í 37ºÐÀ» ²¿¶ó¹Ú¾Ò³Ä;