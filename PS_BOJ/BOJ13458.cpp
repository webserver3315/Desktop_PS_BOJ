/*
시험 감독
*/

#include <iostream>
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
#include <ctime>
#include <climits>
#define endl '\n'
//#define X first
//#define Y second
//typedef pair <long long, long long> P;
//P mypair = make_pair(1.2);//권장사항
//pair<long long, long long> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용
using namespace std;


/*N개의 시험장이 있고 각각 응시자들이 있음.
i번 시험장에 Ai명의 응시자가 있다.
감독관은 한 방에 B명을, 부감독관은 한 방에 C명을 감시할 수 있는 능력을 가지고 있다.
각각의 시험장에 총감독관은 오직 1명이다. 부감독관은 여럿 ㄱㄴ하다.
이 때 필요한 감독관 수의 최솟값을 구하라.

첫 줄에는 시험장의 개수 N
둘쨰 줄에는 각 시험장에 있는 응시자의 수 Ai(각각 다 다르다)
셋째줄에는 감독역량파라미터인 B, C가 주어진다.

*/

long long N, B, C;
vector<long long> Class;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;
	for (long long i = 0; i < N; i++) {
		long long tmp;
		cin >> tmp;
		Class.push_back(tmp);
	}
	cin >> B >> C;

	long long Main_Kantoku = 0; long long Sub_Kantoku = 0;

	for (long long& nokori : Class) {
		nokori -= B;
		if (nokori < 0)
			nokori = 0;
	}
	Main_Kantoku += Class.size();

	for (long long& nokori : Class) {
		long long hitsuyou = (long long)ceil(nokori / (float)C);
		Sub_Kantoku += hitsuyou;
	}

	long long Total_Kantoku = Main_Kantoku + Sub_Kantoku;
	cout << Total_Kantoku << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}
/*long long으로 처리를 안해줘서 int 한계값을 초과해버려서 틀렸습니다가 나왔던 모양이다.
문제에서 항당 100만을 넘는 값을 허용한다면 long long 쓰자.
치졸하지만 이렇게라도 정답률 낮추려고 하나보다.*/