#include <iostream>
#include <vector>
using namespace std;

int t;

int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> arr;
		int sum = 0;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (tmp == 0) {
				cnt++;
				tmp = 1;
			}
			arr.push_back(tmp);
			sum += tmp;
		}
		if (sum == 0)
			cout << cnt + 1 << endl;
		else
			cout << cnt << endl;
	}
	return 0;
}