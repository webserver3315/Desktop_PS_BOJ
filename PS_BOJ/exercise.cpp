#include <stdio.h>
#include <stdlib.h>

typedef struct __bnode {
	int data;
	struct __bnode* left;/*왼쪽자식노드 포인터*/
	struct __bnode* right;/*오른자식노드 포인터*/
	/*부모노드를 가리키는 포인터는 따로 없네?*/
}BinNode;

/*선형리스트나 해시법과 달리, 빈테이블이나 빈리스트를 만드는 Initialize함수가 없다.
왜냐하면 루트노드를 가리키는 BinNode형 객체를 하나 준비하고 널값만 대입하면 되기 때문이다.
그렇기에 대신, 루트노드를 가리키는 포인터는 이진검색트리를 사용하는 main함수에서 미리 선언해놔야 한다.*/

/*검색*/
BinNode* Search(BinNode* p, const int* x);

/*노드삽입*/
BinNode* Add(BinNode* p, const int* x);

/*노드삭제*/
int Remove(BinNode** root, const int* x);

/*모든노드 출력*/
void PrintTree(const BinNode* p);

/*모든노드를 삭제*/
void FreeTree(BinNode* p);

static BinNode* AllocBinNode() {
	return calloc(1, sizeof(BinNode));
}

static void SetBinNode(BinNode* n, const int* x, const BinNode* left, const BinNode* right) {
	n->data = *x;
	n->left = left;
	n->right = right;
}

BinNode* search(BinNode* p, const int* x) {
	int cond;
	if (p == NULL)
		return NULL;
	else if ((cond = MemberNoCmp(x, &p->data)) == 0)
		return p;
	else if (cond < 0)/*비교함수 리턴값이 음수일 때 == 삽입할 키값이 선택한 노드의 키값보다 더 작을 때*/
		Search(p->left, x);/*좌서브트리로 가야함을 재귀로 표현*/
	else
		Search(p->right, x);/*우서브트리행*/
	/*while문을 써서 끝까지 내려가는게 아니라, 재귀문으로 끝까지 선택선택해가며 내려가는 것을 구현한 것에 주목*/
}

BinNode* Add(BinNode* p, const int* x) {
	int cond;
	if (p == NULL) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if ((cond = MemberNoCmp(x, &p->data)) == 0) {/* &p->data == &(p->data) */
		printf("오류, %d는 이미 등록되어있습니다\n", x->no);/*중복요소를 허용하지 않는 이진검색트리의 특징*/
	}
	else if (cond < 0)/*비교함수 리턴값이 음수일 때 == 삽입할 키값이 선택한 노드의 키값보다 더 작을 때*/
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;/*이 문장의 유무에 따라 구름IDE gcc컴파일러 경고문이 생성된다. 없으면 p 메모리누수 우려를 띄우는데, 리턴문 있어도 똑같이 띄워야 정상아닌가?*/
}

