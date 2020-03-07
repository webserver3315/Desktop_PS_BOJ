#include <iostream>
#define MAX (int)1e8+1
using namespace std;

/*BST를 쓰는 방법이 있고, 배열을 통짜로 쓰는 방법이 있다.
int는 4바이트이므로 8승때리면 위험하다.
bool은 1바이트이므로 8승때려도 256메가 내로 들어온다.
비트마스크는 1비트이므로 아주 여유일 것이다.
*/

int A, B;
bool visitA[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;
	for (int i = 0; i < A; i++) {
		int tmp;
		cin >> tmp;
		visitA[tmp] = true;
	}

	int cross = 0;//겹치는 갯수
	for (int i = 0; i < B; i++) {
		int tmp;
		cin >> tmp;
		if (visitA[tmp])
			cross++;
	}
	cout << A + B - 2 * cross << endl;

	return 0;
}