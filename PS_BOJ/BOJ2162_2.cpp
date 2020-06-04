#include <bits/stdc++.h>
#define endl '\n'
#define MAX 3001
using namespace std;

/*
선분그룹
내 선분교차판별함수에 결함이 있는 것 같다.
https://hugssy.tistory.com/119 참조
*/

typedef struct myLine {
	int x1, y1;
	int x2, y2;
}line;

int N;
int par[MAX];
line vct[MAX];
int chd[MAX];

int find(int a) {//par배열은 원래 자기주소로 초기화되어야함에 유의
	if (par[a] == a) return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b) {//b에 a 병합 -> merge a2b
	par[find(a)] = find(b);
}

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {//u12랑 u13을 외적으로 반시계면 양수, 시계면 음수반환. 신발끈공식
	return (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1);
}

bool isCross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	if (ccw(x1, y1, x2, y2, x3, y3) * ccw(x1, y1, x2, y2, x4, y4) <= 0 &&
		ccw(x3, y3, x4, y4, x1, y1) * ccw(x3, y3, x4, y4, x2, y2) <= 0) {//통과시 일단 직선이라면 무조건 만난다는것
		if ((x1 > x3 && x1 > x4 && x2 > x3 && x2 > x4) ||//x 사거리가 동떨어져있지는 않은가
			(x3 > x1 && x3 > x2 && x4 > x1 && x4 > x2)) return false;
		else if ((y1 > y3 && y1 > y4 && y2 > y3 && y2 > y4) ||//y 사거리가 동떨어져있지는 않은가
			(y3 > y1 && y3 > y2 && y4 > y1 && y4 > y2)) return false;
		else return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++) par[i] = i;//par초기화
	for (int i = 1; i <= N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		vct[i].x1 = x1;	vct[i].y1 = y1;
		vct[i].x2 = x2;	vct[i].y2 = y2;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (isCross(vct[i].x1, vct[i].y1,
				vct[i].x2, vct[i].y2,
				vct[j].x1, vct[j].y1,
				vct[j].x2, vct[j].y2
			)) merge(i, j);
		}
	}

	for (int i = 1; i <= N; i++) {
		chd[find(i)]++;
	}
	int cnt = 0;//그룹수
	int maxnum = 0;
	for (int i = 1; i <= N; i++) {
		if (chd[i] > 0) cnt++;
		if (maxnum < chd[i]) maxnum = chd[i];
	}
	cout << cnt << endl << maxnum << endl;

	return 0;
}