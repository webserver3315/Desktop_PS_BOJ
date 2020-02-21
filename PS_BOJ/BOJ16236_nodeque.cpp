/*
아기상어
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl '\n'
#define MAX 21
#define ff first
#define ss second
using namespace std;

typedef pair<int, int> pii;

/*
물고기 크기를 키로 하여 우선순위큐를 만들면 조금 더 빨라질지 모르겠으나, 일단 naive하게 풀어보자.
케이스 나눌 필요도 없이 이건 딱 정해진 규칙대로 움직이게끔만 하면 된다.
*/
int N;
int field[MAX][MAX];
int sec;
int ssize = 2;//상어크기
int eatcnt;
int sr, sc;//상어위치

void printfield() {
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cout << field[r][c] << ' ';
		}
		cout << endl;
	}
}


/*
간과한 조건이 있다.
만일 큰 물고기에 둘러싸인 작은 물고기의 경우, 먹을 수 없다.
*/


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			cin >> field[r][c];
			if (field[r][c] == 9) {
				sr = r; sc = c;
			}
		}
	}

	bool hasEaten = true;
	while (hasEaten) {//못먹을때까지
		printfield();
		cout << endl;

		int shortestDistance = MAX * 3;
		hasEaten = false;
		
		vector<pii> canEat;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (field[r][c] == 0 || ssize <= field[r][c])//물이거나, 크기가 더 큰 물고기면 거른다
					continue;
				pii pos = { r,c };
				int distance = abs(sr - r) + abs(sc - c);
				canEat.push_back(pos);//삼성A형에서 이렇게 해야되는거 맞나...? C++11도 지원안한다고 들어서 불안하다
				if (shortestDistance > distance)
					shortestDistance = distance;
				if (!hasEaten)
					hasEaten = true;
			}
		}
		if (!hasEaten)//먹을만한게 하나도 없었다면 거기서 끝
			break;
		
		sort(canEat.begin(), canEat.end());//벡터를 row 작은 것, 그 다음으로 column 작은 것 우선으로 정렬 성공시, 제일 먼저나온 거리 최소값이 곧 다음먹을 물고기다.
		int vctsize = canEat.size();//cpp17에서는 굳이 필요없지만 삼성환경때문에
		int toeatr, toeatc;//먹힐놈 좌표
		for (int i = 0; i < vctsize; i++) {
			int distance = abs(canEat[i].ff - sr) + abs(canEat[i].ss - sc);
			if (shortestDistance == distance) {//최초포착자만 제거
				toeatr = canEat[i].ff; toeatc = canEat[i].ss;
				break;
			}
		}

		cout << toeatr << ' ' << toeatc << " 를 먹습니다" << endl;
		field[sr][sc] = 0;
		field[toeatr][toeatc] = 9;
		sec += shortestDistance;//1칸에 1초이므로
		eatcnt++;
		if (eatcnt == ssize) {//많이먹으면 상어 레벨업
			eatcnt = 0; ssize++;
		}
	}

	std::cout << sec << endl;

	return 0;
}