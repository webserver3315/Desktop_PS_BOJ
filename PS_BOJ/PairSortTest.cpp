/*
�Ʊ���
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define endl '\n'
#define MAX 21
#define ff first
#define ss second
using namespace std;

typedef pair<int, int> pii;

/*
����� ũ�⸦ Ű�� �Ͽ� �켱����ť�� ����� ���� �� �������� �𸣰�����, �ϴ� naive�ϰ� Ǯ���.
���̽� ���� �ʿ䵵 ���� �̰� �� ������ ��Ģ��� �����̰Բ��� �ϸ� �ȴ�.
*/
int N;
int field[MAX][MAX];
int sec;
int ssize = 2;//���ũ��
int eatcnt;
int sr, sc;//�����ġ

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pii> testvct;
	testvct.push_back({ 1,2 });
	testvct.push_back({ 2,3 });
	testvct.push_back({ 2,4 });
	testvct.push_back({ 1,3 });
	testvct.push_back({ 2,5 });
	testvct.push_back({ 3,1 });
	testvct.push_back({ 3,2 });
	sort(testvct.begin(), testvct.end());

	for (auto tmp : testvct) {
		cout << tmp.ff << ' ' << tmp.ss << endl;
	}

	return 0;
}