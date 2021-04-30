#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int element;                       // ���� ����(element)�� �ڷ����� int�� ����

typedef struct stackNode {               // ������ ��带 ����ü�� ����
	element data;
	struct stackNode* link;
} stackNode;

stackNode* top;                        // ������ top ��带 �����ϱ� ���� ������ top ����

//������ ���� �������� Ȯ���ϴ� ����
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// ������ top�� ���Ҹ� �����ϴ� ���� 
void push(element item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;                  //���� ��带 top�� ���� ����
	top = temp;                        //top ��ġ�� ���� ���� �̵�
}

// ������ top���� ���Ҹ� �����ϴ� ����
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {                 // ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {                            // ������ ���� ����Ʈ�� �ƴ� ���
		item = temp->data;
		top = temp->link;               // top ��ġ�� ���� ��� �Ʒ��� �̵�
		free(temp);                     // ������ ����� �޸� ��ȯ
		return item;                    // ������ ���� ��ȯ
	}
}

// ������ top ���Ҹ� �˻��ϴ� ����
element peek() {
	if (top == NULL) {              // ������ ���� ����Ʈ�� ���
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {                          // ������ ���� ����Ʈ�� �ƴ� ���
		return(top->data);          //  ���� top�� ���� ��ȯ
	}
}

 // ������ ���Ҹ� top���� bottom ������ ����ϴ� ����
void printStack() {
	stackNode* p = top;
	printf("\n STACK [ ");
	while (p) {
		printf("%d", p->data);
			p = p->link;
	}
	printf("]");
}

void main(void) {
	element item;
	top = NULL;
	printf("\n** ���� ���� ���� **\n");
	printStack();
	push(1); printStack();     // 1 ����
	push(2); printStack();     // 2 ����
	push(3); printStack();     // 3 ����

	item = peek(); printStack(); // ���� top�� ���� ���
	printf("peek => %d", item);

	item = pop(); printStack(); //����
	printf("\nt pop => %d", item);

	item = pop(); printStack(); //����
	printf("\nt pop => %d", item);

	item = pop(); printStack(); //����
	printf("\nt pop => %d", item);

	getchar();
}
