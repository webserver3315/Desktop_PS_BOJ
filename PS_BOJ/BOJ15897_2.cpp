#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int t;
int N;
vector<int> divs;

//int getNum(int n) {
//	int ret = 0;
//	for (int m = 1; floor(((double)n - 1) / m) > 0; m++) {//µÓ»•∞°?
//		float tt = n - 1;
//		//int add = floor(tt / m) - ceil(tt / (m + 1)) + 1;
//		int add = floor(tt / m) - floor(tt / (m + 1));
//		//cout << "add is " << add << " m+1 is " << m+1 << endl;
//		add *= (m + 1);
//		//cout <<"add is "<< add << endl;
//		ret += add;
//	}
//	ret++;
//	//int cnt = floor(sqrt(N));
//
//	return ret;
//}

int getNum(int m) {
	return (floor((double)(N - 1) / m) - floor((double)(N - 1) / (m + 1))) * (m + 1);
}

int getDiv() {
	for (int i = 1; i * i <= N; i++) {
		if (N % i == 0) {
			divs.push_back(i);
		}
	}
	if()
	for (int i = divs.size() - 1; i >= 0; i--) {
		divs.push_back(N / i);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	t = 1;
	while(t--) {
		cin >> N;
		int ans = solve();
		cout << ans << endl;
	}
	return 0;
}