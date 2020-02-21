/*
텀 프로젝트

반복문을 이용해서 풀려는 생각은 앵간해서는 자제하도록 하자
어차피 완탐을 해야한다면, 교묘한 반복문보다 DFS가 더 효율적이다.

10만개의 케이스라도 800밀리초밖에 안걸리는데 왜 시간초과뜨나 해서
예전에 합격한 C코드를 돌려봤는데
C코드는 88초밖에 안걸렸다.
즉, 이게 압도적으로 느린게 맞다.
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
int sasumono[StuMax];
bool visited[StuMax];
bool done[StuMax];
int cnt;
vector<int> vii;

/*벡터에서 정렬 후 중복되는 인접인자 제거 방법?*/

int DFS(int n) {
	if (visited[n]) {//돌아왔을 경우
		/*int next = sasumono[n];
		vii.push_back(n);*/
		//int cnt = 0;
		while (!done[n]) {
			done[n] = true;
			//cout << n << " 은 확실한 사이클로 푸시" << endl;
			//vii.push_back(n);
			cnt++;
			n = sasumono[n];
		}
		memset(visited + 1, false, N);
		return cnt;
	}
	if (done[n])
		return 0;
	visited[n] = true;
	//cout << n << " 에서 " << sasumono[n] << " 으로 향합니다" << endl;
	DFS(sasumono[n]);
	//visited[n] = false;
	//memset(visited, false, N);//매번 memset 때리는게 생각보다 시간 굉장히 많이 잡아먹었다.
	return 0;
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
		for (int i = 1; i <= N; i++) {
			cin >> sasumono[i];
		}
		//int inssa = 0;
		for (int start = 1; start <= N; start++) {
			//inssa += DFS(start);
			if(!done[start])
				DFS(start);
		}

		//cout << N - vii.size() << endl;
		cout << N - cnt << endl;
		cnt = 0;
		//vii.clear();
		memset(done + 1, false, N);
		memset(visited + 1, false, N);//일단 이거 꽤나 시간적으로 결정적이다. 800밀리초에서 250대로 낮아짐.
	}

	

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	cout << ctime_duration << " ms" << endl;
	return 0;
}