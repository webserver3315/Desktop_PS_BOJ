/*
2020.03.08 ¿Á≈¡
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

//
int myabs(int n) {
	return n > 0 ? n : -n;
}

//bool operator<(pii a, pii b) {//pair = key, value
//	if (a.ff > b.ff)
//		return true;
//	else if (a.ff == b.ff)
//		if (a.ss > b.ss)
//			return true;
//	return false;
//}

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

int N;
//priority_queue<pii> pq;
priority_queue<stc> pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int tmp;
	while (N--) {
		cin >> tmp;
		//if (tmp) {
		//	int abstmp = myabs(tmp);
		//	pq.push(mp(abstmp, tmp));
		//}
		//else {
		//	if (pq.empty())
		//		cout << 0 << endl;
		//	else {
		//		cout << pq.top().ff << ' ' << pq.top().ss << endl;
		//		pq.pop();
		//	}
		//}
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