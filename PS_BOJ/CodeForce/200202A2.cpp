#include <iostream>
#include <string>
#include <stdlib.h>
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
	str.clear();
	return;
}

//원하는 것: 홀수이면서 각자릿수 합이 짝수
void solve() {
	Initialize();
	cin >> n;
	cin >> str;
	if (ZzinEven() == true) {//찐양수면, 끝자리부터 홀수나올때까지 닥치고 pop
		while (ZzinEven() == true) {
			if (str == "0") {
				cout << -1 << endl;
				return;
			}
			str.pop_back();
			if (str.empty() == true) {
				cout << -1 << endl;
				return;
			}
		}
	}

	//일단 홀수는 만들었고, 마지막자리 lock한 뒤 삭제작업 진행
	if (YusaEven() == true) {//이미 유사양수면 땡큐다
		cout << str << endl;
		return;
	}
	else {//각 자릿수 합이 홀수면, 홀수를 빼서 짝수로 만들어야 한다. 이 때, 최좌측 및 최우측을 제외하고 전부 0밖에 없다면 -1리턴이다.
		//적어도 최좌측은 살아있어야 하기 때문에, 최좌측이 홀수냐 짝수냐에 따라 갈린다.
		//최좌측이 짝수면 속살 중 홀수가 없다면 ㅈㅈ.
		//최좌측이 홀수면 속살 중 0이 아닌 어떤 수라도 있으면 ㅇㅋ
		int zeros = 0;
		int evens = 0;
		int odds = 0;
		int evenidx = -1;
		int oddidx = -1;
		for (int i = 0; i < str.length() - 1; i++) {
			int tmp = str[i] - '0';
			if (tmp % 2 == 0) {
				if (tmp == 0)
					zeros++;
				else {
					evens++;
					evenidx = i;
				}
			}
			else {
				odds++;
				oddidx = i;
			}
		}
		if (odds > 1) {//홀수가 2개 이상이면 생각할 것도 없다. 마지막 홀수 빼면 된다.
			if (str.empty() == false) {//혹시에러방지용
				str.erase(oddidx, 1);
				cout << str << endl;
				return;
			}
			else {
				cout << "ERROR" << endl;
				return;
			}
		}
		else {//odds가 1개 or 아예 없음
			if (odds == 1) {//1개만 있으면, 그게 최전방원소 아니면서도 짝수원소가 하나라도 있기를 빌어야한다.
				if (evens == 0) {//최전방, 최후방만 홀수 나머지 전부 0
					cout << -1 << endl;
					return;
				}
				else {//홀수 및 짝수 전부 존재. 대가리가 홀수인지 짝수인지는 불명.
					if ((str.front() - '0') % 2 != 0) {//대가리가 홀수면, 어딘가에는 짝수가 있다. 대가리 참수하고 짝수를 머리로 넣자.
						int secondone = 0;
						for (int i = 1; i <= evenidx; i++) {
							if (str[i] != 0) {
								secondone = i;
								break;
							}
						}
						for (int i = secondone; i < str.length(); i++) {
							cout << str[i];
						}
						cout << endl;
						return;
					}
					else {//대가리가 짝수이고, 홀수가 존재하면
						int secondone = 0;
						for (int i = 1; i <= oddidx; i++) {
							if (str[i] != 0) {
								secondone = i;
								break;
							}
						}
						str.erase(secondone, 1);
						cout << str << endl;
						return;
					}
				}
			}
			else {//아예 없으면 노답
				cout << -1 << endl;
				return;
			}
		}


		return;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}