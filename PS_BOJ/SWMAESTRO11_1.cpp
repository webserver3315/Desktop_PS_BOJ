#include <bits/stdc++.h>
using namespace std;

int N;
string ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	if (N % 2) {//È¦¼ö¸é
		ans.append("7");
		N -= 3;
	}
	else {
		ans.append("1");
		N -= 2;
	}
	for (; N > 0; N -= 2) {
		ans.append("1");
	}
	cout << ans << endl;

	return 0;
}