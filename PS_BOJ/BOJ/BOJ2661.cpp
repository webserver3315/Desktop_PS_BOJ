/*
좋은 수열
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

/*임의의 길이의 인접한 두 개의 부분수열이 동일한 것이 있으면 그 수열을 나쁜 수열이라고 부른다.
예를 들어, 같은 수가 반복되면 나쁜 수열.
2121처럼 같은 패턴이 반복되어도 나쁜 수열.
일단 공백없이 수열을 출력해야하므로, vector<int> IntList 로 유지하자.
그리고, 최소의 좋은수열을 출력해야한다.
수열을 뽑고 검사를 하는가? 검사를 하고 뽑는가?
이 문제의 특징 중 하나는, optimal subset 이 성립한다는 것이다. 좋은수열의 부분수열은 역시 좋은수열이다. 이를 이용하면 dp도 가능하다.
검사를 하고 뽑을 필요는 없다. 수열을 뽑고 새로운 수열에 대한 검사만 하는게 맞다. optimal subset을 활용하기 위해서라면.
중복이 허용되고, 순서 또한 신경써야하므로 매번 1부터 3까지 검사때리는 중복순열이다.

이 문제는 쪼갤 필요는 없다고 보인다.
아니, 가능하네. 쪼개야하네.
1. DFS함수
2. 현재 유지중인 IntList가 좋은 수열인지 아닌지 판별하는 함수
*/

int N;
vector<int> IntList;
vector<int> Kotae;

//bool HasSubset(vector<int>::iterator MotherBegin, vector<int>::iterator MotherEnd, vector<int>::iterator SonBegin, vector<int>::iterator SonEnd) {
//	int MotherLength = MotherBegin - MotherEnd; int SonLength = SonBegin - SonEnd;
//	for (vector<int>::iterator MotherStart = MotherBegin; MotherStart < MotherEnd - SonLength; MotherStart++) {
//		
//	}
//}

bool IsFine() {/*겹치는 부분수열이 있는지 검색하는 함수이다. 부분수열은 길이 1이 될 수도 있고, N-1이 될 수도 있다.
			   어떻게 체크할까. 길이 1부터 IntList.size()-1 만큼의 길이를 상정하고 그 횟수만큼 순회돌릴까. n(n-1)/2의 연산횟수가 소요될 것이다.
			   뭐 이렇게 멍청하게 푼다고 하더라도 사실 1억번 연산 내라 초여유롭다.*/
	for (int length = 1; length < IntList.size(); length++) {//혹시 size()는 unsigned로 리턴되기에 자잘한 오류가 생기지 않을까..불안하노
		for (int start = 0; start < IntList.size() - length; start++) {
			 IsSubset = search(IntList.begin(), IntList.end(), IntList.begin() + start, IntList.begin() + start + length);
			if (IsSubset)
				return false;
		}
	}
	return true;
}

void DFS(int depth) {
	if (depth == N) {
		if (Kotae.empty())
			Kotae = IntList;
		return;
	}
	for (int i = 1; i <= 3; i++) {
		IntList.push_back(i);
		if (IsFine())
			DFS(depth + 1);
		IntList.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;

	DFS(0);

	for (int tmp : Kotae)
		cout << tmp;
	cout << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}