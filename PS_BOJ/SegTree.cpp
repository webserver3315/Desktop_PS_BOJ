/*
���� �� ���ϱ�
>>>���׸�Ʈ Ʈ�� ����
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

struct SegTree {
	vector<int> tree;
	int size;//tree ������ ũ��
	SegTree(int a) {
		size = 1;//�ϴ� ���� �⺻ũ��� 1�̰�
		while (size < a)//�۴ٸ� ��� 2��
			size <<= 1;
		tree.resize(size * 2 + 2);//�ű⼭ �ڽĵ� �־�� �ϴϱ� ��, ���ڽĿ� 2���� �� �̸� �Ҵ�
		size--;//�� �ִ��� ������ �� �𸣰���.
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
		idx += size;//size�� leaf depth�� ���ԾȵǾ������Ƿ� �ܼ��� size+idx�ϸ� �ش� ������ ���´�.
		tree[idx] = val;
		idx >>= 1;//�θ���� �̵�
		while (idx > 0) {//���⼭, root ���� 1�̴�. ���� ��ȣ�� ���� �ʾҴ�.
			tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);//�ڽ��߿� ū�� �θ� �����Ѵٴ� �߻��ε�, �̰� ��� �� ���� ���� �����Ƿ� 1 �������� ������ũ�Ѵ�.
			idx >>= 1;//�θ���� �̵�
		}
	}*/
	int sum(int L, int R, int NodeL, int NodeR, int nowidx) {//��������, ������, ���������, �����峡, �������ȣ
		if (L > NodeR || R < NodeL)
			return 0;
		/*if (L <= NodeL && R >= NodeR)
			return 0;*/
		if (L <= NodeL && NodeR <= R)
			return tree[nowidx];
		int mid = (NodeL + NodeR) >> 1;//==nodeL+nodeR/2
		return sum(L, R, NodeL, mid, nowidx * 2) + sum(L, R, mid+1, NodeR, nowidx * 2 + 1);
	}
	/*int sum2(int st, int fn, int ns = 1, int nf = -1, int num = 1) {//���ϰ����ϴ� ����, ��, ���� ��尡 ����ϴ� ������ ����, ��, ���� ���� ����� ��ȣ
		if (nf == -1)//������ ���ϰ� ���� �� nf ���ڷ� -1�� ���ڴ°ɷ� �����Ѵ�.
			nf = size + 1;
		if (nf<st || ns>fn)//��ġ�� ���� ��
			return 0;
		if (st <= ns && nf <= fn)//������ ��ĥ ��
			return tree[num];//��尪 ��ȯ
		int mid = (ns + nf) >> 1;//�� ��: �Ϻθ� ��ĥ ��
		return max(query(st, fn, ns, mid, num * 2), query(st, fn, mid+1, nf, num * 2 + 1));//��ͷ� ��������
	}*/
};

int main() {


	return 0;
}