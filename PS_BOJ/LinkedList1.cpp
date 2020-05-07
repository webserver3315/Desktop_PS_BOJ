#include <iostream>
#include <algorithm>
//#include <list>

using namespace std;
#define endl '\n'

const int NODE_SIZE = (int)3e5;
const int PUSH_BACK = 0;
const int PUSH_FRONT = 1;
const int INSERT = 2;
const int POP_BACK = 3;
const int POP_FRONT = 4;
const int ERASE = 5;

int test_cmd[NODE_SIZE][3];

struct NODE {
	int prev;
	int next;
	int val;
};

struct MY_LIST {
	int HEAD = NODE_SIZE;
	int TAIL = NODE_SIZE + 1;
	int pos;
	NODE node[NODE_SIZE + 2];
	
	MY_LIST() {
		pos = 0;//BACK�� ���� �� �ڷᰡ �� �ε���
		node[HEAD].next = TAIL;
		node[TAIL].prev = HEAD;
	}

	void my_push_back(int data) {
		int BEFOREprev = node[TAIL].prev;

		node[pos].val = data;//���� �������� POS�� �� �ֱ�(==BACK)
		node[pos].prev = BEFOREprev;//���� ���Ĺ��尡 ���� BACK�� Ǫ�õ� ����� PREV ��尡 �ȴ�.
		node[pos].next = TAIL;

		node[BEFOREprev].next = pos;//
		node[TAIL].prev = pos;
		pos++;
		//�̰� �����־�δ�. ����Ʈ ���� ����� �ص� ����Ʈ�� ������ �޸� ���Ἲ�� ���� ���Ἲ�� ��ġ�Ѵٰ� ����� ���� �� �� �����Ƿ�, �� �� �Ϲ�ȭ���Ѿ��Ѵ�.
	}

	void push_back(int data) {
		int prev = node[TAIL].prev;
		int next = node[prev].next;//�׳� TAIL�� �����ϴ�.

		node[pos].val = data;
		node[pos].prev = prev;
		node[pos].next = next;

		node[prev].next = pos;
		node[next].prev = pos;
		pos++;
	}
	void push_front(int data) {
		int next = node[HEAD].next;
		int prev = node[next].prev;//HEAD

		node[pos].val = data;
		node[pos].prev = prev;
		node[pos].next = next;

		node[prev].next = pos;
		node[next].prev = pos;
		pos++;
	}
	void insert(int p, int data) {
		int next = node[HEAD].next;
		for (int i = 0; i < p; i++) {
			next = node[next].next;
		}
		int prev = node[next].next;
	}
	void pop_back() {

	}
	void pop_front() {

	}
	void erase(int p) {

	}
};

MY_LIST my_list;

int main() {
	
	int cur_size = 0;
	
	for (int i = 0; i < NODE_SIZE; i++) {
		if (i < NODE_SIZE / 3) {
			test_cmd[i][0] = rand() % 2;
		}
		else {
			test_cmd[i][0] = rand() % 6;
		}

		switch (test_cmd[i][0]) {
		case PUSH_BACK:
		case PUSH_FRONT: {
			test_cmd[i][1] = rand();
			cur_size++;
			break;
		}
		case INSERT: {
			test_cmd[i][1] = rand() % cur_size;
			test_cmd[i][2] = rand();
			cur_size++;
			break;
		}
		case POP_BACK:
		case POP_FRONT: {
			cur_size--;
			break;
		}
		case ERASE: {
			test_cmd[i][1] = rand() % cur_size;
			cur_size--;
			break;
		}
		}
	}

	return 0;
}