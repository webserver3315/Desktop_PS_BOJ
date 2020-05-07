/*
구간 합 구하기
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
#define int long long
using namespace std;

vector<int> segtree;
int TreeSize;
int n, m, k;

/*루트노드 인덱스는 1이다 1!!!!!!!*/

void InitializingSegmentTree() {
	TreeSize = 1;
	while (TreeSize < n)
		TreeSize *= 2;
	segtree.resize(TreeSize * 2 + 2);//어차피 ㅈㄴ넉넉하게 할당하는게 낫다.
	TreeSize--;//이거 굳이 필요해? >>> 안하면 TreeSize는 2의 배수가 되겠지? 근데 leaf depth 보다 한 단계 윗층의 최우단 노드의 번호는 루트노드가 1이라는 전제 하에서는 홀수가 될 수밖에 없으니까 홀수로 맞춰준다고 생각하면 편하다.
}

void update(int idx, int val) {//leaf node idx = idx+TreeSize
	int leafNodeIdx = idx + TreeSize;
	segtree[leafNodeIdx] = val;
	while (leafNodeIdx > 0) {
		leafNodeIdx /= 2;
		segtree[leafNodeIdx] = segtree[leafNodeIdx * 2] + segtree[leafNodeIdx * 2 + 1];
	}
}

int sum(int LL, int RR, int NodeL, int NodeR, int Nodeidx) {//LL RR NODEL NODER 모두 [) 가 아니라 [] 구간이라는 점에 유념하라
	if (LL > NodeR || RR < NodeL)//하나도 안겹칠 경우
		return 0;
	else if (LL <= NodeL && RR >= NodeR)//구하고자하는 부분이 현재 노드구간을 완전히 품을 경우
		return segtree[Nodeidx];
	else {//일부만 겹치는 경우
		int mid = (NodeL + NodeR) / 2;
		return sum(LL, RR, NodeL, mid, Nodeidx * 2) + sum(LL, RR, mid + 1, NodeR, Nodeidx * 2 + 1);// [NodeL,NodeR) 이 아니라 [NodeL,NodeR] 임에 유의!
	}
}

signed main() {/*루트노드의 노드번호는 0번으로 한다.*/
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	
	InitializingSegmentTree();

	for (int i = 1; i < n + 1; i++) {
		int tmp;
		cin >> tmp;
		update(i, tmp);
	}

	for (int i = 0; i < m + k; i++) {
		int o1, o2, o3;
		cin >> o1 >> o2 >> o3;
		if (o1 == 1) {
			update(o2, o3);
			continue;
		}
		else if (o1 == 2) {
			//cout << sum(o2, o3, 1, n + 1, 1) << endl;
			//cout << sum(o2, o3, 1, n, 1) << endl;
			cout << sum(o2, o3, 1, TreeSize + 1, 1) << endl;
			continue;
		}
		else {
			cerr << "Undefined Order" << endl;
			exit(1);
		}
	}

	return 0;
}