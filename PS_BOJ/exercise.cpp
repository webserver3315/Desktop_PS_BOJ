#include <stdio.h>
#include <stdlib.h>

typedef struct __bnode {
	int data;
	struct __bnode* left;/*�����ڽĳ�� ������*/
	struct __bnode* right;/*�����ڽĳ�� ������*/
	/*�θ��带 ����Ű�� �����ʹ� ���� ����?*/
}BinNode;

/*��������Ʈ�� �ؽù��� �޸�, �����̺��̳� �󸮽�Ʈ�� ����� Initialize�Լ��� ����.
�ֳ��ϸ� ��Ʈ��带 ����Ű�� BinNode�� ��ü�� �ϳ� �غ��ϰ� �ΰ��� �����ϸ� �Ǳ� �����̴�.
�׷��⿡ ���, ��Ʈ��带 ����Ű�� �����ʹ� �����˻�Ʈ���� ����ϴ� main�Լ����� �̸� �����س��� �Ѵ�.*/

/*�˻�*/
BinNode* Search(BinNode* p, const int* x);

/*������*/
BinNode* Add(BinNode* p, const int* x);

/*������*/
int Remove(BinNode** root, const int* x);

/*����� ���*/
void PrintTree(const BinNode* p);

/*����带 ����*/
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
	else if (cond < 0)/*���Լ� ���ϰ��� ������ �� == ������ Ű���� ������ ����� Ű������ �� ���� ��*/
		Search(p->left, x);/*�¼���Ʈ���� �������� ��ͷ� ǥ��*/
	else
		Search(p->right, x);/*�켭��Ʈ����*/
	/*while���� �Ἥ ������ �������°� �ƴ϶�, ��͹����� ������ ���ü����ذ��� �������� ���� ������ �Ϳ� �ָ�*/
}

BinNode* Add(BinNode* p, const int* x) {
	int cond;
	if (p == NULL) {
		p = AllocBinNode();
		SetBinNode(p, x, NULL, NULL);
	}
	else if ((cond = MemberNoCmp(x, &p->data)) == 0) {/* &p->data == &(p->data) */
		printf("����, %d�� �̹� ��ϵǾ��ֽ��ϴ�\n", x->no);/*�ߺ���Ҹ� ������� �ʴ� �����˻�Ʈ���� Ư¡*/
	}
	else if (cond < 0)/*���Լ� ���ϰ��� ������ �� == ������ Ű���� ������ ����� Ű������ �� ���� ��*/
		p->left = Add(p->left, x);
	else
		p->right = Add(p->right, x);
	return p;/*�� ������ ������ ���� ����IDE gcc�����Ϸ� ����� �����ȴ�. ������ p �޸𸮴��� ����� ���µ�, ���Ϲ� �־ �Ȱ��� ����� ����ƴѰ�?*/
}

