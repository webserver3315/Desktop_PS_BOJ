#define MAX_NODE (int)1e5
#define MAX (int)3e4

struct Node{
	int val;
	Node* next;
} nodes[MAX_NODE];

struct Bucket {
	int count;
	Node* tail;
} HashTable[MAX];

int ndidx = 0;

Node* newNode() {
	return &nodes[ndidx++];
}

int get_key(int val) {
	return val % MAX;
}

void add(int val) {
	int key = get_key(val);
	Node* node = newNode();
	node->val = val;
	if (HashTable[key].count != 0) {
		node->next = HashTable[key].tail;
	}
	HashTable[key].tail = node;
	HashTable[key].count++;
}

Node* find(int val) {
	int key = get_key(val);
	Node* node = HashTable[key].tail;
	while (node) {
		if (node->val == val) {
			return node;
		}
		node = node->next;
	}
	return 0;
}

void del(int val) {
	int key = get_key(val);
	Node* node = HashTable[key].tail;


}