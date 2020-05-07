#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int t;



int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> allStudent;
		for (int i = 0; i < 2 * n; i++) {
			int tmp;
			cin >> tmp;
			allStudent.push_back(tmp);
		}
		sort(allStudent.begin(), allStudent.end());



	}

	return 0;
}