/*
PersistentSegmentTree 연습
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

	pst(int a, int b, int rn) {//a: SegTree의 leaf level 의 노드개수, b: update 연산 횟수, rn: 루트의 개수
		base = height = t = 1;//이렇게도 선언가능하다! 우에서 좌로 연쇄적으로 대입된다.
		while (base < a)
			height++, base = base << 1;//후위연산자랑 시프트같은경우 딱히 리턴값이 필요한게 아니기에 콤마로 한줄처리가 가능하다.
		int tmp = base * 2 + 2 + height * b + 5;
		tree.resize(tmp);
		left.resize(tmp);
		right.resize(tmp);
		root.resize(tmp);
		root[0] = setup(1, base);
	}

	int setup(int ns, int nf) {//재귀적으로 FBT를 반들어준다(Full Binary Tree)
		int k = t++;
		tree[k] = 0;
		if (ns < nf) {
			int mid = (ns + nf) >> 1;
			left[k] = setup(ns, mid);
			right[k] = setup(mid + 1, nf);
		}
		return k;
	}

	void update_Kth_tree(int k, int idx, int val) {//k번째 업데이트 히스토리에서 idx를 val로 바꾼다.
		if (root[k] == 0)
			root[k] = root[k - 1];
		root[k] = make(root[k], idx, val);
	}

	int make(int bef, int idx, int val, int ns = 1, int nf = -1) {//실질적인 역전파를 담당하는 함수
		if (nf == -1)
			nf = base;
		if (idx < ns || nf < idx)
			return bef;

		int k = t++;
		if (ns == nf)
			tree[k] = tree[bef] + val;//이전상태에서 val만큼 누적하는 코드이다. 만일, val로 단순히 값을 바꾸고 싶다면 tree[k]=val로 바꾸면 된다.
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