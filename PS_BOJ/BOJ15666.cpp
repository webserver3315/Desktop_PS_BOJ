/*
N과 M 12
중복조합
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

/*중복조합이다. 시간에 민감한 아까와 마찬가지로 우선은 NAIVE하게 set으로 풀어보자.
*/

int N, M;
vector<int> mystack;
vector<int> kouhou;
set<vector<int>> mukashi;


/*중복조합이니, 일단 정렬된 kouhou라는 전제 하에 전진만 하면 된다.
고로, 별도로 start가 필요하다.*/
void MultisetCombination3(int depth, int start) {
	if (depth == M) {
		if (mukashi.find(mystack) != mukashi.end())/*만일 set에 이미 있는 예비output이라면*/
			return;
		mukashi.insert(mystack);
		for (int tmp : mystack)
			cout << tmp << ' ';
		cout << endl;
		return;
	}
	for (int i = start; i < N; i++) {
		mystack.push_back(kouhou[i]);
		MultisetCombination3(depth + 1, i);/*i+1이 아니라 i라는 점이 Combination과 MultisetCombination의 차이이다. 물론, start 가 아님에 주의해야한다.*/
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

	MultisetCombination3(0, 0);

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}