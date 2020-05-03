/*
숨바꼭질
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
#include <cstring>
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


/*수빈이는 점 N에 있고 동생은 점 K에 있다.
수빈이는 걷거나 순간이동이 ㄱㄴ하다
걸음은 1초에 +-1칸 가능하다
순간이동은 반드시 2배의 좌표로 이동한다.
수빈이가 동생을 찾을 수 있는 가ㅂ장 빠른 시간은 몇 초 후인가?

동생과 수빈이의 좌표는 0이상 10만 이하이다.
*/

/*생각없이 분기쳤다가는 시간초과되지않을까. 일단 2초 주긴 했다만
이거 DP로 ㅆㄱㄴ아닌가? 10만배열 순회하면서. 순회가 빠르려나 아니면 확보한 분기에 대해서만 ㄱㄱ하는게 빠르려나.

일단은 최적해를 찾는거니까 BFS가 적절하고
DP말고 일반적인 BFS로 풀어보자
*/

//int PointArrivalTime[100001];

typedef pair<int, int> PointArrivalTime;//x 좌표에 도달하는데는 최소 y초가 소모됨을 뜻함
queue<PointArrivalTime> Queue;
int N, K;
bool visited[1000001];

void BFS() {
	Queue.push({ N,0 });
	visited[N] = true;
	while (!Queue.empty()) {
		PointArrivalTime nowPoint = Queue.front();
		Queue.pop();
		if (nowPoint.first == K) {
			cout << nowPoint.second << endl;
			//exit(0);
			break;
		}
		int f1 = nowPoint.first + 1;
		if (f1 >= 0 && f1 <= 100000 && !visited[f1]) {//여기에 추가적으로 "방문해본 적 없는 좌표일 때" 라는 조건을 추가한다면 좀 더 효율적이긴 할 것이다.
			Queue.push({ f1,nowPoint.second + 1 });
			visited[f1] = true;
		}

		int f2 = nowPoint.first - 1;
		if (f2 >= 0 && f2 <= 100000 && !visited[f2]) {
			Queue.push({ f2,nowPoint.second + 1 });
			visited[f2] = true;
		}

		int f3 = nowPoint.first * 2;
		if (f3 >= 0 && f3 <= 100000 && !visited[f3]) {
			Queue.push({ f3,nowPoint.second + 1 });
			visited[f3] = true;
		}
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> K;

	BFS();

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}