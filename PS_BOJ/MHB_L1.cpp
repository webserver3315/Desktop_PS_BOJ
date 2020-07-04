#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
11053 가장 긴 증가하는 부분수열
lower_bound 이용한 이분탐색으로 해결
https://red-pulse.tistory.com/152
길이뿐만 아니라 온전한 LIS도 얻을 수 있다.
*/

int N;
vector<int> vct;
int ret;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//cin >> N;
	//for (int i = 0; i < N; i++) {
	//	int tmp; cin >> tmp;
	//	vct.push_back(tmp);
	//}

	cin >> N;
	vct.push_back(-99999999);
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		if (vct.back() < tmp) {
			vct.push_back(tmp);
			ret++;
		}
		else {
			auto it = lower_bound(vct.begin(), vct.end(), tmp);
			*it = tmp;//덮어쓰기
		}
	}
	cout << ret << endl;
	return 0;
}