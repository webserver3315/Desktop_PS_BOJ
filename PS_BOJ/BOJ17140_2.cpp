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
���� C�� �迭�� ���� �迭�� ���� �����ϴ� �ͺ��� �ƿ� �����Լ��� ���� �����ϴ°� ���� ������, �޸𸮴� �˳��ϹǷ�...
*/
int t;
int R, C;
int gR, gC;
int K;
int arr[MAX][MAX];//R�� �迭 -> ����迭
int rev_arr[MAX][MAX];//C�� �迭 -> ��� ���� �ٲ�. 1���� 1��, 2���� 2���� ��.
int num_cnt[MAX];//�ش� ���� �� �� ���Դ����� ���

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
		vector<pii> forSort;//pii�� ù����: ����Ƚ��, �ι�°����: �ش����
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
		vector<pii> forSort;//pii�� ù����: ����Ƚ��, �ι�°����: �ش����
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
			cout << "���� �̻��ϴ�" << endl;
		cout << sec << " �� ° " << endl;
		cout << "R, C : " << R << ' ' << C << endl;
		printArr();
		cout << endl;*/
		if (arr[gR - 1][gC - 1] == K) {
			return sec;
		}
		else if (R >= C) {
			R_operator();
			sec++;
			/*cout << "R ���� ����" << endl;
			cout << "R, C : " << R << ' ' << C << endl;
			printArr();
			cout << endl;*/
			
		}
		else {
			C_operator();
			sec++;
			/*cout << "C ���� ����" << endl;
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