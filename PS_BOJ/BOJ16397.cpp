#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, t, g;
bool visit[100000];
deque<int> dq;

int bfs() {
	dq.push_back(n); visit[n] = true;
	for (int tt = 0; tt <= t; tt++) {
		int cir = dq.size();
		for (int i = 0; i < cir; i++) {
			int cur = dq.front(); dq.pop_front();
			if (cur == g) {
				cout << tt << endl;
				return tt;
			}

			if (cur < 99999) {
				//cout << tt << " 번째 버튼 : " << cur + 1 << "푸시" << endl;
				if (!visit[cur + 1]) dq.push_back(cur + 1);
				visit[cur + 1] = true;
			}
			if (cur * 2 < 99999) {
				int b = cur * 2; int bb = b;
				int len = 0;
				while (bb /= 10) {
					len++;
				}
				b -= pow(10, len);
				if (b < 0) continue;
				//cout << tt << " 번째 버튼 : " << b << "푸시" << endl;
				if (!visit[b]) dq.push_back(b);
				visit[b] = true;
			}
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> t >> g;
	if (bfs() == -1) {
		cout << "ANG" << endl;
	}

	return 0;
}