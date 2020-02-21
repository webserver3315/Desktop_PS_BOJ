/*
#598 Div3 A
*/
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

/*n원의 코인 a개가 있고 1원의 코인 b개가 있다
정확한 거스름돈으로 지불하고자 할 때

인풋은 a,b,n,S

n, 1코인을 각각 x,y개 써서 S원을 만들 때 가능? 불가능?
테케 q


*/

int q, a, b, n, S;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> q;
	while (q--) {
		cin >> a >> b >> n >> S;
		/*while (a-- && S >= n) {
			S -= n;
		}*/
		int div = min(S / n, a);
		a -= div;
		S -= n * div;
		/*
		while (b-- && S > 0) {
			S -= 1;
		}*/

		if (b >= S)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}