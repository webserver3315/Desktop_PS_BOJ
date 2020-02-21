#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

int n;
int top = 9;
vector<string> everything;
int freqTable[50][13];//12번 인덱스에는 문자열의 길이가 들어감.
int allocated[10];

int GoJyuSinHou(int arr[]) {//string 숫자열을 받아서 50진법으로 취급해 10진법 int로 바꿔준다.
	int sum = 0;
	for (int idx = 0; idx < 12; idx++) {
		sum += pow(50, idx) * arr[idx];
	}
	return sum;
}

void makeTable() {
	for (int a = 0; a < n; a++) {
		for (int i = 0; i < 12; i++) {
			if (everything[a][i]<'A' || everything[a][i]>'J')
				break;
			int alphabet = everything[a][i] - 'A';
			freqTable[alphabet][i]++;
		}
		freqTable[a][12] = everything[a].length();
	}
}

void SortPIC() {
	vector<pair<int, char>> vctpic;
	int bottom = 0;
	for (int i = 0; i < 10; i++) {
		int score = GoJyuSinHou(freqTable[i]);
		pair<int, char> tmppic = make_pair(score, i + 'A');
		vctpic.push_back(tmppic);
	}
	sort(vctpic.begin(), vctpic.end());
	for (int i = 0; i < 10; i++) {
		allocated[vctpic[i].second - 'A'] = bottom++;
	}
	return;
}

int calcMaxVal() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < everything[i].length();j++) {
			int digit = allocated[everything[i][j]-'A'];
			sum += pow(10, j) * digit;
		}
	}
	return sum;
}

signed main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmpstr;
		cin >> tmpstr;
		reverse(tmpstr.begin(), tmpstr.end());
		everything.push_back(tmpstr);
	}

	makeTable();
	SortPIC();
	int ans = calcMaxVal();
	cout << ans << endl;

	return 0;
}

/*
테케 다 맞췄는데 오류가 나온다.
정직하게 백트래킹 재귀 써야하나.
*/