/*
N과 M 4
중복조합
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

/*중복순열과 마찬가지로, 중복을 허용하니 visit 배열은 필요없다.
다만, 비내림차순으로 고정되어있으므로, start배열은 유지해야 한다.
그러나 시작점을 start+1이 아니라 start로 하면 된다.
*/

int N, M;
vector<int> mystack;

void MultisetCombination(int Start, int SentakuKazu) {
	if(SentakuKazu == M) {
		for (int i : mystack)
			cout << i << ' ';
		cout << endl;
		return;
	}
	for (int i = Start; i <= N; i++) {/*굳이 i가 Start인지, Start보다 큰지 구별할 필요 없다! 그냥 어차피 감가는 인정안되므로, */
		mystack.push_back(i);
		MultisetCombination(i, SentakuKazu + 1);
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
	MultisetCombination(1, 0);


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}