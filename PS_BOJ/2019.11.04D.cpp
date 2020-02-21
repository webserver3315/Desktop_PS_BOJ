/*
#598 Div3 D
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

#define swap(type, a, b) do{type tmp; tmp=a; a=b; b=tmp;}while(0)

int operation(string& bin) {
	for (int i = 1; i < bin.size(); i++) {
		if (bin[i] == '0' && bin[i - 1] == '1') {
			swap(char, bin[i], bin[i - 1]);
			return 0;
		}
	}
	return 1;
}

int q, n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> q;
	while (q--) {
		cin >> n >> k;
		string bin;
		cin >> bin;
		int ans = 0;
		while (k-- && ans != 1) {
			int i;
			for (i = 1; i < bin.size(); i++) {
				if (bin[i] == '0' && bin[i - 1] == '1') {
					swap(char, bin[i], bin[i - 1]);
					break;
				}
			}
			if (i == bin.size())
				break;
		}
		cout << bin << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}