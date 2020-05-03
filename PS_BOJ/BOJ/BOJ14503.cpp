#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <utility>
#define MAX (int)55
#define endl '\n'
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second

//후진==(방위+2)%4
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

using namespace std;

int t;
int R, C;
int rr, cc;
int mode;
int field[MAX][MAX];
bool cleaned[MAX][MAX];
int cnt;
int dr[4] = { -1,0,1,0 };
int dc[4] = { 0,1,0,-1 };

int Soji() {
	while (1) {
		if (!cleaned[rr][cc]) {//1번 행위
			cleaned[rr][cc] = true;
			cnt++;
		}
		for (int i = 0; i < 5; i++) {//2번 행위
			if (i == 4) {//상하좌우 모두 노답일 경우
				int rrr = rr + dr[(mode + 2) % 4]; int ccc = cc + dc[(mode + 2) % 4];//rrr,ccc==후진시 가게 되는 칸
				if (field[rrr][ccc] == 1)//뒤가 벽이면 여기까지다.
					return cnt;
				else {//사면클린인데 뒤가 벽은 아닌 경우, 후진하고 2번부터 계속한다.
					rr = rrr; cc = ccc;
					break;
				}
			}
			int rrr = rr + dr[i]; int ccc = cc + dc[i];
			if (!cleaned[rrr][ccc] && field[rrr][ccc] == 0)//벽 아니고 청소 안된 칸 있으면 예스답.
				break;
		}
		//여기까지 왔다는 것은, 네 방향 중 청소 안된 벽 아닌 칸이 있다는 것.
		int rrr, ccc;
		for (int i = 0; i < 4; i++) {
			int newMode = abs((mode - i) % 4);//북>서>남>동...순으로 가야한다.
			rrr = rr + dr[newMode]; ccc = cc + dc[newMode];
			if (!cleaned[rrr][ccc] && field[rrr][ccc] == 0)
				break;
		}
		rr = rrr; cc = ccc;
		continue;
	}
	return -1;
}


int main() {
	cin >> t;
	while (t--) {
		int cnt = 0;
		cin >> R >> C;
		cin >> rr >> cc >> mode;
		for (int i = 0; i < MAX; i++) {
			memset(field[i], 0, MAX);
			memset(cleaned[i], false, MAX);
		}
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				cin >> field[r][c];
			}
		}
		Soji();
		cout << cnt << endl;
	}
	return 0;
}