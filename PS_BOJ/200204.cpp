#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int t;
int n;
int mindiff = 2e5 + 1;
int max = 2e5 + 1;
int min;
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
		min = 0;
		max = 2e5 + 1;
		mindiff = 2e5 + 1;

	}
	return 0;
}