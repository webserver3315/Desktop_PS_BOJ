/*
게리맨더링2
*/

#include <iostream>
#include <utility>
#include <deque>
#include <cstring>
//#include <cmath>//INT_MAX 때문
#include <climits>//INT_MAX는 cmath가 아니라 climits에 있다!!!!
#define endl '\n'
#define MAX (int)23
#define ff first
#define ss second
#define mp(x,y) make_pair(x,y)

typedef std::pair<int, int> pii;

using namespace std;

/*
일단 중간에 찍히는 5번선거구 영역이 키다. 제일 먼저 박고 들어가야한다.
각 선거구의 최소너비는 1칸이고 반드시 기울어진 직사각형꼴이며, 5번선거구는 중앙인 x,y 기준점과 좌상/우하단길이인 d1+1, 우상/좌하단 길이인 d2+1, 로 정의된다.

1. 5번 선거구 색칠하는 함수를 만들자
2. 5번선거구 결과를 읽어서, 1,2,3,4 선거구를 분류하는 함수를 만들자
3. 배정이 완전히 끝난 경우, 각 선거구의 인구수를 각각 구하는 함수를 만들자
4. 3번함수에서 최댓값과 최솟값을 빼자.
5. 5번 선거구를 만들 수 있는 모든 경우의 수에 대해 1~4를 반복하며, 최소 최대격차값을 업데이트하자

유사 마름모의 상하좌우 꼭짓점만 모두 영역내라면, 마름모가 영역내라는 것이 보장된다.

어차피 점대칭이 성립하니까, x,y는 1,1~n,n 도는게 아니라 1,1~n/2+1,n/2+1까지 도는걸로 하는게 나을 듯 하다. 연산량 1/4배 된다.
*/

int N;
int r5, c5;
//int d1, d2;
int population[MAX][MAX];//인구든 선거구든 r,c는 1부터 시작하도록 하자
int regiment[MAX][MAX];//선거구 생각이 안나서 걍 연대로 퉁침
int populationOfRegiment[6];//각 선거구별 인구수 유지
int dr[4] = { 1, -1,0,0 };
int dc[4] = { 0,0,-1,1 };
int minMaxDiff = INT_MAX;

bool IsInBoundary(int x, int y, int d1, int d2) {//이렇게 돌리면 과연 5번선거구가 영역안에 쏙 들어가는가에 대한 답
	int ur, uc, rr, rc, dr, dc, lr, lc;
	ur = x; uc = y;
	rr = x + d2; rc = y + d2;
	lr = x + d1; lc = y - d1;
	dr = x + d1 + d2; dc = y + d2 - d1;
	if (ur > N || rr > N || lr > N || dr > N
		|| uc > N || rc > N || lc > N || dc > N
		|| ur < 1 || rr < 1 || lr < 1 || dr < 1
		|| uc < 1 || rc < 1 || lc < 1 || dc < 1)
		return false;
	return true;
}

void printRegiment() {
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cout << regiment[r][c] << ' ';
		}
		cout << endl;
	}
}

