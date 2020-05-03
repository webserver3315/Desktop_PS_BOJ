#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int t;
int n;
int mindiff = 2e5 + 1;
string str;
vector<int> Ridx;
vector<int> Lidx;
vector<int> Uidx;
vector<int> Didx;

/*
R-L+U-D == 0�� �����ϴ�
���� ª�� �������� [a,b]�� ã���� �ȴ�.
*/
//����: 0�ε��� ������ ��½ÿ��� 1�ε������ ǥ���ؾ��Ѵ�.

bool Check(int a, int b) {//[a,b] ���� ���� R-L+U-D�� ���� 0���� üũ.
	int Rcnt = 0; int Lcnt = 0; int Ucnt = 0; int Dcnt = 0;
	for (int i = a; i <= b; i++) {
		if (str[i] == 'R') {
			Rcnt++;
		}
		else if (str[i] == 'L') {
			Lcnt++;
		}
		else if (str[i] == 'U') {
			Ucnt++;
		}
		else if (str[i] == 'D') {
			Dcnt++;
		}
		else {
			cout << "error" << endl;
			return false;
		}
	}
	if (Rcnt - Lcnt + Ucnt - Dcnt == 0)
		return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> str;
		int mindiff = 2e5;
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
				if (Check(small, big)) {
					if (big - small < mindiff)
						mindiff = big - small;
				}
			}
		}
		for (int i = 0; i < Uidx.size(); i++) {
			for (int j = 0; j < Didx.size(); j++) {
				int a = Uidx[i]; int b = Didx[j];
				int big = a < b ? b : a;
				int small = a > b ? b : a;
				if (Check(small, big)) {
					if (big - small < mindiff)
						mindiff = big - small;
				}
			}
		}
		if (mindiff == 2e5 + 1) {
			cout << -1 << endl;
		}
		else
			cout << mindiff << endl;
	}
	return 0;
}