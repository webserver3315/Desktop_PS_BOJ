/*
N과 M 11
중복순열
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
//typedef pair <int, int> P;
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용
//#define mp(x,y) make_pair(x,y)//고인물용

using namespace std;

/*일단 가장 naive하게 이전과 마찬가지로 set 을 이용해 중복출력을 배제시키자.

*/

int N, M;
vector<int> mystack;
vector<int> kouhou;
set<vector<int>> mukashi;

void MultisetPermutation3(int depth) {
	if (depth == M) {
		if (mukashi.find(mystack) != mukashi.end())
			return;
		mukashi.insert(mystack);
		for (int tmp : mystack)
			cout << tmp << ' ';
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		mystack.push_back(kouhou[i]);
		MultisetPermutation3(depth + 1);
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
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		kouhou.push_back(tmp);
	}
	sort(kouhou.begin(), kouhou.end());

	MultisetPermutation3(0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}