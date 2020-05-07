/*
텀 프로젝트
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
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

#define StuMax 100005

int T, N;
int sasu[StuMax];
bool visit[StuMax];
bool done[StuMax];
int cnt;

void DFS(int stu) {//done 된 stu가 들어오지 않는다는 보장은 되어있다는 전제로 짠다.
	visit[stu] = true;
	int next = sasu[stu];
	/*if (done[stu]) {
		cout << stu << "는 done 되었으므로 거른다" << endl;
		return;
	}*/
	if (!visit[next]) {//unvisited면
		cout << stu << "에서 " << next << " 로 가자" << endl;
		DFS(next);
	}
	else if(!done[next]){//visited && undone
		/*int originnext = next;
		for (next = sasu[next]; next != originnext; next = sasu[next]) {
			cout << next << "루프로 카운트하고 " << sasu[next] << " 로 가자" << endl;
			cnt++;
		}
		cnt++;*/
		for (int i = next; i != stu; i = sasu[i]) {
			cnt++;
		}
		cnt++;
	}
	cout << stu << "는 done 때렸다" << endl;
	done[stu] = true;//사이클이든 아니든, 한 번 방문했으면 재차확인해도 사이클여부결과는 동일하므로 더 이상 확인할 일이 없다
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> T;
	while (T--) {
		cin >> N;
		memset(visit + 1, false, N);
		memset(done + 1, false, N);
		cnt = 0;
		for (int i = 1; i <= N; i++) {
			cin >> sasu[i];
		}

		for (int i = 1; i <= N; i++) {
			if(!done[i])
				DFS(i);
		}
		cout << N - cnt << endl;
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}