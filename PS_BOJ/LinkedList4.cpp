#include <iostream>
using namespace std;

const int NODE_SIZE = (int)3e5;
const int PUSH_BACK = 0;
const int PUSH_FRONT = 1;
const int INSERT = 2;
const int POP_BACK = 3;
const int POP_FRONT = 4;
const int ERASE = 5;

struct NODE {
	int val;
	int prev;
	int next;
};

struct MY_LIST {
	int pos;
	int HEAD = NODE_SIZE;
	int TAIL = NODE_SIZE + 1;
	NODE node[NODE_SIZE + 2];

	MY_LIST() {
		pos = 0;
		node[HEAD].next = TAIL;
		node[TAIL].prev = HEAD;
	}

	void push_back(int data) {
		int prev = node[TAIL].prev;
		int next = TAIL;

		node[pos].val = data;
		node[pos].next = next;
		node[pos].prev = prev;
		node[next].prev = pos;
		node[prev].next = pos;
		pos++;
	}
	void pop_back() {

	}
	void erase(int p) {

	}
};

int main() {


	return 0;
}