#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
11053 ���� �� �����ϴ� �κм���
lower_bound �̿��� �̺�Ž������ �ذ�
https://red-pulse.tistory.com/152
���̻Ӹ� �ƴ϶� ������ LIS�� ���� �� �ִ�.
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
			*it = tmp;//�����
		}
	}
	cout << ret << endl;
	return 0;
}