void assignRegiment(int x, int y, int d1, int d2) {//x,y는 5번선거구 최북단.
	//memset(regiment, 0, (N + 1) * (N + 1));//되나?
	//if (IsInBoundary(x, y, d1, d2) == false)//범위초과 예상되면 계산낭비하지마라
	//	return;

	for (int d = 0; d <= d1; d++) {
		regiment[x + d][y - d] = 5;
	}
	for (int d = 0; d <= d2; d++) {
		regiment[x + d][y + d] = 5;
	}
	for (int d = 0; d <= d2; d++) {
		regiment[x + d1 + d][y - d1 + d] = 5;
	}
	for (int d = 0; d <= d1; d++) {
		regiment[x + d2 + d][y + d2 - d] = 5;
	}

	/*속을 5로 색칠*/
	//int ur = x; int dr = x + d1 + d2;/*5번선거구의 최북단과 최남단*/
	bool spotted = false;
	for (int r = x + 1; r < x + d1 + d2; r++) {
		spotted = false;
		for (int c = 1; c <= N; c++) {
			if (regiment[r][c] == 5) {
				if (spotted)
					break;
				else {
					spotted = true;
					continue;
				}
			}
			else {
				if (spotted)
					regiment[r][c] = 5;
				else
					continue;
			}
		}
	}

	/*5번아닌 나머지 부분 전부 1,2,3,4로 할당*/
	for (int r = 1; r < x + d1; r++) {//1
		for (int c = 1; c <= y; c++) {
			if (regiment[r][c] != 5) {
				regiment[r][c] = 1;
			}
		}
	}
	for (int r = 1; r <= x + d2; r++) {//2
		for (int c = y + 1; c <= N; c++) {//c=y+1부터인데 y라고했다...
			if (regiment[r][c] != 5) {
				regiment[r][c] = 2;
			}
		}
	}
	for (int r = x + d1; r <= N; r++) {//3
		for (int c = 1; c < y - d1 + d2; c++) {
			if (regiment[r][c] != 5) {
				regiment[r][c] = 3;
			}
		}
	}
	for (int r = x + d2 + 1; r <= N; r++) {//4
		for (int c = y - d1 + d2; c <= N; c++) {
			if (regiment[r][c] != 5) {
				regiment[r][c] = 4;
			}
		}
	}
}

bool regimentPopulationCount() {//false면 선거구 중 인구가 0인 선거구가 있다는 말
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			populationOfRegiment[regiment[r][c]] += population[r][c];
		}
	}
	for (int i = 1; i < 6; i++) {
		if (!populationOfRegiment[i])
			return false;
	}
	return true;
}

int GetMaxDiff() {
	int min = INT_MAX; int max = 0;
	for (int i = 1; i < 6; i++) {
		if (min > populationOfRegiment[i])
			min = populationOfRegiment[i];
		if (max < populationOfRegiment[i])
			max = populationOfRegiment[i];
	}
	return max - min;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++) {
			cin >> population[r][c];
		}
	}

	for (int r = 1; r <= N / 2 + 1; r++) {
		for (int c = 1; c <= N / 2 + 1; c++) {
			for (int d2 = 1; d2 <= N - c; d2++) {
				for (int d1 = 1; d1 < N - r - d2; d1++) {
					if (IsInBoundary(r, c, d1, d2) == false)//범위초과 예상되면 계산낭비하지마라
						continue;


					for (int r = 1; r <= N; r++) {//연대필드 0으로 초기화
						for (int c = 1; c <= N; c++) {
							regiment[r][c] = 0;
						}
					}
					//memset(populationOfRegiment, 0, 6);//연대별 인구수 0으로 초기화//왠지모르겠지만 이거 제대로 안돌아가네
					for (int i = 1; i < 6; i++)
						populationOfRegiment[i] = 0;

					/*if (r == 2 && c == 3 && d1 == 1 && d2 == 2) {
						int tmp = 1;
						cout << tmp << "여기서멈춰라" << endl;
					}*/

					assignRegiment(r, c, d1, d2);


					if (regimentPopulationCount() == false)
						continue;
					if (minMaxDiff > GetMaxDiff()) {
						cout << "최소차이 업데이트: " << minMaxDiff << " 에서 " << GetMaxDiff() << endl;
						minMaxDiff = GetMaxDiff();//변수선언 따로 안하고 이렇게 짜면 비효율적이려나?
					}
					cout << "r: " << r << " c: " << c << " d1: " << d1 << " d2: " << d2 << endl;
					printRegiment();
					cout << "1 : " << populationOfRegiment[1] << endl
						<< "2 : " << populationOfRegiment[2] << endl
						<< "3 : " << populationOfRegiment[3] << endl
						<< "4 : " << populationOfRegiment[4] << endl
						<< "5 : " << populationOfRegiment[5] << endl;
					cout << endl;
				}
			}
		}
	}
	cout << minMaxDiff << endl;

	return 0;
}
