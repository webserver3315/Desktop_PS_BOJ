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

void check(int a, int b) {
	int R = 0; int L = 0; int U = 0; int D = 0;
	for (int i = a; i <= b; i++) {
		if (str[i] == 'R') {
			R++;
		}
		else if (str[i] == 'L') {
			L++;
		}
		else if (str[i] == 'U') {
			U++;
		}
		else if (str[i] == 'D') {
			D++;
		}
		else {
			cout << "ERROR" << endl;
			return;
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
		Ridx.clear(); Lidx.clear(); Uidx.clear(); Didx.clear();
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == 'R') {
				Ridx.push_back(i);
			}
			else if (str[i] == 'L') {
				Lidx.push_back(i);
			}
			else if (str[i] == 'U') {
				Uidx.push_back(i);
			}
			else if (str[i] == 'D') {
				Didx.push_back(i);
			}
			else {
				cout << "error" << endl;
				return 0;
			}
		}
		for (int i = 0; i < Ridx.size(); i++) {
			for (int j = 0; j < Lidx.size(); j++) {
				int a = Ridx[i]; int b = Lidx[j];
				int big = a < b ? b : a;
				int small = a > b ? b : a;
				check(small, big);
			}
		}
		for (int i = 0; i < Uidx.size(); i++) {
			for (int j = 0; j < Didx.size(); j++) {
				int a = Uidx[i]; int b = Didx[j];
				int big = a < b ? b : a;
				int small = a > b ? b : a;
				check(small, big);
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