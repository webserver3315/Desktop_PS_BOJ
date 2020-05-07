/*
텀 프로젝트
다시풀어보자. 복잡하게 말고 굉장히 비효율적이지만 디버깅편하게.
반복 및 if문으로만 풀어보자

1
15
1 15 12 15 10 1 1 15 14 9 4 3 10 7 13
가 인풋되었을 때 4를 서칭할 때 15부터를 루프문으로 인식하는 중대결함이 있다.
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

int T, N;
//vector<vector<int>> vvi;
vector<int> vi;
int sasumono[100005];
int cycled[100005];//0:미방문 1:방문인데 왕따확정 2: 사이클생성
bool visit[100005];

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


		for (int i = 1; i <= N; i++) {
			cout << i << " 서칭" << endl;
			if (i == 4) {
				int stop = 1;
				cout << stop << "멈춤" << endl;
			}
			if (cycled[i]) {
				cout << i << "는 가망없으니 손절한다" << endl;
				continue;
			}
				/*int next = sasumono[i];
				sasumono[i] = -1;
				while (sasumono[next] != -1) {
					int tmp = sasumono[next];
					sasumono[next] = -1;
					next = tmp;
				}
				int kaiki = next;
				next=
				while()*/
			int next = sasumono[i];
			cout << i << " 에서 " << next << " 로" << endl;
			cycled[i] = 1;
			while (!cycled[next]) {
				cycled[next] = 1;
				cout << next << " 에서 " << sasumono[next] << " 로" << endl;
				next = sasumono[next];
			}

			//사이클을 측정
			while (!visit[next]) {
				visit[next] = true;
				cout << next << " 를 사이클확정 벡터에 푸시합니다" << endl;
				vi.push_back(next);
				next = sasumono[next];
			}
			memset(visit, false, N);
		}

		cout << N - vi.size() << endl;
	}
	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}