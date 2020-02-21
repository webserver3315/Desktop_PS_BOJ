/*
아기상어
*/

#include <iostream>
#include <deque>
#define endl '\n'
#define MAX 21
//#define ff first
//#define ss second
using namespace std;

//typedef pair<int, int> pii;

struct fish {
	int r; int c; int s;//size
};

/*
물고기 크기를 키로 하여 우선순위큐를 만들면 조금 더 빨라질지 모르겠으나, 일단 naive하게 풀어보자.
케이스 나눌 필요도 없이 이건 딱 정해진 규칙대로 움직이게끔만 하면 된다.
*/
int N;
int field[MAX][MAX];
int sec;
int ssize = 2;//상어크기
int eatcnt;
deque<fish> dqfish;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			if (field[r][c] != 0 && field[r][c] != 9) {
				fish Fish = { r,c,field[r][c] };
				dqfish.push_back(Fish);
			}
		}
	}

	bool hasEaten = true;
	while (!hasEaten) {//못먹을때까지
		int shortestDistance = MAX * 3;
		hasEaten = false;
		int numFish = dqfish.size();
		for (int i = 0; i < numFish; i++) {
			fish nowfish = dqfish.front();
			dqfish.pop_front;
			if (nowfish.s < ssize) {//작으면, 일단 먹을수있다

			}

		}


	}

	cout << sec << endl;

	return 0;
}