/*
A
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

/*테스트케이스 갯수는 t개, 100개 이하
문자열이 주어진다. 500글자 이하이다.
문자열을 보고, 확실히 작동함을 보장할 수 있는 자판들을 사전순으로 나열하라.
고장난 자판은 중복입력된다.

앞뒤가 자신과 모두 다른 철자가 있다면 해당 철자는 안전한 자판이라고 확신가능하다.
일방으로 탐색시 뒤만 확인하면 될 듯 하다.

만일, 제대로 작동하는 자판이 없다면, 공백출력 및 개행하라.
*/

int T;
string Strings[102];//화면에 나온 철자
set<string> Kakusin[102];//확신할 수 있는 자판들

void GetNoBroken(int Case, string answer) {
	if (answer.size() == 1)
		cout << answer;
	else {
		for (int idx = 0; idx < answer.size() - 1; idx++) {
			if (answer[idx] == answer[idx + 1])
				idx++;
			else {
				string inserting(1, answer[idx]);
				Kakusin[Case].insert(inserting);
			}
		}
		if (answer.back() != answer[answer.size() - 2]) {
			string inserting(1, answer.back());
			Kakusin[Case].insert(inserting);
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> Strings[i];
	}

	/*for (int i = 0; i < T; i++) {
		int idx = 0;
		for (; idx < Strings[i].size() - 1; idx++) {
			if (Strings[i][idx] == Strings[i][idx + 1]) {
				idx++;
				continue;
			}
			else {
				Kakusin[i].insert(Strings[i][idx]);
			}
		}
		if (Strings[i].size() != 1) {
			if (Strings[i][Strings[i].size() - 1] == Strings[i][Strings[i].size() - 2]) {
				Kakusin[i].insert(Strings[i][idx]);
			}
		}
		else {
			Kakusin[i].insert(Strings[i][idx]);
		}
	}*/

	for (int i = 0; i < T; i++) {
		GetNoBroken(i, Strings[i]);
	}

	for (int i = 0; i < T; i++) {
		for (string c : Kakusin[i]) {
			cout << c;
		}
		cout << endl;
	}

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}