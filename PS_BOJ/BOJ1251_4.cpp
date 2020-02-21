#include <iostream>
#include <string>
#include <algorithm>
#define MAX 51
using namespace std;

string str;
string minstr;

string SanTouBun(int a, int b) {//[0,a], [a+1,b], [b+1,n-1) 까지
	string first, second, third;
	string answer;
	for (int i = 0; i <= a; i++) {
		first += str[i];
	}
	for (int i = a + 1; i <= b; i++) {
		second += str[i];
	}
	for (int i = b + 1; i < str.length(); i++) {
		third += str[i];
	}
	reverse(first.begin(), first.end());
	reverse(second.begin(), second.end());
	reverse(third.begin(), third.end());
	answer = first + second + third;
	return answer;
}

int main() {
	cin >> str;
	minstr = str;
	for (int f = 0; f < str.length() - 2; f++) {
		for (int s = f + 1; s < str.length() - 1; s++) {
			//cout << "f: " << f << " s: " << s << endl;
			string tmp;
			tmp = SanTouBun(f, s);
			if (minstr > tmp) {
				//cout << "사건발생 - f: " << f << " s: " << s << endl;
				minstr = tmp;
			}
		}
	}
	cout << minstr << endl;
	return 0;
}