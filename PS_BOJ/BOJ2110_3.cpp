/*
������ ��ġ

�� ������ �������� ������ Ȯ���ϴ� ���� �ƴ� �̺� Ž���� ����� �̿��ϴ� ���̴�.

"�������� ���� Ű�� ���� �� �ְڱ�"

	Ư�� ������ �������� ������ ��ġ�� �����⸦ ��ġ�Ѵ�.
	��ġ�� �Ŀ��� ������ �Ǵ��Ѵ�.
	������ ���� �� ��ġ�Ǿ�� �Ѵٸ�, ������ ���δ�.
	������ ���� �ٿ����Ѵٸ�, ������ �ø���.



��ó: https://mygumi.tistory.com/301 [���̱����� HelloWorld]
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ld, rd, md;//��������, �ִ밣��, �����������ΰ���
int N, C;
int RouterNum;

vector<int> housePosition;

void psearch() {
	while (RouterNum != C) {

	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		housePosition.push_back(tmp);
	}
	sort(housePosition.begin(), housePosition.end());

	ld = 1; rd = housePosition.back() - housePosition.front(); /*md = (ld + rd) / C;*/


	psearch();

	return 0;
}