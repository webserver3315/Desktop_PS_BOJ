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
vector<int> minIdx;
int minval = INT32_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int tmp;
		vct.push_back(tmp);
		if (tmp < minval) {
			minval = tmp;
			minIdx.clear();
			minIdx.push_back(0);
			minIdx.push_back(i);
		}
		else if (tmp == minval) {
			minIdx.push_back(i);
		}
	}
	minIdx.push_back(N - 1);

	return 0;
}