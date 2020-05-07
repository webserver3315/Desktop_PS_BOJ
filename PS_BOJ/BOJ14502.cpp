/*
연구소

P.S - 플러드필 알고리즘 BFS말고 DFS로도 구현하는 법 숙지해놓기.
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

/*연구소 크기는 N*M
바이러스는 상하좌우 인접한 빈칸으로 모두 퍼져나갈 수 있다 - Flood Fill
벽을 세울 수 있으며, 벽은 딱 더도말고 덜도말고 3개만 세워야 한다. 빈칸은 최소 3개 이상 주어진다.
0은 공간, 1은 벽, 2는 바이러스를 뜻한다.
바이러스를 차단해서 얻을 수 있는 최대의 안전영역을 구하라.

해당 문제는 2가지로 나눌 수 있다.
빈칸 수를 B라고 했을 때, 벽을 세울 수 있는 경우의 수는 BC3이다.

1. 벽을 세우는 경우를 제조하는 재귀함수
2. 상황이 주어졌을 경우, 바이러스를 퍼뜨려 해당 Case에서의 안전영역을 구하는 함수

바이러스의 위치는 vector로 유지하는게 나을까.
또, 벽과 공백은 따로 유지안해도 될까.
아니다, 공백을 pair의 vector로 유지해야 BC3을 구하기 쉬울것이다.

처음상태유지용 공백위치 벡터
처음상태유지용 바이러스 벡터
스택메모리용 벽위치 벡터

일단 이렇게 필요하다.
*/

int R, C;//R, C
int Labo[9][9];//0:공간, 1:벽, 2:원래 바이러스, 3: 퍼진 바이러스
int MaxSafe;
int dr[4] = { 1,-1,0,0 }; int dc[4] = { 0,0,-1,1 };
vector<pair<int, int>> Hatsu_Blank;
vector<pair<int, int>> Hatsu_Virus;
vector<pair<int, int>> Stack_Wall;

void PrintLabo() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << Labo[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void CleanLabo() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (Labo[r][c] == 3)
				Labo[r][c] = 0;
		}
	}
	return;
}

int VirusKaiho() {/*해당 Case에서의 안전구역 칸 수 출력*/
	queue<pair<int, int>> Susume_Virus;/*BFS를 통한 플러드필을 구현하기 위한 큐이다.*/
	for (auto EachVirus : Hatsu_Virus) {
		Susume_Virus.push(EachVirus);
	}
	int SusunndaKazu = 0;
	while (!Susume_Virus.empty()) {
		pair<int, int> ImaVirus = Susume_Virus.front();
		Susume_Virus.pop();
		int r = ImaVirus.first; int c = ImaVirus.second;
		//if (Labo[r][c] == 0 || 1)
		//	continue;
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i]; int cc = c + dc[i];
			if (rr >= R || rr < 0 || cc >= C || cc < 0 || Labo[rr][cc] != 0)/*경계초과하거나 공백칸이 아니라면*/
				continue;
			Labo[rr][cc] = 3;
			SusunndaKazu++;
			Susume_Virus.push({ rr,cc });
		}
	}
	return Hatsu_Blank.size() - SusunndaKazu - 3;
}

void MakeLaboGreatAgain(int depth, int start) {//벽을 3군데에 만드는 함수이다.
	if (depth == 3) {
		int ImaSafe = VirusKaiho();
		//cout << "바이러스 모두 퍼뜨림. 그래서 이렇게 됨." << endl;
		//PrintLabo();
		if (ImaSafe > MaxSafe) {
			//cout << "최대 안전값 업데이트: " << MaxSafe << " 에서 " << ImaSafe << endl;
			MaxSafe = ImaSafe;
		}
		//cout << endl;
		CleanLabo();
		return;
	}
	for (int position = start; position < Hatsu_Blank.size(); position++) {
		int row = Hatsu_Blank[position].first; int column = Hatsu_Blank[position].second;
		Stack_Wall.push_back({ row,column });
		Labo[row][column] = 1;
		//cout << row << " 랑 " << column << " 에 벽을 세웠음" << endl;
		//PrintLabo();
		//cout << endl;
		MakeLaboGreatAgain(depth + 1, position + 1);
		Labo[row][column] = 0;
		Stack_Wall.pop_back();
		//cout << row << " 랑 " << column << " 에 벽을 허물었음" << endl;
		//PrintLabo();
		//cout << endl;
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> Labo[r][c];
			if (Labo[r][c] == 0) {
				Hatsu_Blank.push_back({ r,c });
			}
			else if (Labo[r][c] == 2) {
				Hatsu_Virus.push_back({ r,c });
			}
		}
	}

	MakeLaboGreatAgain(0, 0);

	cout << MaxSafe << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}