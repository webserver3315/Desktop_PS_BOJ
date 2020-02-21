/*
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

int q;
int a, b, c;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> q;
	int maxnum;
	int diff = 0;
	while (q--) {
		cin >> a >> b >> c >> n;
		maxnum = max(a, b);
		maxnum = max(maxnum, c);
		diff = 3 * maxnum - a - b - c;

		if (n < diff) {
			cout << "NO" << endl;
			continue;
		}
		else {
			if (n % 3 == diff % 3) {
				cout << "YES" << endl;
				continue;
			}
			else {
				cout << "NO" << endl;
				continue;
			}
		}
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}