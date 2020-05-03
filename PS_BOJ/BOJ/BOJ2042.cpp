/*
���� �� ���ϱ�
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

/*��Ʈ��� �ε����� 1�̴� 1!!!!!!!*/

void InitializingSegmentTree() {
	TreeSize = 1;
	while (TreeSize < n)
		TreeSize *= 2;
	segtree.resize(TreeSize * 2 + 2);//������ �����˳��ϰ� �Ҵ��ϴ°� ����.
	TreeSize--;//�̰� ���� �ʿ���? >>> ���ϸ� TreeSize�� 2�� ����� �ǰ���? �ٵ� leaf depth ���� �� �ܰ� ������ �ֿ�� ����� ��ȣ�� ��Ʈ��尡 1�̶�� ���� �Ͽ����� Ȧ���� �� ���ۿ� �����ϱ� Ȧ���� �����شٰ� �����ϸ� ���ϴ�.
}

void update(int idx, int val) {//leaf node idx = idx+TreeSize
	int leafNodeIdx = idx + TreeSize;
	segtree[leafNodeIdx] = val;
	while (leafNodeIdx > 0) {
		leafNodeIdx /= 2;
		segtree[leafNodeIdx] = segtree[leafNodeIdx * 2] + segtree[leafNodeIdx * 2 + 1];
	}
}

int sum(int LL, int RR, int NodeL, int NodeR, int Nodeidx) {//LL RR NODEL NODER ��� [) �� �ƴ϶� [] �����̶�� ���� �����϶�
	if (LL > NodeR || RR < NodeL)//�ϳ��� �Ȱ�ĥ ���
		return 0;
	else if (LL <= NodeL && RR >= NodeR)//���ϰ����ϴ� �κ��� ���� ��屸���� ������ ǰ�� ���
		return segtree[Nodeidx];
	else {//�Ϻθ� ��ġ�� ���
		int mid = (NodeL + NodeR) / 2;
		return sum(LL, RR, NodeL, mid, Nodeidx * 2) + sum(LL, RR, mid + 1, NodeR, Nodeidx * 2 + 1);// [NodeL,NodeR) �� �ƴ϶� [NodeL,NodeR] �ӿ� ����!
	}
}

signed main() {/*��Ʈ����� ����ȣ�� 0������ �Ѵ�.*/
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