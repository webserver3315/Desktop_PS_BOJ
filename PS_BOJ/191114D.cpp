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
단순히 그리디하게 제일 적절한 영웅 출격시킴면 되겠는데?
*/

int t;
int n, m;//몬스터 및 영웅 수
int mobpow[MAX];
int herpow[MAX];
int herend[MAX];
int killed;//조진 몬스터 수
int day;//걸린 날짜

int ifGetIn(int idx) {//idx번 영웅이 던전레이드 뛰면 몇마리를 조질 수 있는가를 출력
	int chikara = herpow[idx]; int tairyoku = herend[idx];
	int tsugi = killed;
	int killmark = 0;
	while (tairyoku--) {
		if (chikara >= mobpow[tsugi]) {
			tsugi++;
			killmark++;
		}
		else
			break;
	}
	return killmark;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	while (t--) {
		bool nodap = false;
		killed = 0; day = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> mobpow[i];
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> herpow[i] >> herend[i];
		}

		while (killed < n) {
			int mostcankill = 0;
			int pick = -1;
			for (int i = 0; i < m; i++) {
				int couldkill = ifGetIn(i);
				if (couldkill > mostcankill) {
					mostcankill = couldkill;
					pick = i;
				}
			}

			if (mostcankill == 0) {//더 이상 노답이면
				cout << -1 << endl;
				nodap = true;
				break;
			}
			killed += mostcankill;
			day++;
		}
		if(!nodap)
			cout << day << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}