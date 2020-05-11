#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

vector<int> vct;
int m, n;

//파라매트릭 서치다.

bool isok(int k) {//k길이로 m명에게 배분할 수 있는지
	int cnt = 0;
	for (int i = vct.size() - 1; cnt < m && i >= 0; i--) {
		cnt += vct[i] / k;
	}
	//for (auto l : vct)
	//	cnt += l / k;
	if (cnt >= m) return true;
	else return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	//cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		vct.push_back(tmp);
	}
	sort(vct.begin(), vct.end());
	int l = 1; int r = vct.back(); int mid = (l + r) / 2;
	while (l <= r) {
		if (mid == 0) {
			cout << 0 << endl;
			return 0;
		}
		if (isok(mid)) {//더 잘라도 됨
			l = mid + 1;
			mid = (l + r) / 2;
		}
		else {//덜 잘라야 함
			r = mid - 1;
			mid = (l + r) / 2;
		}
	}
	cout << mid << endl;
	
	return 0;
}