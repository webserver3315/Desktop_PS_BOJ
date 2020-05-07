/*
N과M 5
순열
인풋값은 비연속값으로 주어진다. 단 중복값은 없다.
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
vector<int> kouhou;
vector<int> mystack;
bool visited[10];

void Permutation2(int depth) {
	if (depth == M) {
		for (int i : mystack)
			cout << i << ' ';
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (visited[i])
			continue;
		visited[i] = true;
		mystack.push_back(kouhou[i]);
		Permutation2(depth + 1);
		visited[i] = false;
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

	Permutation2(0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}