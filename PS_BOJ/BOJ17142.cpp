/*
연구소 3

이번엔 DFS로 Flood Fill 을 구현해보도록 하자.
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

/*시간은 0.25초 주어진다. 일단 유의하자.
바이러스 중 M개를 활성화시켜서, 모든 공백란을 바이러스로 메우려고 한다.
바이러스는 1초에 1칸 확산된다. - 재귀함수의 인자로 현재 초를 유지해야겠다.
활성바이러스는 빈칸은 물론, 비활성바이러스 칸으로도 확산될 수 있다. 즉, 벽을 제외한 모든 칸으로 확산가능하다.


시간을 재는 것이므로, DFS보다는 BFS로, 각 인자에 현재 초를 새겨서 flood fill 시키는 것이 적절해보인다. 아쉽게도 또 BFS인가. 무리해서라도 이번에 한번 DFS 써봐?
아, 아니다. 굳이 인자에 초를 새겨서 인자를 struct로 만들 필요 없이, 라보에서 0은 빈공간, 1은 벽, 2는 바이러스 설치가능장소, 3은 최초바이러스(0초), 4부터는 1초이후 생성된 바이러스 이렇게 유지하면 더 편하겠다. 그렇다고 위험한 char 쓰지는 말고, int로 쓰자.

문제는 2개로 쪼갤 수 있다.
1. 바이러스 총 V개가 있다고 할 때, VCM으로 최초로 활성화시킬 바이러스 M개를 선택하는 함수
2. 각 경우에 대해 퍼지는데 걸리는 최소시간을 반환하는 함수

1번을 해결하기 위해서는 조합을 사용해야 한다.
이를 위해 필요한 자료구조로는
최초바이러스좌표 유지용 벡터
활성화바이러스좌표 스택용 벡터

간과한게 있는데, 불가능할 경우도 존재한다. 해당 경우, -1을 반환해야 한다.
모든 칸을 점령하지 못했다는 것을 인지시키기 위해서는 공백칸의 갯수를 유지할 필요가 있다.
*/

int TotalLargestTimeforDFS=987654321;
int EachLargestTimeforDFS;
int OriginalLabo[51][51];
int Labo[51][51];
int N, M;//연구소는 정사각형, 설치할 바이러스 수
int dr[4] = { 1,-1,0,0 }; int dc[4] = { 0,0,-1,1 };
int MinKakusanTime = 987654321;
vector<pair<int, int>> Kanou_Virus;
vector<pair<int, int>> Setchi_Virus;
int Hajime_BlankKazu;

void PrintLabo() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << Labo[i][j] << ' ';
		}
		cout << endl;
	}
	return;
}

void CleanLabo() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			Labo[r][c] = OriginalLabo[r][c];
		}
	}
	return;
}

int VirusKaiho_BFS() {
	int final_time = 0;
	queue<pair<int, int>> KakusanChu;
	for (auto HajimeVirus : Setchi_Virus)
		KakusanChu.push(HajimeVirus);

	while (!KakusanChu.empty()) {
		int r = KakusanChu.front().first; int c = KakusanChu.front().second;
		KakusanChu.pop();
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i]; int cc = c + dc[i];
			if (rr >= N || rr < 0 || cc >= N || cc < 0 || Labo[rr][cc] == 1 || (Labo[rr][cc] != 0 && Labo[rr][cc] <= Labo[r][c])) {/*퍼질 예정장소가 장외라거나 벽이라면 걸러야 한다. 또한, 진작 퍼진 장소면 굳이 확산될 필요가 없다.*/
				continue;
			}
			if(Labo[rr][cc]<Labo[r][c])
			Labo[rr][cc] = Labo[r][c] + 1;
			if (final_time < Labo[rr][cc])
				final_time = Labo[rr][cc];
			KakusanChu.push({ rr,cc });
		}
	}
	
	return final_time;
}


