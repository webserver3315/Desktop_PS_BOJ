#include <stdio.h>
#include <stdlib.h>


//rear�� �ְ�, front���� ����. rear=�� �� ������ �ּ�, front=���� ���� �ּ�
int front, rear;
int maxsize = 6;//5���� �ֱ� ����, �ִ�ũ�� 6���� �����ؾ߸� empty�� full ���¸� ���а����ϰ� �ȴ�.
int queue[6];
int size;

void printstatus() {
	printf("front: %d, rear: %d\n", front, rear);
	printf("queue: ");
	for (int i = 0; i < 6; i++) {
		printf("%d, ", queue[i]);
	}
	printf("\n");
}

int IsEmpty() {
	if (rear == front || size <= 0) return 1;
	else return 0;
}

int IsFull() {
	if ((rear + 1) % maxsize == front || size >= maxsize) return 1;
	else return 0;
}

void enqueue(int val) {
	if (IsFull()) {
		printf("queue full\n");
		//printstatus();
	}
	else {
		rear = (rear + 1) % maxsize;
		queue[rear] = val;
		size++;
		printf("%d input\n", val);
		//printstatus();
	}
}

void dequeue() {
	if (IsEmpty()) {
		printf("queue empty\n");
		//printstatus();
	}
	else {
		front = (front + 1) % maxsize;		
		printf("%d output\n", queue[front]);
		//printstatus();
		size--;
	}
}

int main(void){
	rear = -1; front = -1; size = 0;
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	printf("\n");

	rear = -1; front = -1; size = 0;
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	printf("\n");

	rear = -1; front = -1; size = 0;
	enqueue(1);
	enqueue(2);
	enqueue(3);
	dequeue();
	dequeue();
	dequeue();
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();

	return 0;
}

