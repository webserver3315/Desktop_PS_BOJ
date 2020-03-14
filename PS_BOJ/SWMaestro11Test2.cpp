#include <bits/stdc++.h>
#define endl '\n'
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define pii pair<int,int>
using namespace std;

int N, K;
vector<int> vct;
//multimap<int,int> minIdx;//최소값들의 위치_key=값,val=위치
int idx1;
int minval = INT32_MAX;
int L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int cnt = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vct.push_back(tmp);
		if (tmp == 1)
			idx1 = i;
	}
	L = idx1;
	R = N - idx1 - 1;
	cnt += ceil(L / (K - 1));
	cout << "좌에서 " << cnt << " 더함" << endl;
	L %= (K - 1);
	R -= (K - 1 - L);
	cout << "우가 " << R << " 이 됨" << endl;
	cout << "우에서 " << ceil(R / (K - 1)) << " 더함" << endl;
	cnt += ceil(R / (K - 1));
	cout << cnt << endl;

	return 0;
}