/*모바이러스로 다시 되돌아가는 문제가 식별되었다.*/
int VirusKaiho_BFS2() {
	int final_time = 0;
	int SusunndaKazu = 0;
	queue<pair<int, int>> KakusanChu;
	for (auto HajimeVirus : Setchi_Virus)
		KakusanChu.push(HajimeVirus);

	while (!KakusanChu.empty()) {
		int r = KakusanChu.front().first; int c = KakusanChu.front().second;
		KakusanChu.pop();
		for (int i = 0; i < 4; i++) {
			int rr = r + dr[i]; int cc = c + dc[i];
			if (rr >= N || rr < 0 || cc >= N || cc < 0 || Labo[rr][cc] != 0) {/*퍼질 예정장소가 장외라거나 벽이라면 걸러야 한다. 또한, 진작 퍼진 장소면 굳이 확산될 필요가 없다.*/
				continue;
			}
			if (Labo[rr][cc] < Labo[r][c] + 1)
					SusunndaKazu++;
				Labo[rr][cc] = Labo[r][c] + 1;
			if (final_time < Labo[rr][cc])
				final_time = Labo[rr][cc];
			KakusanChu.push({ rr,cc });
		}
	}

	cout << "확산 종료" << endl;
	PrintLabo();
	cout << endl;
	if (Hajime_BlankKazu == SusunndaKazu)
		return final_time - 3;
	return -1;
}


/*빈칸과 바이러스 후보지는 다르게 취급된다. 꼭 바이러스 후보지에까지 바이러스를 퍼뜨릴 필요는 없다. 종료조건은 딱 "빈칸"만 다 채우면 된다.*/
void VirusKaiho_DFS(int r, int c, int corruptedBlank){
	int final_time = 0;
	if (corruptedBlank == Hajime_BlankKazu) {/*모든 빈칸을 다 메웠다면, 걸린 시간을 조사해야함*/
		if (EachLargestTimeforDFS < TotalLargestTimeforDFS)
			TotalLargestTimeforDFS = EachLargestTimeforDFS;
		EachLargestTimeforDFS = 0;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int rr = r + dr[i]; int cc = c + dc[i];
		if (rr >= N || rr < 0 || cc >= N || cc < 0) {/*장외라면*/
			continue;
		}
		if (Labo[rr][cc] > Labo[r][c] + 1 || Labo[rr][cc] == 2) {/*덮어쓸 가치가 있거나, 바이러스 예비자리였다면 전진*/
			if (Labo[rr][cc] == 0) {
				Labo[rr][cc] = Labo[r][c] + 1;
				if (Labo[rr][cc] > EachLargestTimeforDFS)
					EachLargestTimeforDFS = Labo[rr][cc];
				VirusKaiho_DFS(rr, cc, corruptedBlank + 1);
				Labo[rr][cc] = OriginalLabo[rr][cc];
			}
			else {
				Labo[rr][cc] = Labo[r][c] + 1;
				if (Labo[rr][cc] > EachLargestTimeforDFS)
					EachLargestTimeforDFS = Labo[rr][cc];
				VirusKaiho_DFS(rr, cc, corruptedBlank);
				Labo[rr][cc] = OriginalLabo[rr][cc];
			}
		}
	}
	return;
}

void SelectVirus(int depth) {
	if (depth == M) {
		cout << "M개의 바이러스 설치완료" << endl;
		VirusKaiho_DFS();
		PrintLabo();
		cout << endl;
		if (TestcaseFinalTime < MinKakusanTime) {
			cout << "최소확산시간 업데이트: " << MinKakusanTime << " 에서 " << TestcaseFinalTime << endl;
			MinKakusanTime = TestcaseFinalTime;
		}
		cout << "라보 초기화" << endl;
		CleanLabo();
		PrintLabo();
		cout << endl;
		return;
	}
	for (int idx = depth; idx < Kanou_Virus.size(); idx++) {
		pair<int, int> Ima_Virus = Kanou_Virus[idx];
		int r = Ima_Virus.first; int c = Ima_Virus.second;
		Labo[r][c] = 3;/*활성화된 바이러스는 2에서 3으로 표식변경.*/
		Setchi_Virus.push_back(Ima_Virus);

		cout << r << " , " << c << " 위치에 " << idx << " 번째 바이러스 설치" << endl;
		PrintLabo();
		cout << endl;

		SelectVirus(depth + 1);
		Labo[r][c] = 2;

		cout << r << " , " << c << " 위치에 " << idx << " 번째 바이러스 회수" << endl;
		PrintLabo();
		cout << endl;

		Setchi_Virus.pop_back();
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
			int tmp;
			cin >> tmp;
			Labo[r][c] = tmp; OriginalLabo[r][c] = tmp;
			if (Labo[r][c] == 2)
				Kanou_Virus.push_back({ r,c });
			else if (Labo[r][c] == 0)
				Hajime_BlankKazu++;
		}
	}

	SelectVirus(0);

	cout << TotalLargestTimeforDFS << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}