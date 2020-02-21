#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
#define MAX (int)150
#define endl '\n'
using namespace std;


/*
원래 C용 배열을 위한 배열을 따로 선언하는 것보다 아예 정렬함수를 새로 선언하는게 낫긴 하지만, 메모리는 넉넉하므로...
*/
int t;
int R, C;
int gR, gC;
int K;
int arr[MAX][MAX];//R용 배열 -> 보통배열
int rev_arr[MAX][MAX];//C용 배열 -> 행과 열이 바뀜. 1행이 1열, 2행이 2열이 됨.
int num_cnt[MAX];//해당 수가 몇 번 나왔는지를 기록

void printArr() {
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cout << arr[r][c] << ' ';
		}
		cout << endl;
	}
	return;
}

void ResetNumCnt() {
	for (int i = 0; i < MAX; i++)
		num_cnt[i] = 0;
	return;
}

void R_operator() {
	int maxC = 0;
	for (int r = 0; r < R; r++) {
		vector<pii> forSort;//pii의 첫인자: 등장횟수, 두번째인자: 해당숫자
		ResetNumCnt();
		for (int c = 0; c < C; c++) {
			int num = arr[r][c];
			if (num == 0)
				continue;
			num_cnt[num]++;
			if (num_cnt[num] == 1) {
				forSort.push_back(mp(1, num));
			}
		}
		for (int i = 0; i < forSort.size(); i++) {
			forSort[i].ff = num_cnt[forSort[i].ss];
		}
		sort(forSort.begin(), forSort.end());
		for (int i = 0; i < forSort.size() && i < 50; i++) {
			arr[r][i * 2] = forSort[i].ss;
			arr[r][i * 2 + 1] = forSort[i].ff;
			if (i * 2 + 1 > maxC)
				maxC = i * 2 + 1;
		}
		int localC = (forSort.size() - 1) * 2 + 1;
		for (int i = localC + 1; i < MAX; i++) {
			arr[r][i] = 0;
		}
	}
	C = maxC + 1;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			rev_arr[c][r] = arr[r][c];
		}
	}
	return;
}

void C_operator() {
	int maxR = 0;
	for (int c = 0; c < C; c++) {
		vector<pii> forSort;//pii의 첫인자: 등장횟수, 두번째인자: 해당숫자
		ResetNumCnt();
		for (int r = 0; r < R; r++) {
			int num = arr[r][c];
			if (num == 0)
				continue;
			num_cnt[num]++;
			if (num_cnt[num] == 1) {
				forSort.push_back(mp(1, num));
			}
		}
		for (int i = 0; i < forSort.size(); i++) {
			forSort[i].ff = num_cnt[forSort[i].ss];
		}
		sort(forSort.begin(), forSort.end());
		for (int i = 0; i < forSort.size() && i < 50; i++) {
			arr[i * 2][c] = forSort[i].ss;
			arr[i * 2 + 1][c] = forSort[i].ff;
			if (i * 2 + 1 > maxR)
				maxR = i * 2 + 1;
		}
		int localR = (forSort.size() - 1) * 2 + 1;
		for (int i = localR + 1; i < MAX; i++) {
			arr[i][c] = 0;
		}
	}	
	R = maxR + 1;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			rev_arr[c][r] = arr[r][c];
		}
	}
	return;

}

int Solve() {
	int sec = 0;
	while (sec <= 100) {
		/*if (sec == 6)
			cout << "여기 이상하다" << endl;
		cout << sec << " 초 째 " << endl;
		cout << "R, C : " << R << ' ' << C << endl;
		printArr();
		cout << endl;*/
		if (arr[gR - 1][gC - 1] == K) {
			return sec;
		}
		else if (R >= C) {
			R_operator();
			sec++;
			/*cout << "R 연산 이후" << endl;
			cout << "R, C : " << R << ' ' << C << endl;
			printArr();
			cout << endl;*/
			
		}
		else {
			C_operator();
			sec++;
			/*cout << "C 연산 이후" << endl;
			cout << "R, C : " << R << ' ' << C << endl;
			printArr();
			cout << endl;*/
		}
	}
	return -1;
}


int main() {
	//cin >> t;
	t = 1;
	while (t--) {
		cin >> gR >> gC >> K;
		for (int r = 0; r < 3; r++) {
			for (int c = 0; c < 3; c++) {
				cin >> arr[r][c];
				rev_arr[c][r] = arr[r][c];
			}
		}
		R = 3; C = 3;
		int ans = Solve();
		cout << ans << endl;
	}
	return 0;
}