/*

*/

#include <iostream>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

deque<int> dq;
int n, bufsiz, dq_siz;

int main() {
	ios::sync_with_stdio(false);
	dq.resize(200001);
	cin >> n >> bufsiz;
	while (n--) {
		int tmp;
		cin >> tmp;
		for (int tmp2 : dq) {
			if (tmp2 == tmp) {
				goto here;/*�ִ°Ŵϱ� �Ÿ���*/
			}
		}
		/*�������� ���� ���*/
		if (dq_siz >= bufsiz) {/*��á����*/
			dq.pop_back();
			dq.push_front(tmp);
		}
		else {/*����������*/
			dq.push_front(tmp);
			dq_siz++;
		}
	here:
		int k;
	}
	cout << dq_siz << endl;
	for (int i = 0; i < dq_siz;i++) {
		cout << dq[+i] << ' ';
	}
	cout << endl;
	return 0;
}