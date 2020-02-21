/*

*/
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
#define MAX (int)2e5+5
#define ff first
#define ss second
typedef std::pair <int, int> pii;
#define mp(x,y) make_pair(x,y)

int t;
int n;
int arr[MAX];
bool visit[MAX];
vector<pii> vctpii;

/*
pair i i인데, 첫 인자는 유지중인 해당 인접 수 간의 최단길이, 두 번째 인자는 가장 최근에 나온 인덱스
*/
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	while (t--) {
		bool isdone = false;
		vctpii.clear();
		cin >> n;
		vctpii.reserve(n + 2);
		for (int i = 1; i < n + 1; i++) {//편의상 1번인덱스부터 시작
			cin >> arr[i];
		}

		for (int i = 1; i <= n + 1; i++) {
			pii tmp = { 0,0 };
			vctpii.push_back(tmp);
		}

		for (int i = 1; i <= n; i++) {
			int su = arr[i];
			if (vctpii[su].ss == 0) {
				vctpii[su].ss = i;
			}
			else {
				int nowdiff = abs(i - vctpii[su].ss);
				if (vctpii[su].ff == 0 || nowdiff < vctpii[su].ff) {
					vctpii[su].ff = nowdiff;
				}
				vctpii[su].ss = i;
			}
		}
		sort(vctpii.begin(), vctpii.end());
		for (auto tmp : vctpii) {
			if (tmp.ff == 0)
				continue;
			cout << tmp.ff + 1 << endl;
			isdone = true;
			break;
		}
		if (!isdone)
			cout << -1 << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}