#include <iostream>
#include <vector>
using namespace std;


int n;
vector<int> divisor;

int main() {
	cin >> n;
	while (n != -1) {
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {//i가 n의 약수이면
				divisor.push_back(i);
				sum += i;
			}
		}

		if (sum == n) {
			cout << n << " = ";
			int i;
			for (i = 0; i < divisor.size() - 1; i++) {
				cout << divisor[i] << " + ";
			}
			cout << divisor[i] << endl;
		}
		else {
			cout << n << " is NOT perfect." << endl;
		}
		divisor.clear();
		cin >> n;
	}
	return 0;
}