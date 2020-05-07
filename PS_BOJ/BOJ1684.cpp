#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int t;
int n;
int minval = 1e6 + 1;
vector<int> arr;

/*
일단 한번 뇌비우고 풀어보자.
브루트하게 푸는거다.
*/

/*
C에서 기본적으로 지정된 몫과 나머지 연산과, 이 문제에서 정의된 해당 연산은 차이가 있다.
즉, 직접 구현해야한다.
*/

int myMod(int a, int b) {//a%b
	return a - b * ((a / b) - 1);
}

/*
b*tmp가 a보다 반드시 크거나 같음이 보장됨. a=b*tmp+R에서 R은 무조건 음수가 되므로.
그러나, 이 문제에서는 R은 언제나 양수가 되어야 한다.
즉, 기존의 나머지는 a-b*tmp 로 표현된다면
현재의 나머지는 a-b*(tmp-1) 이 된다.
즉, a-b*((a/b)-1) 이 되는 것이다.
다만, 그 결과가 b와 동일하게 나올 경우 나머지를 0으로 정정해줘야한다.
*/

int main() {
	t = 1;
	while (t--) {
		cin >> n;
		arr.clear();
		minval = 1e6 + 1;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			if (minval > tmp)
				minval = tmp;
			arr.push_back(tmp);
		}

		sort(arr.begin(), arr.end());

		for (int nowDiv = arr.back(); nowDiv > 0; nowDiv--) {
			bool dameda = false;
			int flag = myMod(arr.front(), nowDiv);
			for (int i = 0; i < n; i++) {
				if (flag != myMod(arr[i], nowDiv)) {
					dameda = true;
					break;
				}
			}
			if (!dameda) {
				cout << nowDiv << endl;
				break;
			}
		}
	}
	return 0;
}