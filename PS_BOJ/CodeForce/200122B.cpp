/*
테케 1e2제
상자는 1e3제
가로세로 좌표 1e3제, 총 격자는 1e6
*/
#include <iostream>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <array>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <climits>
using namespace std;
#define endl '\n'
#define ff first
#define ss second
typedef std::pair <int, int> pii;
#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

vector<pii> boxZahyo;
int t;
int n;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	while (t--) {
		boxZahyo.clear();
		int n;
		cin >> n;

		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			pii tmppii = mp(x, y);
			boxZahyo.push_back(tmppii);
		}
		
		/*
		앵간하면 닥치고 오른쪽.
		그런데 봤을 때 위에 박스 있으면 울며겨자먹기로 올려야함.
		그런데, 올라갔을 때 아래측에 박스 있으면 ㅈㅈ.
		즉, 오름차순정렬을 했을 때
		1,2 1,3 3,3 4,3 5,5
		0,1 1,0
		4,3
		이렇게 했을 때 y좌표 또한 자연스레 비내림차순이 되어야 함.
		*/
		sort(boxZahyo.begin(), boxZahyo.end());
		bool Kanou = true;
		for (int i = 1; i < n; i++) {
			if (boxZahyo[i - 1].ss > boxZahyo[i].ss) {
				Kanou = false;
			}
		}

		if (!Kanou) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		string kotae;
		int nowx = 0; int nowy = 0;
		for (int i = 0; i < n;) {//박스 주우러 가야지
			int xx = boxZahyo[i].ff; int yy = boxZahyo[i].ss;
			if (nowx < xx) {
				kotae.append("R");
				nowx++;
			}
			else if (nowy < yy) {
				kotae.append("U");
				nowy++;
			}
			else if (nowx == xx && nowy == yy) {//엄밀히는, nowx==xx이고 nowy==yy일 때
				i++;
			}
			else {
				cout << "ERROR" << endl;
				break;
			}
		}
		cout << kotae << endl;
	}



	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}