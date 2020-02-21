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
	NODE node[NODE_SIZE + 2];//const int 로 선언했으므로 배열크기로 사용가능

	MY_LIST() {
		pos = 0;
		node[HEAD].next = TAIL;
		node[TAIL].prev = HEAD;
	}

	void push_back(int data) {
		int next = TAIL;
		int prev = node[TAIL].prev;
		node[pos].val = data;
		node[pos].next = next;
		node[pos].prev = prev;
		node[prev].next = pos;
		node[next].prev = pos;
		pos++;
	}
	void push_front(int data) {
		int next = node[HEAD].next;
		int prev = HEAD;
		node[pos].val = data;
		node[pos].next = next;
		node[pos].prev = prev;
		node[prev].next = pos;
		node[next].prev = pos;
		pos++;
	}
	void insert(int p, int data) {
		for (int i = 0; i < p;; i++) {

		}
	}

};

int main() {



}