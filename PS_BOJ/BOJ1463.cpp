/*
1로 만들기
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
#include <cstring>
#include <cstdio>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
#define ff first
#define ss second
typedef std::pair <int, int> pii;
#define mkp(x,y) make_pair(x,y)
//pii mkpii = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

/*dp로 풀면 되는 문제다.
일단 3으로 나누어 떨어지면 3으로, 2로 나누어떨어지면 2로, 노답이면 1을 빼는 식으로 1에 근사하도록 솔빙하면 된다.
그러나, 시간적으로 넉넉치 않다. 입력값의 상한은 10의 6승인데(100만) 주어지는 시간은 2이다.
연산횟수의 최솟값을 출력하면 되는 문제인데, top down인지 bottom up인지를 잘 판단해야 할 듯 하다.
bottom up이 더 나을 듯 하긴 한데
아니다. 그냥 이거 두드려박아도 풀리지 않나? 애초에 테스트케이스 여러개도 아닌데...

일단 dp 안쓰고 풀어봐야겠다. 굳이 필요가 없어보인다.

아, 이거 dp 써야한다. 그리디하게 풀리는 문제가 아니다.
10 주어지면 닥치고 2 나누고 1 빼고 2 나누고 이렇게 매뉴얼대로 가는게 아니다.
이 문제는 정해진 매뉴얼이 없다. 그러므로 모든 경우의 수를 고려하지 않으면 안된다.
*/

int Solve(int N, int depth) {
	if (N == 1) {
		return depth;
	}
	if (N % 3 == 0) {
		return Solve(N / 3, depth + 1);
	}
	else if (N % 2 == 0) {
		return Solve(N / 2, depth + 1);
	}
	else {
		return Solve(N - 1, depth + 1);
	}
}

/*앞선풀이에서 참교육당하고, dp로 풀기로 했다. optimal substructure임이 자명하므로 dp로 풀림이 보장된다.
일단 visit 배열이 필요하려나 싶었지만 필요없다. 그냥 int배열이 0이면 unvisited, 양수면 visited로 인식하면 된다. 또한 값은 해당 값으로 가는데 필요한 최저비용으로 계산하면 된다.
만일 가지를 뻗을 자리가 visited라면 최저비용이 아닐게 뻔하므로, 거르면 된다.
즉 top down이다.
*/

int Memo[1000002];

/*안된다. DP_BFS로 다시 풀어보자. 애초에 DP로 최적해를 찾아야 하는데 DFS를 써버리면 결국 다 훑어야 한다는 저에는 변함이 없잖아?*/
void DP(int N) {
	if (N == 1) {
		//cout << Memo[N] << endl;
		return;
	}
	if (N % 3 == 0) {
		if (Memo[N / 3] == 0 || Memo[N / 3] > Memo[N] + 1) {
			Memo[N / 3] = Memo[N] + 1;
			DP(N / 3);
		}
	}
	if (N % 2 == 0) {
		if (Memo[N / 2] == 0 || Memo[N / 2] > Memo[N] + 1) {
			Memo[N / 2] = Memo[N] + 1;
			DP(N / 2);
		}
	}
	if (Memo[N / 3] == 0 || Memo[N / 3] > Memo[N] + 1) {
		Memo[N - 1] = Memo[N] + 1;
		DP(N / 1);
	}
	return;
}

void DP_BFS(int N) {
	queue<pii> Queue;
	Queue.push(mkp(N, 0));
	while (!Queue.empty()) {
		pii nowPosition = Queue.front();
		Queue.pop();
		int f = nowPosition.ff; int s = nowPosition.ss;
		if (f == 1) {
			//cout << s << endl;
			return;
		}

		if (f % 3 == 0) {/*bfs의 경우, 처음 나온 해가 반드시 최적해라고 보장이 가능하므로 처음 나온 1이 굳이 최적인지 체크를 할 필요가 없다*/
			if (Memo[f / 3] == 0 || Memo[f / 3] > Memo[f] + 1) {
				Memo[f / 3] = Memo[f] + 1;
				Queue.push(mkp(f / 3, s + 1));
			}
		}
		if (f % 2 == 0) {
			if (Memo[f / 2] == 0 || Memo[f / 2] > Memo[f] + 1) {
				Memo[f / 2] = Memo[f] + 1;
				Queue.push(mkp(f / 2, s + 1));
			}
		}
		if (Memo[f - 1] == 0 || Memo[f - 1] > Memo[f] + 1) {
			Memo[f - 1] = Memo[f] + 1;
			Queue.push(mkp(f - 1, s + 1));
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

	int n;
	cin >> n;
	//cout << Solve(n, 0) << endl;
	DP_BFS(n);

	cout << Memo[1] << endl;


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " sec" << endl;
	return 0;
}