/*삭제는 좀 복잡하다.
세 가지 서로 다른 상황을 염두에 둬야 하는데,
1. 자식노드가 없는 노드를 삭제할 경우
-그냥 삭제한다. 부모포인터가 자신을 가리킬텐데, 그걸 NULL 가리키도록 뒤처리까지 하면 완벽.
2. 자식노드가 1개인 노드를 삭제할 경우
- 0-0-0식일텐데, 가운데 것이 빠지는 것이므로, 그리고 이진검색트리 특징이 우서브트리는 반드시 모든 원소가 부모보다 커야하므로 딱히 고려해야할 것 없다. 그냥 연결리스트 삭제마냥 자신 빼고 자신의 부모, 자신의 자식을 이어주면 된다.
3. 자식노드가 2개인 노드를 삭제할 경우(즉, 완전히 허리부분인 경우)
->앞의 두 케이스보다 조금 더 복잡하다.
삭제할 노드의 좌서브트리에서 최대값을 가지는 노드를 검색하여, 삭제된 노드의 위치로 옮긴다
>>>이 때, 옮긴 노드는 원래위치로부터 "삭제"되어야하므로, 옮겨진 노드의 구 위치의 자식노드가 있느냐 1개냐에 따라 갈라진다. 즉, 자식없는노드삭제 또는 자식노드1개인 노드 삭제 알고리즘이 재귀적으로 호출된다.
*/
int Remove(BinNode** root, const int* x) {/*이중포인터로 루트노드를 받는 이유: 루트노드를 삭제하는 경우 루트노드 포인터를 NULL 로 업데이트해야하기 때문*/
	BinNode* next;
	BinNode* temp;
	/*BinNode *next, *temp;*/
	// != BinNode* next, temp;
	BinNode** left;
	BinNode** p = root;

	while (1) {/*삭제하고자 하는 노드를 찾을 때까지 while문으로 검색한다.
	근데 Search 함수를 사용해도 되지않나? 그 편이 애초에 재귀적으로 구현되어있기도 하고 더 깔끔한듯한데*/
		int cond;
		if (*p == NULL) {
			printf("오류 : %d 는 등록되어있지 않습니다\n", x->no);
			return -1;
		}
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break; /*검색성공*/
		else if (cond < 0)
			p = &((*p)->left); /*왼쪽 서브트리에서 검색*/
		else
			p = &((*p)->right); /*오른쪽 서브트리에서 검색 */
	}

	/* *p는 일반적인 함수의 그냥 p로 봐도 무방하다. 수정여지 때문에 이중포인터로 선언한 것일 뿐이니까*/
	if ((*p)->left == NULL)/*왼노드가 없다면?*/
		next = (*p)->right;/*오른노드를 그대로 당겨오기*/
	else {/*왼노드가 있다면*/
		left = &((*p)->left);/*왼서브트리로 이동 후*/
		while ((*left)->right != NULL)/*좌서브트리의 최댓값을 찾기 위해, 최대한 우로 간다*/
			left = &(*left)->right;/*좌서브트리 우측끝을 만날 때까지 계속 우로간다.*/
		next = *left;/* *left는 곧바로 아래단에서 덮어쓰기될 것이기에 next에 세자 값을 보존하는 것이다
		여기서 left는 최초의 left가 아니라, 좌서브트리 우측끝까지 가버린 노드값임에 유의.
		next가 담고있는 BinNode의 주소값이 이중포인터left가 1차적으로 가리키는 곳이 담고있는 주소값 덮어쓰기되는 것인데, 조금 심오하다. 복습필수.*/
		*left = (*left)->left;/*세자의 자리를 세자 좌노드로 채워주고*/
		next->left = (*p)->left;/*next가 구 *p 의 pointer to leftBNode를 인수인계받음*/
		next->right = (*p)->right;/*RightBNode도 마저 인수인계*/
	}
	temp = *p;/*곧 삭제될 p입니다*/
	*p = next;/*p 자리는 next가 채웠으니 안심하라구!*/
	free(temp);

	return 0;
}

void PrintTree(const BinNode* p) {/*모든 노드를 오름차순으로 출력하는 함수. 오름차순으로 출력하기 위해 중위순회를 쓴다*/
	/*그럼 내림차순은 어떤순회지? 전위, 중위, 후위도 아닌 역중위순회인가? 오른자식->노드방문->왼자식 순의.*/
	if (p != NULL) {/*중위순회를 재귀적으로 구현함*/
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

void FreeTree(BinNode* p) {/*후위순회 방법으로 트리를 검색하며, 삭제를 진행한다*/
	/*혹시 재귀식으로 구현한 코드에서 free(p)나 위의 PrintLnMember() 같은 효력부가 어디에 있느냐에 따라 전위냐 중위냐 후위냐의 이름이 붙은건가?*/
	if (p != NULL) {/*당연하겠지만, 부모노드부터 프리시키면 자식으로 가는 다리가 불태워지므로 자식부터 프리시켜야만 한다! 아니면 누수 발생한다!*/
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}

int main() {


	return 0;
}