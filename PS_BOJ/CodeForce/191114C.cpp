/*

*/
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
//#include <array>
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
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

/*
일단 길이 2부터 조사. 만일 모배열 길이가 2 미만이면 당연히 불가이므로 -1 출력
길이 2가 무산이라면(==연속된 동일수가 없다면) 길이 3 조사
길이 3도 무산이라면 ... 길이 n까지 조사
*/


/*길이 3 조사라면 당연히 인접한 동일글자는 배열에 없다는 것을 전제로 한다고 봐도 좋다.
즉, abc 또는 aba 말고는 경우의 수가 없다. false는 abc가 유일하고, true는 aba가 유일하다.
길이 4 조사라면, 당연히 3에서 false 떴다는 전제가 붙으므로 abca 가 유일하다.
즉, 동일수가 나온다면 그 시점에서 이전에 떴을 것이다.
즉, 동일수간의 최소간격을 구하면 된다.

33221이라면
2 출력이다. 왜냐하면 3에서 걸러지기에, 또 최소한의 길이만 원하기에.

만약 32231이라면 역시 걸러진다. 2에서.*/

int t;
int n;
int arr[MAX];
bool visit[MAX];

bool hasSubarray(int size, int searchlength) {
	for (int startidx = 0; startidx <= size - searchlength; startidx++) {//idx부터 수색한다
		memset(visit + startidx, false, searchlength);
		for (int pp = 0; pp < searchlength; pp++) {
			int idx = startidx + pp;
			if (visit[arr[idx]])
				return true;
			else
				visit[arr[idx]] = true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	while (t--) {
		bool done = false;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 2; i <= n; i++) {
			if (hasSubarray(n, i)) {
				cout << i << endl;
				done = true;
				break;
			}
			else {
				memset(visit, false, n);
				continue;
			}
		}
		if (!done)
			cout << -1 << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}