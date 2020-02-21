/*
바이러스
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
using namespace std;
#define endl '\n'
//#define ff first
//#define ss second
//typedef std::pair <int, int> P;//error C2143: 구문 오류 : ';'이(가) '<' 가 발생하므로 std:: 을 붙여서 충돌을 없애주었다.
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

/*이번엔 dfs로 풀어보자. 이건 BFS로 풀면 10분컷내니까.
100대 이하의 컴퓨터 수가 주어지고, 둘째줄부터는 간선수, 그 다음부터는 간선이 주어진다.
항상 1번컴퓨터가 첫 빠따로 감염된다.
1번컴퓨터는 몇 대의 컴퓨터에 바이러스를 옮기는가?
*/

int N, E;
bool AdjTable[102][102];
bool visited[102] = { true, };//1번컴은 무조건 감염
int HowMany;

void DFS(int kara) {
	HowMany++;
	for (int made = 1; made <= N; made++) {//made==まで
		if (!visited[made] && AdjTable[kara][made]) {//안들렀고 인접한 노드에 대해
			visited[made];
			DFS(made);
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

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		AdjTable[num1][num2] = true; AdjTable[num2][num1] = true;
	}

	DFS(1);

	cout << HowMany << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}