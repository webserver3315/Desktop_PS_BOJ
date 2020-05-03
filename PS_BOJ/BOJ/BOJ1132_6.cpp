#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;//주어질 문자열의 라인 수
vector<string> strvct;
int maxval;//답이 될 숫자.

int alphabetsScore[26];

/*
https://lmcoa15.tistory.com/79
를 참조해서 간단한 수학을 첨가해 그리디하게 풀었다.

주의할 점은, 12자리이므로 
long long은 1e18정도까지 지원하지않나?

string 말고는 답이 없지는 않을텐데 어디서 틀린거지?
*/

signed ctoi(char c) {
	return c - 'A';//제대로 쓰였다면 반드시 양수가 나와야 함.
}


bool desc(int a, int b) {
	return a > b;
}

signed main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string tmpstr;
		cin >> tmpstr;
		reverse(tmpstr.begin(), tmpstr.end());
		strvct.push_back(tmpstr);
	}
	//makeTable();
	for (int i = 0; i < strvct.size(); i++) {
		for (int j = 0; j < strvct[i].length(); j++) {
			signed idx = ctoi(strvct[i][j]);
			int plus = pow(10, j);
			alphabetsScore[idx] += plus;
		}
	}

	sort(alphabetsScore, alphabetsScore + 26, desc);

	for (int i = 9; i >= 0; i--) {
		maxval += i * alphabetsScore[9 - i];
	}
	
	cout << maxval << endl;
	return 0;
}