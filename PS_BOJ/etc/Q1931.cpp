/*
회의실 배정
*/

/*
회의는 시작int 종료int로 구성된 pair로 구현하고
2번째 인자를 key로 한 최소힙을 이용해 우선순위 큐를 구현한다
다만, 판별과정에서 팝된 첫 인자가 현재의 2번째 인자보다 작다면 기각이다. 다시 팝한다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int > Time;

int n, cnt;
Time kouhou;
Time now = pair<int, int>(0, 0);

//priority_queue< pair<int, int >, vector<int>, pair_second_compare() > TimeList;
priority_queue<Time, vector<Time>, greater<Time>> pq;/*최소힙이다*/

int main() {
	cin >> n;
	while (n--) {
		int fir, sec;
		scanf("%d %d", &fir, &sec);
		pq.push(Time(sec, fir));/*주의!!! 첫 항에 ENDTIME이, 말항에 STARTTIME이 입력된다!*/
	}
	while (!pq.empty()) {
		kouhou = pq.top();
		if (kouhou.second < now.first) {/*팝된 후보회의의 시작시간이 현재 회의종료시간보다 이를 경우*/
			pq.pop();
		}
		else {
			now = kouhou;
			pq.pop();
			++cnt;
		}
	}
	printf("%d\n", cnt);
	return 0;
}