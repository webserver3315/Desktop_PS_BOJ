/*

*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int n;
string GlobalStr;
bool isExist[26];

void Change(int i, char c) {
	GlobalStr[i] = c;
}

void ClearIsExist(){
	for (int i = 0; i < 26; i++) {
		isExist[i] = false;
	}
}

int CountExist() {
	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (isExist[i])
			++cnt;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin >> GlobalStr >> n;
	for (int i = 0; i < n; i++) {
		int order, cnt;
		cnt = 0;
		cin >> order;
		if (order == 1) {
			int idx;
			char ch;
			cin >> idx >> ch;
			Change(idx - 1, ch);
		}
		else {
			int idx1, idx2;
			cin >> idx1 >> idx2;
			for (int idx = idx1 - 1; idx < idx2; idx++) {
				if (!isExist[GlobalStr[idx] - 'a']) {
					isExist[GlobalStr[idx] - 'a'] = true;
					++cnt;
				}
			}
			printf("%d\n", cnt);
			ClearIsExist();
		}
	}
}