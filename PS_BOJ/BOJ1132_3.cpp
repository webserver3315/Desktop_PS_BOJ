#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#define pic pair<int, char>
#define ff first
#define ss second
using namespace std;

int n;
int top = 9;
vector<string> everything;
int freqTable[10][12];
int allocated[10];

int ctoi(char c) {
	return c - 'A';
}

void makeTable() {
	for (int a = 0; a < n; a++) {
		for (int i = 0; i < 12; i++) {
			if (everything[a][i]<'A' || everything[a][i]>'J')
				break;
			int alphabet = everything[a][i] - 'A';
			freqTable[alphabet][i]++;
		}
	}
}

void allocating(int idx) {
	if (idx < 0)
		return;

	vector<int> buffer;
	for (int lim = 50; lim >= 0; lim--) {
		for (int i = 0; i < n; i++) {
			if (freqTable[i][idx] == lim) {
				buffer.push_back(i);
			}
		}
		if (!buffer.empty()) {
			if (buffer.size() == 1) {
				allocated[buffer[0]] = top--;
			}
			else {
				allocating(idx - 1);
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string tmpstr;
		cin >> tmpstr;
		reverse(tmpstr.begin(), tmpstr.end());
		everything.push_back(tmpstr);
	}

	makeTable();

	return 0;
}