/*������ �� �����ϴ�.
�� ���� ���� �ٸ� ��Ȳ�� ���ο� �־� �ϴµ�,
1. �ڽĳ�尡 ���� ��带 ������ ���
-�׳� �����Ѵ�. �θ������Ͱ� �ڽ��� ����ų�ٵ�, �װ� NULL ����Ű���� ��ó������ �ϸ� �Ϻ�.
2. �ڽĳ�尡 1���� ��带 ������ ���
- 0-0-0�����ٵ�, ��� ���� ������ ���̹Ƿ�, �׸��� �����˻�Ʈ�� Ư¡�� �켭��Ʈ���� �ݵ�� ��� ���Ұ� �θ𺸴� Ŀ���ϹǷ� ���� ����ؾ��� �� ����. �׳� ���Ḯ��Ʈ �������� �ڽ� ���� �ڽ��� �θ�, �ڽ��� �ڽ��� �̾��ָ� �ȴ�.
3. �ڽĳ�尡 2���� ��带 ������ ���(��, ������ �㸮�κ��� ���)
->���� �� ���̽����� ���� �� �����ϴ�.
������ ����� �¼���Ʈ������ �ִ밪�� ������ ��带 �˻��Ͽ�, ������ ����� ��ġ�� �ű��
>>>�� ��, �ű� ���� ������ġ�κ��� "����"�Ǿ���ϹǷ�, �Ű��� ����� �� ��ġ�� �ڽĳ�尡 �ִ��� 1���Ŀ� ���� ��������. ��, �ڽľ��³����� �Ǵ� �ڽĳ��1���� ��� ���� �˰����� ��������� ȣ��ȴ�.
*/
int Remove(BinNode** root, const int* x) {/*���������ͷ� ��Ʈ��带 �޴� ����: ��Ʈ��带 �����ϴ� ��� ��Ʈ��� �����͸� NULL �� ������Ʈ�ؾ��ϱ� ����*/
	BinNode* next;
	BinNode* temp;
	/*BinNode *next, *temp;*/
	// != BinNode* next, temp;
	BinNode** left;
	BinNode** p = root;

	while (1) {/*�����ϰ��� �ϴ� ��带 ã�� ������ while������ �˻��Ѵ�.
	�ٵ� Search �Լ��� ����ص� �����ʳ�? �� ���� ���ʿ� ��������� �����Ǿ��ֱ⵵ �ϰ� �� ����ѵ��ѵ�*/
		int cond;
		if (*p == NULL) {
			printf("���� : %d �� ��ϵǾ����� �ʽ��ϴ�\n", x->no);
			return -1;
		}
		else if ((cond = MemberNoCmp(x, &(*p)->data)) == 0)
			break; /*�˻�����*/
		else if (cond < 0)
			p = &((*p)->left); /*���� ����Ʈ������ �˻�*/
		else
			p = &((*p)->right); /*������ ����Ʈ������ �˻� */
	}

	/* *p�� �Ϲ����� �Լ��� �׳� p�� ���� �����ϴ�. �������� ������ ���������ͷ� ������ ���� ���̴ϱ�*/
	if ((*p)->left == NULL)/*�޳�尡 ���ٸ�?*/
		next = (*p)->right;/*������带 �״�� ��ܿ���*/
	else {/*�޳�尡 �ִٸ�*/
		left = &((*p)->left);/*�޼���Ʈ���� �̵� ��*/
		while ((*left)->right != NULL)/*�¼���Ʈ���� �ִ��� ã�� ����, �ִ��� ��� ����*/
			left = &(*left)->right;/*�¼���Ʈ�� �������� ���� ������ ��� ��ΰ���.*/
		next = *left;/* *left�� ��ٷ� �Ʒ��ܿ��� ������ ���̱⿡ next�� ���� ���� �����ϴ� ���̴�
		���⼭ left�� ������ left�� �ƴ϶�, �¼���Ʈ�� ���������� ������ ��尪�ӿ� ����.
		next�� ����ִ� BinNode�� �ּҰ��� ����������left�� 1�������� ����Ű�� ���� ����ִ� �ּҰ� �����Ǵ� ���ε�, ���� �ɿ��ϴ�. �����ʼ�.*/
		*left = (*left)->left;/*������ �ڸ��� ���� �³��� ä���ְ�*/
		next->left = (*p)->left;/*next�� �� *p �� pointer to leftBNode�� �μ��ΰ����*/
		next->right = (*p)->right;/*RightBNode�� ���� �μ��ΰ�*/
	}
	temp = *p;/*�� ������ p�Դϴ�*/
	*p = next;/*p �ڸ��� next�� ä������ �Ƚ��϶�!*/
	free(temp);

	return 0;
}

void PrintTree(const BinNode* p) {/*��� ��带 ������������ ����ϴ� �Լ�. ������������ ����ϱ� ���� ������ȸ�� ����*/
	/*�׷� ���������� ���ȸ��? ����, ����, ������ �ƴ� ��������ȸ�ΰ�? �����ڽ�->���湮->���ڽ� ����.*/
	if (p != NULL) {/*������ȸ�� ��������� ������*/
		PrintTree(p->left);
		PrintLnMember(&p->data);
		PrintTree(p->right);
	}
}

void FreeTree(BinNode* p) {/*������ȸ ������� Ʈ���� �˻��ϸ�, ������ �����Ѵ�*/
	/*Ȥ�� ��ͽ����� ������ �ڵ忡�� free(p)�� ���� PrintLnMember() ���� ȿ�ºΰ� ��� �ִ��Ŀ� ���� ������ ������ �������� �̸��� �����ǰ�?*/
	if (p != NULL) {/*�翬�ϰ�����, �θ������ ������Ű�� �ڽ����� ���� �ٸ��� ���¿����Ƿ� �ڽĺ��� �������Ѿ߸� �Ѵ�! �ƴϸ� ���� �߻��Ѵ�!*/
		FreeTree(p->left);
		FreeTree(p->right);
		free(p);
	}
}

int main() {


	return 0;
}