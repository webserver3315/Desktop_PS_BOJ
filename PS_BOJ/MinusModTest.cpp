#include <iostream>
using namespace std;

int myMod(int a, int b) {// a%b
	int ans = a - b * ((a / b) - 1);
	return ans % b;
}

int main() {
	/*int a = -7;
	int b = 3;*/
	int a = 701;
	int b = 169;
	cout << a % b << endl;
	cout << myMod(a,b) << endl;
	return 0;
}