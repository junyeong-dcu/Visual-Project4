#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;                    // ���� ���(element)�� �ڷ����� char�� ����

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

// ������ ��ȣ�� �˻��ϴ� ����
int testPair(char* exp) {
	char symbol, open_pair;
	// char�� ������ �Ű������� ���� ���� exp�� ���̸� ����Ͽ� length ������ ����
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++) {
		symbol = exp[i];
		switch (symbol) {
			// (1) ���� ��ȣ�� ���ÿ� ����
		case '(':
		case '[':
		case '{':
			push(symbol); break;
			// (2) ������ ��ȣ�� ������,
		case ')':
		case ']':
		case '}':
			if (top == NULL)return 0;
			else {
				// (2)-1 ���ÿ��� ���������� ���� ��ȣ�� ����
				open_pair = pop();
				// (2)-2 ��ȣ ���� �´��� �˻�
				if ((open_pair == '(' && symbol != ')')
					(open_pair == '[' && symbol != ']')
					(open_pair == '{' && symbol != '}'))
					// (2)-3 ��ȣ ���� Ʋ���� ���� ����
					return 0;
				// (2)-4 ��ȣ ���� ������ ���� symbol �˻縦 �����
				else break;
			}
		}
	}
	if (top == NULL)return 1; // ���� �˻縦 ��ģ �� ������ �����̸� 1�� ��ȯ
	else return 0;            // ������ �ƴϸ� 0�� ��ȯ(���� ��ȣ Ʋ��)
}

void main(void) {
	char* express = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
	printf("%s", express);

	if (testPair(express) == 1)
		printf("\n\n������ ��ȣ�� �°� ���Ǿ����ϴ�!");
	else
		printf("\n\n������ ��ȣ�� Ʋ�Ƚ��ϴ�!")

		getchar();
}