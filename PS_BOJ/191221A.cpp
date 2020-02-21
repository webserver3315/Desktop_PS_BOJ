/*#609 Div2 A*/

#include <iostream>
#include <cmath>
#define MAX (int)1e8
using namespace std;

/*빼서 n이 되도록 만드는 합성수 n을 찾아라. 답은 언제나 존재하고 아무거나 찾으면 된다.
일단 소수판별은 에라토스체를 이용해서 빨리 구하는거 ㄱㄴ하다.
소수테이블 만든 뒤에 어쩔껀가?
일단, a,b의 범위는 10의 9승보다 작다. 연산량이 8승이니 일반적인 수단은 안먹힌다고 보면 된다.
10의 9승까지 그냥 테이블 만들어버리는게 제일 빠르지않나?
시간은 일단 3초걸리고,
테이블 만든 뒤로는 ㅈㄴ 간단하다.
*/

int n;
bool IsComposite[MAX + 1];

void makeEratos() {
	for (int i = 2; i < sqrt(MAX + 1); i++) {
		if (IsComposite[i] == true)
			continue;
		else {
			for (int j = i*2; j < MAX + 1; j+=i) {
				//printf("%d 는 소수가 아닙니다\n", j);
				IsComposite[j] = true;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	makeEratos();
	for (int i = 2; i <= MAX-n; i++) {
		if (IsComposite[i] == true && IsComposite[i + n] == true) {
			cout << i + n << ' ' << i << endl;
			return 0;
		}
	}

	return 0;
}