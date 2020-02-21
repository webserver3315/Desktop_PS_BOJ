/*
구간 합 구하기
>>>세그먼트 트리 문제
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

struct SegTree {
	vector<int> tree;
	int size;//tree 벡터의 크기
	SegTree(int a) {
		size = 1;//일단 벡터 기본크기는 1이고
		while (size < a)//작다면 계속 2배
			size <<= 1;
		tree.resize(size * 2 + 2);//거기서 자식도 있어야 하니까 좌, 우자식용 2마리 더 미리 할당
		size--;//왜 있는지 솔직히 잘 모르겠음.
	}
	void update(int idx, int val) {
		idx += size;
		tree[idx] = val;
		while (idx > 0) {
			idx >>= 1;
			tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
		}
	}
	/*void update2(int idx, int val) {
		idx += size;//size엔 leaf depth는 포함안되어있으므로 단순히 size+idx하면 해당 색인이 나온다.
		tree[idx] = val;
		idx >>= 1;//부모노드로 이동
		while (idx > 0) {//여기서, root 노드는 1이다. 따라서 등호는 넣지 않았다.
			tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);//자식중에 큰걸 부모에 대입한다는 발상인데, 이건 적어도 내 사고와 맞지 않으므로 1 버전으로 리메이크한다.
			idx >>= 1;//부모노드로 이동
		}
	}*/
	int sum(int L, int R, int NodeL, int NodeR, int nowidx) {//최종시작, 최종끝, 현재노드시작, 현재노드끝, 현재노드번호
		if (L > NodeR || R < NodeL)
			return 0;
		/*if (L <= NodeL && R >= NodeR)
			return 0;*/
		if (L <= NodeL && NodeR <= R)
			return tree[nowidx];
		int mid = (NodeL + NodeR) >> 1;//==nodeL+nodeR/2
		return sum(L, R, NodeL, mid, nowidx * 2) + sum(L, R, mid+1, NodeR, nowidx * 2 + 1);
	}
	/*int sum2(int st, int fn, int ns = 1, int nf = -1, int num = 1) {//구하고자하는 시작, 끝, 현재 노드가 담당하는 구간의 시작, 끝, 현재 보는 노드의 번호
		if (nf == -1)//끝까지 구하고 싶을 때 nf 인자로 -1을 넣자는걸로 추정한다.
			nf = size + 1;
		if (nf<st || ns>fn)//겹치지 않을 때
			return 0;
		if (st <= ns && nf <= fn)//완전히 겹칠 때
			return tree[num];//노드값 반환
		int mid = (ns + nf) >> 1;//그 외: 일부만 겹칠 때
		return max(query(st, fn, ns, mid, num * 2), query(st, fn, mid+1, nf, num * 2 + 1));//재귀로 구현ㄱㄴ
	}*/
};

int main() {


	return 0;
}