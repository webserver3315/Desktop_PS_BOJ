/*
치킨 배달
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

/*치킨집을 M개만 남긴다고 할 때, 폐쇄이후 최소의 치킨거리 총합을 구해서 출력하라.
치킨집은 최대 13개, 또한 cartesian coordinate 로 주어지므로 거리는 단지 x, y 각각의 값의 차의 절댓값을 더하면 된다.
치킨집이 K개라고 할 때, M개를 구하는 가짓수는 KCM이다.
각 경우에 대해 naive하게 최소치킨거리를 구해주는 함수에 각각 넣어주고 돌려버리면 된다.

그렇다면 이 문제는 일단 2가지로 분해된다.
1. 1번치킨집부터 K번 치킨집까지 M개를 조합하는 방법의 수
2. 각 방법에 대해 최소치킨거리를 구해주는 함수의 제작: 각각의 집에 대해 모든 치킨집에 대한 거리를 탐색하도록 한다. 각 케이스마다 집*치킨의 연산이 소요된다.(사실 비교횟수만 따지면 N**2지만)
*/

int N, M;
int Village[52][52];
int Murabito_Kazu, Chicken_Kazu;
int FinalMinChickenKazu = 987654321;
vector<pair<int, int>> Selected_Chicken;
vector<pair<int, int>> Whole_Chicken;
vector<pair<int, int>> Whole_Murabito;

int Get_ChickenDistance() {
	int TotalChickenDistance = 0;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {/*이런 형식으로 이중for문 돌리는 것 대신 RBfL 쓰는것도 ㄱㅊ할 듯 하다. 뭐 시험환경에선 안될가능성 크지만*/
			if (Village[r][c] == 1) {/*가정집이 발견되면*/
				int MinChickenDistance = 987654320;
				for (auto Chicken : Selected_Chicken) {/*그 가정집으로부터 현재 남아있는 모든 치킨집에 대해 거리를 구한다.*/
					int ImaChickenDistance = abs(r - Chicken.first) + abs(c - Chicken.second);
					if (MinChickenDistance > ImaChickenDistance)
						MinChickenDistance = ImaChickenDistance;
				}
				TotalChickenDistance += MinChickenDistance;
			}
		}
	}
	return TotalChickenDistance;
}

void Combination_Chicken_Testcase(int start, int depth) {
	if (depth == M) {
		int ImaChickenDistance = Get_ChickenDistance();
		if (ImaChickenDistance < FinalMinChickenKazu) {
			FinalMinChickenKazu = ImaChickenDistance;
		}
		return;
	}
	for (int i = start; i < Chicken_Kazu; i++) {
		Selected_Chicken.push_back(make_pair(Whole_Chicken[i].first, Whole_Chicken[i].second));
		Combination_Chicken_Testcase(i + 1, depth + 1);
		Selected_Chicken.pop_back();
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> N >> M;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> Village[r][c];
			if (Village[r][c] == 2) {
				Whole_Chicken.push_back(make_pair(r, c));
				Chicken_Kazu++;
			}
			else if (Village[r][c] == 1) {
				Whole_Murabito.push_back(make_pair(r, c));
				Murabito_Kazu++;
			}
		}
	}

	Combination_Chicken_Testcase(0, 0);

	cout << FinalMinChickenKazu << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}