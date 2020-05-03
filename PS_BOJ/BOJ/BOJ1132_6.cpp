#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;//�־��� ���ڿ��� ���� ��
vector<string> strvct;
int maxval;//���� �� ����.

int alphabetsScore[26];

/*
https://lmcoa15.tistory.com/79
�� �����ؼ� ������ ������ ÷���� �׸����ϰ� Ǯ����.

������ ����, 12�ڸ��̹Ƿ� 
long long�� 1e18�������� ���������ʳ�?

string ����� ���� ������ �����ٵ� ��� Ʋ������?
*/

signed ctoi(char c) {
	return c - 'A';//����� �����ٸ� �ݵ�� ����� ���;� ��.
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