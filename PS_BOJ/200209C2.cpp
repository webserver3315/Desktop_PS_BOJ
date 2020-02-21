#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;


int n;
vector<int> arr;

int pseudoOR(int a, int b) {
	return (a | b) - b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end());

	int max = 0;
	do {
		int first = arr[0];
		for (int i = 0; i < arr.size() - 1; i++) {
			first = pseudoOR(first, arr[i + 1]);
		}
		for (int i : arr) {
			cout << i << ' ';
		}
		if (first > max) {
			cout << "first : " << first << " max : " << max << endl;
			cout << "UPDATED";
			max = first;
		}
		cout << endl;
		cout << first << " max: " << max << endl;
		cout << endl;
	} while (next_permutation(arr.begin(), arr.end()));

	return 0;
}