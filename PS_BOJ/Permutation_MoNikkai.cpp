/*

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
bool visited[10];
vector<int> mystack;
/*Permutation이다. 전진만이 불가하니, visit 배열이 필요하다.*/

void Permutation(int SentakuKazu) {
	if (SentakuKazu == M) {
		for (int i : mystack) {
			cout << i << ' ';
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i]) {
			continue;
		}
		visited[i] = true;
		mystack.push_back(i);
		Permutation(SentakuKazu + 1);
		mystack.pop_back();
		visited[i] = false;
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
	Permutation(0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}