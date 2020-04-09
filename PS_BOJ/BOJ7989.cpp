#include <bits/stdc++.h>
using namespace std;

/*
The Bridge
*/

int n;
deque<int> li;
deque<int> ri;

/*
단일 횃불 2인용 다리 문제
건너기 전, 가장 빠른 2명과 가장 느린 2명 중 어느 쪽을 보내는게 이득인지를 그때그때 그리디하게 판별
*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		li.push_back(tmp);
	}
	int time = 0;
	sort(li.begin(), li.end());
	while (li.size() > 3) {
		int a, b, c, d;
		a = li[0]; b = li[1]; c = li[li.size() - 2]; d = li[li.size() - 1];
		if (2 * b > a + c) {//a가 캐리하는게 나을 경우
			time += 2 * a + b + c + d; 
		}
		else {
			time += a + 3 * b + d;
		}
		li.pop_back(); li.pop_back(); li.pop_front(); li.pop_front();
	}
	if (li.size() == 3) {
		for (auto i : li)
			time += i;
	}
	else if (li.size() == 2) {
		time += li[1];
	}
	else if (li.size() == 1) {
		time += li[0];
	}
	cout << time << endl;
	return 0;
}