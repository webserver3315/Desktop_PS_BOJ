#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int t;
int n;
int mindiff = 2e5 + 1;
int maxnum = 2e5 + 1;
int minnum;
string str;
vector<int> Ridx;
vector<int> Lidx;
vector<int> Uidx;
vector<int> Didx;

/*
R-L+U-D == 0를 만족하는
가장 짧은 닫힌구간 [a,b]를 찾으면 된다.
*/
//유의: 0인덱스 삭제를 출력시에는 1인덱스라고 표현해야한다.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> str;
		minnum = 0;
		maxnum = 2e5 + 1;
		mindiff = 2e5 + 1;
		for (int a = 0; a < str.length() - 1; a++) {
			int R = 0; int L = 0; int U = 0; int D = 0;
			for (int b = a; b < str.length(); b++) {
				if (str[b] == 'R') {
					R++;
				}
				else if (str[b] == 'L') {
					L++;
				}
				else if (str[b] == 'U') {
					U++;
				}
				else if (str[b] == 'D') {
					D++;
				}
				else {
					cout << "ERROR" << endl;
					return 0;
				}

				if (R - L == 0 && U - D == 0) {
					if (b - a < mindiff) {
						mindiff = b - a;
						maxnum = b + 1;
						minnum = a + 1;
					}
				}
			}
		}
		if (mindiff == 2e5 + 1) {
			cout << -1 << endl;
		}
		else
			cout << minnum << ' ' << maxnum << endl;
	}
	return 0;
}