#include <iostream>
#include <string>
using namespace std;

string str;//길이는 50 이하. 즉, 2개 격벽을 친다고 해도, 51C2 즉 51*25개 미만밖에 안된다. 전수조사 ㅆㄱㄴ이다.
string minstr;

string swapstr(int a, int b) {//1구역: 0~a-1, 2구역: a~b-1, 3구역: b~n-1, 즉 x+1 칸에 벽을 친다.
	int idx = 0;
	string tmp;
	tmp.reserve(51);
	for (int i = a - 1; i >= 0; i--) {
		tmp.append(string(1, str[i]));
	}
	for (int i = b - 1; i >= a; i--) {
		tmp.append(string(1, str[i]));
	}
	for (int i = str.length() - 1; i >= b; i--) {
		tmp.append(string(1,str[i]));
	}
	//cout << "This time, " << tmp << " 가 나왔다." << endl;
	return tmp;
}

int main() {
	cin >> str;
	minstr = str;
	for (int i = 1; i < str.length() - 1; i++) {
		for (int j = i + 1; j < str.length() ; j++) {
			string nowswaped;
			nowswaped = swapstr(i, j);
			if (nowswaped < minstr)
				minstr = nowswaped;
		}
	}
	cout << minstr;
	return 0;
}