/*
2020.03.08 재탕

자체 구조체를 만들어서 < 연산자를 오버로딩해서 PRIORITY를 DIY 판별기준으로 수정한 것.
이상하게 PAIR를 쓰면, 오버로딩이 기본설정에 자꾸 씹히는 문제점이 발생해서
아예 유사PAIR로 stc 구조체를 만들었다.
*/
#include <iostream>
#include <queue>
#include <utility>
#define endl '\n'
#define pii pair<int,int>
#define ff first
#define ss second
#define mp(a,b) make_pair(a,b)
using namespace std;

struct stc {
	int key;
	int val;
};

bool operator<(stc a, stc b) {
	if (a.key > b.key)
		return true;
	else if (a.key == b.key)
		if (a.val > b.val)
			return true;
	return false;
}

int myabs(int n) {
	return n > 0 ? n : -n;
}

int N;
priority_queue<stc> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	while (N--) {
		cin >> tmp;
		if (tmp) {
			int abstmp = myabs(tmp);
			stc stctmp = { abstmp,tmp };
			pq.push(stctmp);
		}
		else {
			if (pq.empty())
				cout << 0 << endl;
			else {
				cout << pq.top().val << endl;
				pq.pop();
			}
		}
	}
	return 0;
}