#include <iostream>
#include <string>
using namespace std;

/*
각 자릿수의 합이 짝수지만, 그 수는 짝수가 아니라면 에브네수라고 한다.
음이 아닌 정수 s가 주어지고, 그 정수는 n자릿수이며
나는 몇 숫자들을 삭제가능하다. 그렇게 에브네수를 만들 수 있따.
그러나 수들의 순서를 바꿀 수는 없다.

편집 이후 수는 첫 자릿수가 0이어선 안된다.

주어진 수로부터 도출가능한 아무 에브네수를 출력하라.
만일 불가능하면 -1을 출력하라.

*/

int t;
int n;
bool nodap;
string str;

/*
경우를 나눌 수 있다.
1. 짝수인가 홀수인가
2. 각 자릿수의 합이 짝수인가 홀수인가.

*/

bool ZzinEven() {//찐 짝수인지 판별. string의 마지막 자릿수가 짝수인지 홀수인지만 판별하면 된다.
	if ((str.back() - '0') % 2 == 0)
		return true;
	return false;
}

bool YusaEven() {//유사 짝수인지 판별. 각 자릿수의 합이 짝수인지 홀수인지만 판별하면 된다.
	int sum = 0;
	for (int i = 0; i < str.length(); i++) {
		sum += str[i] - '0';
	}
	if (sum % 2 == 0)
		return true;
	return false;
}

void Initialize() {
	int n = 0;
	nodap = true;
	str.clear();
	return;
}

//원하는 것: 홀수이면서 각자릿수 합이 짝수
void solve() {
	Initialize();
	cin >> str;
	if (ZzinEven() == true) {//찐양수면, 끝자리부터 홀수나올때까지 닥치고 pop
		while (ZzinEven() == true) {
			str.pop_back();
		}
	}

	//일단 홀수는 만들었고, 마지막자리 lock한 뒤 삭제작업 진행
	if (YusaEven() == true) {//이미 유사양수면 땡큐다
		cout << str << endl;
		return;
	}
	else {//각 자릿수 합이 홀수면, 홀수를 빼서 짝수로 만들어야 한다. 이 때, 최좌측 및 최우측을 제외하고 전부 0밖에 없다면 -1리턴이다.
		for (int i = 1; i < str.length() - 1; i++) {//첫자리 삭제를 일단 방지하기 위해 i를 1부터 시작시킴
			if ((str[i] - '0') % 2 == 0) {
				if (str[i] - '0' != 0)//중간원소 중에서 0이 아닌 수가 하나라도 있으면 일단 노답은 아님.
					nodap = false;
				continue;
			}
			else {
				str.erase(i, 1);
				cout << str << endl;
				return;
			}
		}
		//만일, 첫자리 및 마지막 자릿수를 제외하고 전부 짝수라면, 
		if (nodap) {
			cout << -1 << endl;
			return;
		}
		else {

		}

		return;
	}
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}