/*
다리만들기2
*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <array>
#include <cmath>
#include <cstdio>
#include <ctime>
#define endl '\n'
using namespace std;

int DFS_cnt;
int R, C, NumberOfCountry = 1;
int map[10][10];/*r,c 순이며 2차원벡터로 풀려다가 일단 안정적으로 고전적 배열로 선언했다.*/
int KyoriTable[7][7];/*나라간 최단거리를 유지하는 테이블이다.*/
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,-1,1 };
int MinTotalDistance = INT_MAX;
bool visited[10];
bool TraverseComplete;/*순회가능할경우*/
vector<int> LengthVct;
struct Bridge {
	int start; int end; int nagasa;
};
/*다리는 반드시 일직선이어야만 하고, 길이는 반드시 2 이상이어야만 한다.
섬 갑과 섬 을을 연결하는 다리가 섬 병과 접할 경우, 그 다리는 섬 병을 잇는 다리로 취급되지 못한다.
다리의 교차는 허용되며, 그 경우 다리의 길이는 중복되어 계산된다.
가로 세로의 길이는 10 이하로 보장되며 섬의 개수는 2개 이상 6개 이하임이 보장된다.
모든 섬의 연결이 불가능하다면 -1을 출력하면 된다.

나라가 N개라면, 다리의 수는 N-1개 이상이어야만 한다. 그리고, N-1개의 다리면 어떤 수의 나라든 연결ㄱㄴ하다.
그런데, N-1개의 다리를 쌓는 것 보다 N개 이상의 다리를 쓰는 편이 더 효율적인 경우가 존재하긴 하는가?

내 방법
1. 입력된 섬을 일단 1, 2, 3, ... , 6까지 번호로 매긴다.
2. 각 섬 간 가능한 최단거리를 구한다. 만약 다리를 놓는게 불가능하다면, -1을 채워넣는다.
>>>어차피 놓을 수 있는 다리의 수는 아무리 많아봤자 n+m종류다. 그러니까 쭉쭉 놓아서 최단거리만 추출해서 넣자. 굳이 DFS나 BFS 쓸 필요는 여기선 없다.
3. 완성된 거리2차원배열을 이용해서, 최단거리외판원문제를 해결한다. 그 방식은 BFS이다. 어차피 n개 나라 다 돌아야하니 깊이가 n으로 정해진 BFS다.
*/

void PrintMap() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << map[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void PrintKyoriMap() {
	for (int r = 1; r <= NumberOfCountry; r++) {
		for (int c = 1; c <= NumberOfCountry; c++) {
			cout << KyoriTable[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

int LengthVctSum() {
	int sum = 0;
	for (int tmp : LengthVct) {
		sum += tmp;
	}
	return sum;
}

void PrintVct() {
	for (int tmp : LengthVct)
		cout << tmp << ' ';
	cout << endl;
}

bool IsTraverseCompleted() {
	for (int i = 1; i <= NumberOfCountry; i++) {
		if (visited[i] == false)
			return false;
	}
	return true;
}

void DFS(int depth, int Sum) {
	if (depth == NumberOfCountry) {
		if (!TraverseComplete)
			TraverseComplete = true;
		if (Sum < MinTotalDistance)
			MinTotalDistance = Sum;
		return;
	}
	for (int HajimeKuni = 1; HajimeKuni <= NumberOfCountry; HajimeKuni++) {
		if (!visited[HajimeKuni])
			continue;
		for (int OwariKuni = 1; OwariKuni <= NumberOfCountry; OwariKuni++) {
			if (visited[OwariKuni] || KyoriTable[HajimeKuni][OwariKuni] == 0)/*이미 방문한 나라거나 자기자신이면 거른다*/
				continue;
			visited[OwariKuni] = true;
			cout << HajimeKuni << " 와 " << OwariKuni << "를 연결하는 다리를 지었습니다." << endl;
			DFS(depth + 1, Sum + KyoriTable[HajimeKuni][OwariKuni]);
			cout << HajimeKuni << " 와 " << OwariKuni << "를 연결하는 다리를 부쉈습니다." << endl;
			visited[OwariKuni] = false;
		}
	}
	return;
}

int main() {
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> R >> C;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			int tmp;
			cin >> tmp;
			if (tmp == 1)
				tmp = -1;
			map[r][c] = tmp;
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] == -1) {/*임자없는 육지라면*/
				map[r][c] = NumberOfCountry;
				queue< pair <int, int> > ColonyQueue;
				ColonyQueue.push(make_pair(r, c));
				while (!ColonyQueue.empty()) {
					pair <int, int> Ima = ColonyQueue.front();
					ColonyQueue.pop();
					int rr = Ima.first; int cc = Ima.second;
					for (int i = 0; i < 4; i++) {/*상하좌우에 대하여*/
						if (rr + dr[i] >= 0 && rr + dr[i] < R && cc + dc[i] >= 0 && cc + dc[i] < C && map[rr + dr[i]][cc + dc[i]] == -1) {/*장외구역이 아니면서 국적없는 땅이라면*/
							map[rr + dr[i]][cc + dc[i]] = NumberOfCountry;
							ColonyQueue.push(make_pair(rr + dr[i], cc + dc[i]));
						}
					}
				}
				NumberOfCountry++;
			}
		}
	}
	NumberOfCountry--;
	PrintMap();
	cout << endl;

	for (int r = 0; r < R; r++) {/*거리테이블 초기화*/
		for (int c = 0; c < C; c++) {
			KyoriTable[r][c] = 10;
		}
	}


	for (int r = 0; r < R; r++) {/*좌에서 우로만 탐색*/
		int start = -1; int end = -1; int distance = 0;
		for (int c = 0; c < C; c++) {
			if (map[r][c] != 0) {/*육지라면*/
				if (start == -1) {/*첫 나라의 경우*/
					start = map[r][c];/*국명저장*/
					distance = 0;
				}
				else {/*끝지점이자 재시작점이라면*/
					end = map[r][c];/*국명저장*/
					if (distance != 1 && KyoriTable[start][end] > distance) {
						KyoriTable[start][end] = distance;
						KyoriTable[end][start] = distance;
					}
					start = map[r][c];/*새로운 시작국으로 설정*/
					distance = 0;
				}
			}
			else {
				distance++;
			}
		}
	}

	for (int c = C - 1; c >= 0; c--) {/*상에서 하로만 탐색*/
		int start = -1; int end = -1; int distance = 0;
		for (int r = 0; r < R; r++) {
			if (map[r][c] != 0) {/*육지라면*/
				if (start == -1) {/*첫 나라의 경우*/
					start = map[r][c];/*국명저장*/
					distance = 0;
				}
				else {/*끝지점이자 재시작점이라면*/
					end = map[r][c];/*국명저장*/
					if (distance != 1 && KyoriTable[start][end] > distance) {
						KyoriTable[start][end] = distance;
						KyoriTable[end][start] = distance;
					}
					start = map[r][c];/*새로운 시작국으로 설정*/
					distance = 0;
				}
			}
			else {
				distance++;
			}
		}
	}

	PrintKyoriMap();

	/*visit된 나라를 유지한다.
	true된 나라들에 한해서 false나라들로 출발가능하다. 그리고 방문당한 false나라는 true가 되며 그 거리는 sum에 더해진다.
	그걸 DFS한다. BFS했다간 큐 크기가 장담이 안될 것 같다.
	다리수C나라수-1 의 조합이다.*/
	visited[1] = true;
	DFS(0,0);
	if (TraverseComplete)
		cout << MinTotalDistance << endl;
	else
		cout << -1 << endl;

	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << duration << " sec" << endl;
	return 0;
}