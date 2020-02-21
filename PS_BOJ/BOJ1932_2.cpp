/*
정수삼각형
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

/*1 2 3 4 개 순으로 원소수가 열당 증가하는 정수삼각형이 있다.
좌 또는 우측 자식으로밖에 못갈 때, 바닥까지 최대합으로 이동하는 경로를 구하는 프로그램을 작성하라.
아니, 경로가 아니라 최대비용을 출력하라.
>>만약 ㄹㅇ 경로를 파악해야했으면 경로유지 하나때문이라도 dfs 가 매우 적절했을텐데, 비용만 산출하면 되니 상관없군.

500층까지 ㄱㄴ한 삼각형이 주어진다. 최대경로의 합을 2초내에 출력하라.
오로지 음이 아닌 정수만 입력됨이 보장된다.
*/

/*
인덱스를 보면
		0
	  1   2
	3   4   5
  6   7   8   9
10  11  12  13  14
규칙 없나... 이거 트리의 경우 인덱스에 2배의 규칙이 성립하긴 하는데 이진트리가 아니니...
아니 그냥 500*500 배열로 봐볼까.
tri[0][0]은 [1][0], [1][1]로 갈 수 있으니 일반화하면
tri[r][c]는 tri[r+1][c] 또는 tri[r+1][c+1]로 갈 수 있다고 일반화ㄱㄴ. 굳

n층까지 내려가는데 드는 최대비용을 n이라고 할 때
층이 아니라 각 칸마다 해당칸까지 도달하는데 드는 최대비용을 유지시키자.
memo[r][c] = max( memo[r-1][c], memo[r-1][c+1] ) + tri[r][c];
DP[n]=max(for i in range n : memo[n][i])

이 식은
DP2(r,c)=max(DP2(...) 이렇게 표현가능
DP(n)=max(for c in range n : DP2(n,c))
*/

int n;
int tri[503][503];
int memo[503][503];
bool visit[503][503];

void printmemo() {
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= r; c++) {
			cout << memo[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

int DP2(int r, int c) {//[r][c]까지 가는데 드는 최대비용
	//cout << "called " << r << ' ' << c << endl;
	if (r <= 0 || c <= 0)
		return 0;
	else if (visit[r][c])
		return memo[r][c];
	else if (c == r) {
		memo[r][c] = DP2(r - 1, c - 1) + tri[r][c];
		//visit[r][c] = true;
		//return memo[r][c];
	}
	else if (c == 1) {
		memo[r][c] = DP2(r - 1, c) + tri[r][c];
		//visit[r][c] = true;
		//return memo[r][c];
	}
	else
		memo[r][c] = max(DP2(r - 1, c - 1), DP2(r - 1, c)) + tri[r][c];
	visit[r][c] = true;
	return memo[r][c];
}

int DP(int R) {//R:층수(깊이)_정점은 1층으로 취급, 그 아래부터 2층부터다.
	int maxval = 0;
	for (int c = 1; c <= R; c++) {
		if (maxval < DP2(R, c))
			maxval = DP2(R, c);
	}
	return maxval;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> n;
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= r; c++) {
			cin >> tri[r][c];
		}
	}
	memo[1][1] = tri[1][1];
	memo[2][1] = tri[1][1] + tri[2][1];
	memo[2][2] = tri[1][1] + tri[2][2];
	visit[1][1] = true; visit[2][1] = true; visit[2][2] = true;

	cout << DP(n) << endl;

	//printmemo();

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	cout << ctime_duration << " ms" << endl;
	return 0;
}