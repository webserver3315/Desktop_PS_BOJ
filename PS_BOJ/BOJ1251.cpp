#include <iostream>
#include <string>
using namespace std;

string str;//���̴� 50 ����. ��, 2�� �ݺ��� ģ�ٰ� �ص�, 51C2 �� 51*25�� �̸��ۿ� �ȵȴ�. �������� �������̴�.
string minstr;

string swapstr(int a, int b) {//1����: 0~a-1, 2����: a~b-1, 3����: b~n-1, �� x+1 ĭ�� ���� ģ��.
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
	//cout << "This time, " << tmp << " �� ���Դ�." << endl;
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