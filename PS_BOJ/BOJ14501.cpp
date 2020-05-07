/*
퇴사

벡터스택을 이용한 DFS로 모든 경우의 수를 완탐하고, 여태 나온 최대의 maxmoney를 겟한다.
*/

#include <iostream>
#define endl '\n'
#define MAX 17
using namespace std;

int N;
int time[MAX];
int cost[MAX];
int maxmoney;

void DFS(int day, int earned, int saikinEarned) {//날짜, 번 돈 총액, 가장 최근의 일한 날에 번 돈
	if (day > N + 1) {
		int earnedmoney = earned - saikinEarned;
		if (maxmoney < earnedmoney)
			maxmoney = earnedmoney;
		return;
	}
	else if (day == N + 1) {
		int earnedmoney = earned;
		if (maxmoney < earnedmoney)
			maxmoney = earnedmoney;
		return;
	}
	DFS(day + time[day], earned + cost[day], cost[day]);
	DFS(day + 1, earned, saikinEarned);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> time[i] >> cost[i];
	}
	DFS(1, 0, 0);
	cout << maxmoney << endl;

	return 0;
}