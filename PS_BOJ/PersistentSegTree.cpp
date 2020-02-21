/*
PersistentSegmentTree ����
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

struct pst {
	vector<int> tree, left, right;
	vector<int> root;
	int height, t, base;

	pst(int a, int b, int rn) {//a: SegTree�� leaf level �� ��尳��, b: update ���� Ƚ��, rn: ��Ʈ�� ����
		base = height = t = 1;//�̷��Ե� ���𰡴��ϴ�! �쿡�� �·� ���������� ���Եȴ�.
		while (base < a)
			height++, base = base << 1;//���������ڶ� ����Ʈ������� ���� ���ϰ��� �ʿ��Ѱ� �ƴϱ⿡ �޸��� ����ó���� �����ϴ�.
		int tmp = base * 2 + 2 + height * b + 5;
		tree.resize(tmp);
		left.resize(tmp);
		right.resize(tmp);
		root.resize(tmp);
		root[0] = setup(1, base);
	}

	int setup(int ns, int nf) {//��������� FBT�� �ݵ���ش�(Full Binary Tree)
		int k = t++;
		tree[k] = 0;
		if (ns < nf) {
			int mid = (ns + nf) >> 1;
			left[k] = setup(ns, mid);
			right[k] = setup(mid + 1, nf);
		}
		return k;
	}

	void update_Kth_tree(int k, int idx, int val) {//k��° ������Ʈ �����丮���� idx�� val�� �ٲ۴�.
		if (root[k] == 0)
			root[k] = root[k - 1];
		root[k] = make(root[k], idx, val);
	}

	int make(int bef, int idx, int val, int ns = 1, int nf = -1) {//�������� �����ĸ� ����ϴ� �Լ�
		if (nf == -1)
			nf = base;
		if (idx < ns || nf < idx)
			return bef;

		int k = t++;
		if (ns == nf)
			tree[k] = tree[bef] + val;//�������¿��� val��ŭ �����ϴ� �ڵ��̴�. ����, val�� �ܼ��� ���� �ٲٰ� �ʹٸ� tree[k]=val�� �ٲٸ� �ȴ�.
		else {
			int mid = (ns + nf) >> 1;
			left[k] = make(left[bef], idx, val, ns, mid);
			right[k] = make(right[bef], idx, val, mid + 1, nf);
			tree[k] = tree[left[k]] + tree[right[k]];
		}
		return k;
	}

	int get_sum(int num, int st, int fn, int ns = 1, int nf = -1) {
		if (nf == -1)
			nf = base;
		if (fn < ns || nf < st)
			return 0;
		if (st <= ns && nf <= fn)
			return tree[num];
		int mid = (ns + nf) >> 1;
		return get_sum(left[num], st, fn, ns, mid) + get_sum(right[num], st, fn, mid + 1, nf);
	}
};

int main() {

}