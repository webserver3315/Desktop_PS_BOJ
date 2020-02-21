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

//int recur(int depth) {
//	if(depth)
//}

void printPicked(const vector<int> picked) {
	for (auto i : picked) {
		cout << i << " ";
	}
	cout << endl;
	return;
}

void pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		printPicked(picked);
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; ++next) {
		picked.push_back(next);
		pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

void reverse_pick(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		printPicked(picked);
		return;
	}
	int biggest = picked.empty() ? n - 1 : picked.back() - 1;
	for (int next = biggest; next >= 0; next--) {
		picked.push_back(next);
		reverse_pick(n, picked, toPick - 1);
		picked.pop_back();
	}
	return;
}

void pick2(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		printPicked(picked);
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick2(n, picked, toPick - 1);
		picked.pop_back();
	}
	return;
}

void reverse_pick2(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		printPicked(picked);
		return;
	}
	int biggest = picked.empty() ? n : picked.back() - 1;
	for (int next = biggest; next >= 0; next--) {
		picked.push_back(next);
		reverse_pick2(n, picked, toPick - 1);
		picked.pop_back();
	}
	return;
}

void pick3(int n, vector<int>& picked, int toPick) {
	if (toPick == 0) {
		printPicked(picked);
		return;
	}
	int smallest = picked.empty() ? 0 : picked.back() + 1;
	for (int next = smallest; next < n; next++) {
		picked.push_back(next);
		pick3(n, picked, toPick - 1);
		picked.pop_back();
	}
	return;
}

void reverse_pick3(int n, vector<int> picked, int toPick) {
	if (!toPick) {
		printPicked(picked);
		return;
	}
	int biggest = picked.empty() ? n - 1 : picked.back() - 1;
	for (int next = biggest; next >= 0; next--) {
		picked.push_back(next);
		reverse_pick3(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 7;
	vector<int> picked;
	//for (int i = 0; i < n; ++i)
	//	for (int j = i + 1; j < n; ++j)
	//		for (int k = j + 1; k < n; ++k)
	//			for (int l = k + 1; l < n; ++l)
	//				cout << i << " " << j << " " << k << " " << l << endl;
	cout << endl;
	pick(n,picked,5);
	picked.clear();
	cout << endl;
	reverse_pick(n, picked, 5);
	picked.clear();

	cout << endl;
	pick2(n, picked, 5);
	picked.clear();
	cout << endl;
	reverse_pick2(n, picked, 5);
	picked.clear();

	cout << endl;
	pick3(n, picked, 5);
	picked.clear();
	cout << endl;
	reverse_pick3(n, picked, 5);
	picked.clear();

	return 0;
}