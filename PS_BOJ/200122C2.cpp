/*
테케 2승
각 인풋정수는 9승미만.
즉, 이거 생각없이 선형으로 나누기하다가는 무조건 시간초과뜸.
소수로만 나눠야하나... 그건 틀리다.
2의6승도 가능하기 때문이다.
그런데, 안되는 경우는 이미 방문했을 때 뿐이다.
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
#define MAX 31625
//#define ff first
//#define ss second
//typedef std::pair <int, int> pii;
//#define mp(x,y) make_pair(x,y)
//P mypair = make_pair(1.2);//권장사항
//pair<int, int> mypair = make_pair(1, 2);//C++11 비지원시 이렇게
//P mypair = { 1,2 };//C++11 이후부터만 가능
//P mypair(1, 2);//생성자이용

int t;
int n;
vector<int> kotae;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);
	double ctime_start, ctime_finish, ctime_duration;
	ctime_start = clock();

	cin >> t;
	while (t--) {
		kotae.clear();
		cin >> n;
		int cnt = 0;
		int rootval = (int)sqrt(n) + 1;
		for (int div = 2; div < rootval && cnt < 2; div++) {
			if (n % div == 0) {
				cnt++;
				n /= div;
				kotae.push_back(div);
				continue;
			}
		}

		if (cnt >= 2) {
			if (kotae.back() >= n) {
				cout << "NO" << endl;
				continue;
			}
			else {
				cout << "YES" << endl;
				for (int i = 0; i < kotae.size(); i++) {
					cout << kotae[i] << ' ';
				}
				cout << n << ' ';
				cout << endl;
				continue;
			}
		}
		else {
			cout << "NO" << endl;
			continue;
		}
	}


	ctime_finish = clock();
	ctime_duration = ((double)(ctime_finish - ctime_start));
	//cout << ctime_duration << " ms" << endl;
	return 0;
}