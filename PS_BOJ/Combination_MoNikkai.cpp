/*
Combination Mo nikkai
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <climits>
#define endl '\n'
//#define X first
//#define Y second
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용

using namespace std;

int N, M;
vector<int> mystack;
/*
conbination이니까 굳이 visit 할 필요 없이 전진만 하면 된다. start 변수를 permutation에서 추가시킨 후, 유지를 잘 해주면 된다.
*/

void Combination(int Start, int SentakuKazu) {
	if (SentakuKazu == M) {
		for (int i : mystack) {
			cout << i << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = Start; i <= N; i++) {
		mystack.push_back(i);
		Combination(i + 1, SentakuKazu + 1);/*start+1 이 아니라 첫 인자는 i+1 임에 주의 항상 하라!*/
		mystack.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	Combination(1, 0);


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}