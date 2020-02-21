#define MAX_NODE 100000
#define MAX 30000

//1. 노드 준비
struct Node {
	int val;
	Node* next;
} 
//미리 노드 생성
Node nodes[MAX_NODE];
int ndidx = 0;
Node* newNode() {
	return &nodes[ndidx++];
}

//버켓 생성
struct Bucket {
	int count;
	Node* tail;
}
Bucket HashTable[MAX];

int get_key(int val) {
	return val % MAX;
}

void add(int val) {
	int key = get_key(val);
	//노드 초기화
	Node* node = newNode();
	node->val = val;
	//노드 달기
	if (HashTable[key].count != 0)
		node->next = HashTable[key].tail;
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
	int key = get_key(key);
	Node* node = HashTable[key].tail;
	Node* prev = 0;
	if (node == 0) return;

	if (node->val == val) {
		HashTable[key].tail = node->next;
		HashTable[key].count--;
		return;
	}
	while (node) {
		if (node->val == val) {
			prev->next = node->next;
			HashTable[key].count--;
			return;
		}
		prev = node;
		node = node->next;
	}
}

