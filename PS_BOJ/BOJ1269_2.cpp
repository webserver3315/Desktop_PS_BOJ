//이번엔 구태여 SET을 사용해서 풀어보기로 하자.
#include <iostream>
#include <set>
#define MAX (int)1e8
#define endl '\n'
using namespace std;

int a, b;
set<int> A, B;
set<int> C;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		int tmp;
		cin >> tmp;
		A.insert(tmp);
	}
	for (int i = 0; i < b; i++) {
		int tmp;
		cin >> tmp;
		B.insert(tmp);
	}
	for (int i : A) {
		if (B.find(i) != B.end())
			C.insert(i);
	}
	cout << A.size() + B.size() - 2 * C.size() << endl;

	return 0;
}