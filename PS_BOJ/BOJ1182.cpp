/*
부분수열의 합

-예전에 풀어본 문제다. 심지어 C로도 무난히 풀었다. 30분컷내자
>>>12분걸렸다.
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

/*부분수열의 정의: 굳이 연속될 필요는 없다. 그냥 딱 따오기만 하면 된다. 원소는 중복으로 주어질 수 있으며, 비정렬로 주어진다.
정수는 20까지 받는 걸로 일단 되어있다. 정수의 절댓값은 10만을 넘지 않으므로 int범위는 초과하지 않는다.
재귀를 이용한 dfs로 0~n, 1~n, 2~n 이런 식으로 구현해나가면 금방 가능하다. 즉, 완탐_백트래킹이다.

dfs를 위해서는 매개변수로 depth, sum을 유지할 필요가 있다. start는 항상 전진으로만 검색할 것이므로 유지할 필요가 없다.
*/

int N, S, cnt;
vector<int> GlobalVct;

int BackTracking(int depth, int sum) {
	if (depth >= N) {
		return 0;
	}
	if (sum + GlobalVct[depth] == S) {
		cnt++;
	}
	BackTracking(depth + 1, sum + GlobalVct[depth]);
	BackTracking(depth + 1, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		GlobalVct.push_back(tmp);
	}
	BackTracking(0, 0);
	cout << cnt << endl;
	return 0;
}