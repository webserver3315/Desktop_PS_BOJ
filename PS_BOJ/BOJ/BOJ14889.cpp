/*
스타트와 링크
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


/*축구하는데 N명 모였고 당연히 짝수임.
i번 사람과 j번 사람이 같은 팀에 속했을 때 팀에 더해지는 능력치는 테이블로 주어진다.
밸런스가 최대한 맞을 경우, 팀간의 능력치 차의 최소값을 출력하라.
선수의 명수는 4명~20명까지 가능하다.

어떻게 푸느냐...
일단 당장 떠오르는건
10*9/2=45, 45*9는 대충 500. 가능한 총원당 가능한 모든 팀의 종류는 아무리 넉넉하게 잡아도 500가지가 안됨.
500가지 전부 Brute하게 1번팀 전체 sum - 2번팀sum을 빼는 연산을 하고, 그 중 min값을 출력하면 되는 것이다.
Brute하게 하는 것이 유효하다.

이 문제는 그렇게 어렵지는 않다. 두 가지로 쪼갤 수 있기 때문이다. 3가지 이상이면 조금 귀찮아지긴 하지만
우선, 총 인원수는 주어지므로
1. nC2로 짤 수 있는 팀 분할의 모든 종류
2. 해당 팀 경우 당 능력치 차이를 구하는 함수

nC2로 팀을 분할하는 것은 뭘로 구현할까...? 일단 Combination과 동일하므로 start 변수를 사용한 재귀로 구현가능하다.
또한, 팀은 두 팀밖에 없으므로 뽑힌 팀 VS 안뽑힌 팀 식으로 구분 또한 가능하다. start변수를 이용한 뽑힌 팀 유지를 통해 중복은 피할 수 있다. 즉, 배열은 1개만 필요하다.
팀에 들어있는 인원의 수를 유지하는 방식으로 vector에 해당 인원의 이름을 넣기보다는, visited 배열 마냥 1팀에 속한 자들은 1을, 2팀에 속한자들은 2를 써넣는걸로 하자.
그게 훨씬 빠른 find 속도를 가져온다. set쓰는것보다도 빠를 것이다. 애초에 20명밖에 없기에 이런 기수검색이 가능하다.
*/

int N;
int MinDifference = 987654321;
int NoryokuTable[22][22];
int TeamStatus[22];/*0:미정, 1:1팀, 2:2팀*/

/*int GetDifference() {
	int Team1_Sum = 0; int Team2_Sum = 0;
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] != 1)
			continue;
		for (int j = i + 1; j <= N; j++) {
			if (TeamStatus[j] != 1)
				continue;
			cout << "1팀 합: " << i << " 와 " << j << " 의 시너지인 " << NoryokuTable[i][j] << ' ' << NoryokuTable[j][i] << " 을 더해서 " << Team1_Sum << "은 " << NoryokuTable[i][j] + NoryokuTable[j][i] << " 을 더했다." << endl;
			Team1_Sum += NoryokuTable[i][j] + NoryokuTable[j][i];
			cout << "2팀 합: " << N + 1 - i << " 와 " << N + 1 - j << " 의 시너지인 " << NoryokuTable[N + 1 - i][N + 1 - j] << ' ' << NoryokuTable[N + 1 - j][N + 1 - i] << " 을 더해서 " << Team2_Sum << "은 " << NoryokuTable[N + 1 - i][N + 1 - j] + NoryokuTable[N + 1 - j][N + 1 - i] << " 을 더했다." << endl;
			Team2_Sum += NoryokuTable[N + 1 - i][N + 1 - j] + NoryokuTable[N + 1 - j][N + 1 - i];
		}
	}
	int difference = abs(Team1_Sum - Team2_Sum);
	return difference;
}*/


int GetDifference() {
	int Team1_Sum = 0; int Team2_Sum = 0;
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] != 1)
			continue;
		for (int j = i + 1; j <= N; j++) {
			if (TeamStatus[j] != 1)
				continue;
			//cout << "1팀 합: " << i << " 와 " << j << " 의 시너지인 " << NoryokuTable[i][j] << ' ' << NoryokuTable[j][i] << " 을 더해서 " << Team1_Sum << "은 " << NoryokuTable[i][j] + NoryokuTable[j][i] << " 을 더했다." << endl;
			Team1_Sum += NoryokuTable[i][j] + NoryokuTable[j][i];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] != 2)
			continue;
		for (int j = i + 1; j <= N; j++) {
			if (TeamStatus[j] != 2)
				continue;
			//cout << "2팀 합: " << i << " 와 " << j << " 의 시너지인 " << NoryokuTable[i][j] << ' ' << NoryokuTable[j][i] << " 을 더해서 " << Team2_Sum << "은 " << NoryokuTable[i][j] + NoryokuTable[j][i] << " 을 더했다." << endl;
			Team2_Sum += NoryokuTable[i][j] + NoryokuTable[j][i];
		}
	}
	int difference = abs(Team1_Sum - Team2_Sum);
	return difference;
}

void Team1_Print() {
	cout << "1팀: " << endl;
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] == 1)
			cout << i << ' ';
	}
	cout << endl;

	cout << "2팀: " << endl;
	for (int i = 1; i <= N; i++) {
		if (TeamStatus[i] == 2)
			cout << i << ' ';
	}
	cout << endl;
	return;
}

void Team_Sentaku(int start, int depth) {
	if (depth == N / 2) {
		//Team1_Print();
		int NewMin = GetDifference();
		if (MinDifference > NewMin) {
			//cout << "최소합값 업데이트 : " << MinDifference << " 에서 " << NewMin << " 로" << endl << endl;
			MinDifference = NewMin;
		}
		return;
	}
	for (int i = start; i <= N; i++) {
		TeamStatus[i] = 1;
		//cout << i << "를 1번 팀에 넣었습니다" << endl;
		Team_Sentaku(i + 1, depth + 1);
		//cout << i << "를 2번 팀에 되돌렸습니다" << endl;
		TeamStatus[i] = 2;
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
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> NoryokuTable[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {/*Unselected라면 2팀취급하도록 초기화*/
		TeamStatus[i] = 2;
	}


	Team_Sentaku(1, 0);/*아, ㅆㅂ 이거 0,0으로 잡았다가 디버깅하는데 20분 잡아먹었네;*/
	cout << MinDifference << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}