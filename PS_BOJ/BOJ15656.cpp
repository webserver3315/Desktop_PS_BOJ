/*
N과M 7
중복순열
인풋값은 중복없는 비연속값으로 주어짐
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
vector<int> kouhou;

void MultisetPermutation(int depth) {
	if (depth == M) {
		for (int i : mystack)
			cout << i << ' ';
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		mystack.push_back(kouhou[i]);
		MultisetPermutation(depth + 1);
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

	MultisetPermutation(0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}