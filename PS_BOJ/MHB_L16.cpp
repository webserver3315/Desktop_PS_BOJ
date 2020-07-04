#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

//Convex hull(볼록 껍질) 연습

struct pos {
	long long x, y;
};

pos v[100010];

bool comp_y(pos a, pos b) {

	if (a.y != b.y)	return a.y < b.y;
	else return a.x < b.x;
}

long long ccw(pos a, pos b, pos c) { //ccw
	return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}


bool comp_c(pos a, pos b) { //반시계 정렬

	long long cc = ccw(v[0], a, b);
	if (cc != 0) return cc > 0; // 각도 작은 순
	else return (a.x + a.y) < (b.x + b.y); //일직선 있을경우 좌표가 작은
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	stack<pos> s;
	int N; cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> v[i].x >> v[i].y;
	}

	sort(v, v + N, comp_y);
	sort(v + 1, v + N, comp_c);

	s.push(v[0]);
	s.push(v[1]);
	pos first, second;


	for (int i = 2; i < N; i++) {
		while (s.size() >= 2) {
			second = s.top();
			s.pop();
			first = s.top();
			if (ccw(first, second, v[i]) > 0) { //좌회전
				s.push(second);
				break;
			}

		}
		s.push(v[i]);
	}

	cout << s.size();
	return 0;
}