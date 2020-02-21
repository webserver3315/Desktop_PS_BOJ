/*
뱀
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

/*보드 크기 N*N
맵 총 사과수는 K
뱀 초기위치는 최좌상단, 초기길이는 1, 초기머리는 우측방향

전진하는데, 사과가 있으면 머리가 목이 되고, 사과가 머리가 됨.
사과가 없으면 다음칸이 머리가 되고, 꼬리까지 전부 1칸 당김.(이거 맵이 작기만 하다면 리스트로 구현하면 ㄱㅊ할듯하긴한데)

초기에 사과의 위치 및 뱀의 이동경로오더를 준다. 이 게임이 언제 게임오버되는지 구하라.
게임오버의 조건은, 뱀이 벽 또는 자기자신의 몸과 부딪힐 때 끝난다.

첫 줄에 보드크기 N이 주어지고, 다음줄에는 사과갯수 K가 주어진다.
다음 K개의 문장은 사과의 위치이다.
사과위치 입력이 종료되면, 뱀의 방향변환횟수 L이 주어지고
다음 L개의 문장은 X초에 뱀을 "L" "D" 하라는 것이다. 각각 좌회전, 우회전을 의미한다.
X는 10000 이하의 정수이고, 방향전환정보는 X가 증가하는 순으로 주어진다.

문제를 쪼개보자. 일단 이 문제는 시뮬레이션형 문제이다.
1. 맵을 어떻게 유지할 것이며, 기호를 어떻게 할당할 것인가? 0을 빈 칸, 1을 벽, 2부터 올라가는 것으로 뱀의 꼬리부터 머리를 묘사할 것인가?
2. L과 D 연산을 어떻게 유지할 것인가?
3. 뱀 구현 및 맵에 적용을 어떻게 할 것이냐?
*/

/*뱀 구현은 list<pair<int,int>> 로 하자. 아니 아니다, vector<pair<int,int>>가 적절하다. 그 이유는, 늘어나기만 하며 중간삽입은 절대 일어나지 않음이 보장되기 때문이다.
괜히 list 썼다가 at 연산자 봉인되어서 엿먹는다.


*/

int Map[101][101];/*-1: 사과, 0: 빈공간, 1부터: 뱀꼬리부터 // 벽은 없다!!!*/
vector<pair<int, int>> Snake;//vector의 back이 대가리다.
int N, A, O;//보드변크기, 사과갯수, 명령수
queue<pair<int, string>> Order;
int State;//0: 동쪽, 1: 남쪽, 2:서쪽, 3:북쪽
int dr[4] = { 0,1,0,-1 }; int dc[4] = { 1,0,-1,0 };
int Time = 1;
bool GameOver;

void PrintMap() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << Map[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void Turn_Right() {
	State += 1;
	if (State == 4)
		State = 0;
	return;
}

void Turn_Left() {
	State -= 1;
	if (State == -1)
		State = 3;
	return;
}

void Forward() {

	if (Time == 5) {
		int k = 1;
		k++;
		//stop at here
	}

	pair<int, int> NextPosition = Snake.back();
	//int rr = NextPosition.first += dr[State]; int cc = NextPosition.second += dc[State];//rr, cc: 다음 전진할 칸의 row, column 번호//혹시 연산순서가 문제있나?
	NextPosition.first += dr[State]; NextPosition.second += dc[State];
	int rr = NextPosition.first; int cc = NextPosition.second;

	if (Map[rr][cc] > 0 || rr >= N || cc >= N || rr < 0 || cc < 0) {/*전진할 칸이 뱀에 닿았거나 장외라면 게임오버*/
		/*if (Map[rr][cc] > 0)
			cout << "본체와 충돌!!!" << endl;
		else
			cout << "벽과 충돌!!!" << endl;*/
		GameOver = true;
		return;
	}
	else if (Map[rr][cc] == -1) {/*다음에 전진할 곳이 사과칸이면*/
		Snake.push_back({ rr,cc });/*그곳이 새로운 머리가 된다.*/
		Map[rr][cc] = Snake.size();
	}
	else if (Map[rr][cc] == 0) {/*일반칸이라면 머리 전진 후 당겨야 한다.*/
		//for (vector<pair<int,int>>::iterator iter = Snake.begin(); iter < Snake.end() - 1; iter++) {//꼬리부터 ㄱㄱ. 머리는 따로 처리한다.
		//	Snake[iter].first = Snake[iter + 1].first; Snake[iter].second = Snake[iter + 1].second;
		//}
		Map[Snake.front().first][Snake.front().second] = 0;/*꼬리는 빈 칸이 될 것이므로*/

		for (int idx = 0; idx < Snake.size() - 1; idx++) {
			Snake[idx].first = Snake[idx + 1].first; Snake[idx].second = Snake[idx + 1].second;/*꼬리를 두 번째 꼬리로 옮기기*/
			Map[Snake[idx].first][Snake[idx].second] = idx + 1;/*두 번째 꼬리를 꼬리숫자로 Map 업데이트*/
		}
		Map[rr][cc] = Snake.size();/*전진할 칸은 새로운 머리가 될 것이므로*/
		Snake.back().first = rr; Snake.back().second = cc;
	}
	else {/*그 외의 경우란 있을 수 없으므로*/
		cout << "ERROR ERROR ERROR ERROR ERROR ERROR ERROR " << endl;
		GameOver = true;
		return;
	}

	Time++;
	return;
}

void Solve() {
	while (!GameOver) {/*사실 100초 안에 무조건 끝나게 되어있다고 추정되지만, 일단 GameOver 변수도 유지하도록 했다*/
		//cout << Time << " 초 시작" << endl;
		if (Order.empty() || Time != Order.front().first) {
			Forward();
		}
		else {
			string NowOrder = Order.front().second;
			if (NowOrder == "L") {
				Order.pop();
				//cout << Time << " 초 시작, 전진후 좌회전 " << endl;
				Forward();
				Turn_Left();
			}
			else if (NowOrder == "D") {
				Order.pop();
				//cout << Time << " 초 시작, 전진후 우회전 " << endl;
				Forward();
				Turn_Right();
			}
			else {/*그 외의 명령이란 있을 수 없다.*/
				cout << "ERROR ERROR ERROR ERROR ERROR ERROR ERROR " << endl;
				return;
			}
		}

		/*PrintMap();
		cout << endl;*/
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N;
	cin >> A;
	for (int i = 0; i < A; i++) {
		int r; int c;
		cin >> r >> c;/*사과 박아넣을 좌표 입력 및 반영*/
		Map[r - 1][c - 1] = -1;
	}
	cin >> O;
	for (int i = 0; i < O; i++) {
		int time; string order;
		cin >> time >> order;
		Order.push({ time,order });
	}

	Snake.push_back({ 0,0 });/*0,0은 디폴트로 뱀칸이다.*/
	Map[0][0] = 1;

	Solve();

	cout << Time << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}