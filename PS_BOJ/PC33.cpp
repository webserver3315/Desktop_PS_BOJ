#include <iostream>
#include <string>
#include <algorithm>
#define endl '\n'
using namespace std;

/*
편의를 위해 string으로 안받고 정수열로 10진수를 유지한다.
*/

string strA;
string strB;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> strA >> strB;
	
	while (strA != "0" || strB != "0") {
		int cnt = 0;
		reverse(strA.begin(), strA.end()); reverse(strB.begin(), strB.end());
		if (strB.length() > strA.length()) {//무조건 A가 길거나 같게 처리한다.
			swap(strA, strB);
		}
		for (int i = 0; i < strB.length(); i++) {
			strA[i] += strB[i];//digit의 char는 48~57이므로, 2배때려도 127 초과해서 오버플로우나는 일 따위는 없으므로 이렇게 해도 된다. 
		}

		for (int i = 0; i < strA.length(); i++) {
			if (strA[i] > '9' + '0') {
				cnt++;
				if (strA[i] > '9' + '0')
					strA[i] -= (':');
				if (i != strA.length() - 1)
					strA[i + 1] += '1';//555 555시 오버플로우 난다
				else
					strA.append("1");
			}
			else
				strA[i] -= '0';
		}
		/*if (cnt == 0)
			cout << "No carry operation." << endl;
		else if (cnt == 1)
			cout << cnt << " carry operation." << endl;
		else
			cout << cnt << " carry operations." << endl;*/
		cout << cnt << endl;
		cin >> strA >> strB;
	}

	return 0;
}