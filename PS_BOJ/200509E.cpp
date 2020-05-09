#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
업데이트가 없으므로 세그트리말고 구간합 쓰면 되겠다
*/

int t;
int n;
int arr[8003];
int psum[8003];
int cnt;

int query(int l, int r, int i) {//i인덱스의 값이 l인덱스 이상 r 인덱스 이하 구간의 값을 더했을 때, 
	int seg = psum[r] - psum[l];
	if (seg == arr[i]) return 0;
	else if (seg > arr[i]) return 1;
	else return -1;
}

bool aq(int i) {//i인덱스를 전부 쿼리날린다. 스페셜 원소면 트루, 아니면 거짓
	for (int l = 0; l <= n - 1; l++) {
		for (int r = l + 2; r <= n; r++) {
			if (query(l, r, i) == 0) {
				//cout << l << " " << r << "의 lr값에서 합이 동일하므로," << i << " 인덱스는 특수원소" << endl;
				return true;
			}
			else if (query(l, r, i) == 1) break;
			else continue;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		memset(psum, 0, sizeof(psum)); cnt = 0;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (i != 0) psum[i] = psum[i - 1] + arr[i];
			else psum[i] = arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (aq(i)) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}