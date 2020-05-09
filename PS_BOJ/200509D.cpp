#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;

int t;
int n;
deque<int> cdy;//»çÅÁ
int turn;
int a, b;
int aeat;//Á÷Àü¼·Ãë°ª
int beat;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	while (t--) {
		n = 0; cdy.clear(); aeat = 0; beat = 0; a = 0; b = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			cdy.push_back(tmp);
		}
		//cout << cdy.front() << "¸¸Å­ ¾Ù¸®½º°¡ ¸ÔÀ½" << endl;
		aeat = cdy.front(); cdy.pop_front(); turn++; a += aeat;
		for (turn = 1; !cdy.empty(); turn++) {
			if (turn & 1) {//bob's turn
				int tmpbeat = 0;
				do {
					//cout << cdy.back() << "¸¸Å­ ¹äÀÌ ¸ÔÀ½" << endl;
					tmpbeat += cdy.back(); cdy.pop_back();
				} while (!cdy.empty() && tmpbeat <= aeat);
				b += tmpbeat;
				beat = tmpbeat;
			}
			else {//alice's turn
				int tmpaeat = 0;
				do {
					//cout << cdy.front() << "¸¸Å­ ¾Ù¸®½º°¡ ¸ÔÀ½" << endl;
					tmpaeat += cdy.front(); cdy.pop_front();
				} while (!cdy.empty() && tmpaeat <= beat);
				a += tmpaeat;
				aeat = tmpaeat;
			}
		}
		cout << turn << " " << a << " " << b << endl;
	}

	

	return 0;
}