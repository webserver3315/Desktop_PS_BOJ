#include<iostream>
#include<deque>
using namespace std;
class Point {
public:
	int x, y;
	Point() {
		x = y = -1;
	}
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
int n, k, l, a[101][101], dir = 4, ax, ay, cTime, ans;
char cDir;
deque<Point> snake;
char change[10001];
void changeDir() {
	switch (dir) {
	case 1:
		if (change[ans] == 'L') dir = 3;
		else dir = 4;
		break;
	case 2:
		if (change[ans] == 'L') dir = 4;
		else dir = 3;
		break;
	case 3:
		if (change[ans] == 'L') dir = 2;
		else dir = 1;
		break;
	case 4:
		if (change[ans] == 'L') dir = 1;
		else dir = 2;
		break;
	}
}
Point move(Point now) {
	int x = now.x, y = now.y;
	switch (dir) {
	case 1:
		--x;
		break;
	case 2:
		++x;
		break;
	case 3:
		--y;
		break;
	case 4:
		++y;
		break;
	}
	return Point(x, y);
}
void go() {
	while (true) {
		if (change[ans] == 'L' || change[ans] == 'D') changeDir();
		Point next = move(snake.front());
		int x = next.x;
		int y = next.y;  //다음방향

		if (x < 0 || x >= n || y < 0 || y >= n || a[x][y] == 2) break;

		snake.push_front(Point(x, y)); //머리 늘려주기
		if (a[x][y] == 0) {
			a[snake.back().x][snake.back().y] = 0; //꼬리를 없애주기
			snake.pop_back();
		}
		a[x][y] = 2;
		++ans;
	}
	cout << ans + 1 << endl;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> ax >> ay;
		a[ax - 1][ay - 1] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> cTime;
		cin >> cDir;
		change[cTime] = cDir;
	}
	a[0][0] = 2;
	snake.push_back(Point(0, 0));
	go();
	return 0;
}
