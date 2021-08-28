//2020 �����ͱ��� ���� 2�� ���� �˻� ���α׷� - linked list �̿�
//1914201 �����

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc�� ����

typedef struct NODE {   // ���� ����Ʈ�� ��� ����ü
	struct NODE* next;  // ���� ����� �ּҸ� ������ ������
	int data;      // �����͸� ������ ���
}NODE;

void list_init(struct NODE* head) {  //�ʱ�ȭ
	head->data = NULL;
	head->next = NULL;
}

void addNode(struct NODE* targetnode, int data) {  // ���� ��� �ڿ� �� ��带 �߰��ϴ� �Լ�
	struct NODE* newNode = (NODE*)malloc(sizeof(NODE));  //�� ��带 ������

	newNode->next = targetnode->next;  // newNode ���� ��忡 ���� ����� ���� ��带 ����
	newNode->data = data;    //�����͸� ������

	targetnode->next = newNode;  // ���� ��忡 �� ��带 ������
}


int searchNode(struct NODE* head, int data) {  //���°�� �ִ��� ã��
	struct NODE* curr = head->next;  //��ȸ�� ��� ����
	int check = 1;  //������ 1��° ���ͷ� ����
	while (curr != NULL) {  // ��(NULL)�� �ƴ� �� ��� �ݺ�
		struct NODE* next = curr->next;
		if (data == (curr->data)) {  //���� ����� �����Ϳ� �Ű������� ���� �����Ͱ� ������
			printf("%d��°", check - 1);
		}
		check++;
		curr = next;  //��ã������ �ϳ� ����
	}
	return check;
}

void print_all(struct NODE* head) {  //��ü ���Ḯ��Ʈ ���
	struct NODE* curr = head->next;  // ���� ����Ʈ ��ȸ�� �����Ϳ� ù ��° ����� �ּ� ����
	while (curr != NULL) {   // ��(NULL)�� �ƴ� �� ��� �ݺ�
		printf("%d ", curr->data);   // ���� ����� ������ ���
		curr = curr->next;   // �����Ϳ� ���� ����� �ּ� ����
	}
	printf("\n");
}

void freeNode(struct NODE* head) {
	struct NODE* curr = head->next;  // ��ȸ�� ������, ù ��° ��� �ּ� ����
	curr = head->next;      // �����Ϳ� ���� ����� �ּ� ����
	while (curr != NULL) {  // �����Ͱ� ��(NULL)�� �ƴ� �� ��� �ݺ�
		struct NODE* next = curr->next;  // ���� ����� ���� ��� �ּҸ� �ӽ÷� ����
		free(curr);    // ���� ��� �޸� ����
		curr = next;  // �����Ϳ� ���� ����� �ּ� ����
	}
	free(head);  //�Ӹ� ��� �޸� ����
}


struct NODE* Searchmiddle(NODE* start, NODE* last)  //�߰����� ã�� �Լ�
{
	if (start == NULL)
		return NULL;

	struct NODE* a = start;
	struct NODE* anext = start->next;  //�ռ����� ������

	while (anext != last){  //anext�� ���������� �ƴ� ����
		anext = anext->next; //anext��ĭ �� �̵�
		if (anext != last){     //anext�� ���������� �ƴϸ�
			a = a->next;      //a��ĭ�̵�
			anext = anext->next;   //anext ��ĭ �� �̵�
		}
	}
	
	return a; //�߰��� ����
}

struct NODE* binarySearch(NODE* head, int value){  //���� Ž���� �ϴ� �Լ� 
	struct NODE* start = head;
	struct NODE* last = NULL;

	while (last == NULL || last != start) {  //������(���ʳ�)�� ����(�Ʒ���)���� ���� �ʰ� ������ ���� ������ ���

		NODE* mid = Searchmiddle(start, last);  // �߰��� ã��

		printf("Ž����\n");
		if (mid == NULL)  //���� mid�� ���������
			return NULL;

		if (mid->data == value) {  // ���� �Է°��� �߰����̸�
			printf("ã�ҽ��ϴ�.\n");
			printf("�ڷᰡ ");
			searchNode(head, value);
			printf("�� �ֽ��ϴ�.\n");

			return mid;
		}

		else if (mid->data < value) {  //���� �߰��� < �Է°��̸�
			start = mid->next;  //�߰����� ���������� ��ĭ�̵��� ���� start�� ����
			printf(" ���� ");
			printf(" �߰���: %d\n", mid->data);
		}

		else {  //���� �Է°� < �߰����̸�
			last = mid;  // last�� mid������ �����Ѵ�. (Searchmiddle���� mid������ Ž���ϹǷ� ��������δ� mid-1�� ������ ����� Ž���ϰ� ��)
			printf(" ���� ");
			printf(" �߰���: %d\n", mid->data);

		}

	}
	// �� ������
	return NULL;
}




int main() {
	int con;

	printf("***2020 �����ͱ��� ���� 2�� ���� Ž�� ���α׷�***\n  2. linked list �̿�");
	printf("\n���� 5���� �����Ͽ� : (1) 3, (2) 96, (3) 15, (4) 66, (5) 99�� ã�� ���ÿ�.\n");
	printf("�ε����� 0���� �����ϸ�, �ܰ躰�� �߰����� Ž���Ͽ� �˷��ݴϴ�.\n");
	printf("���� �Է��ؼ� ã������\n");
	printf("����Ʈ�� �ִ� ���� ã�� �� �ֽ��ϴ�.\n���� ���� ã���� ���� ���ʽÿ�.\n");

	struct NODE* head = (NODE*)malloc(sizeof(NODE));  // �Ӹ� ��� ����
	list_init(head);         //�Ӹ� ��忡�� �����͸� �������� ����

	addNode(head, 99);  //�Ӹ���� �ڿ� �� ��� �߰�
	addNode(head, 96);
	addNode(head, 80);
	addNode(head, 75);
	addNode(head, 73);
	addNode(head, 71);
	addNode(head, 70);
	addNode(head, 69);
	addNode(head, 67);
	addNode(head, 66);
	addNode(head, 59);
	addNode(head, 56);
	addNode(head, 55);
	addNode(head, 51);
	addNode(head, 49);
	addNode(head, 48);
	addNode(head, 43);
	addNode(head, 42);
	addNode(head, 26);
	addNode(head, 24);
	addNode(head, 15);
	addNode(head, 14);
	addNode(head, 12);
	addNode(head, 11);
	addNode(head, 8);
	addNode(head, 7);
	addNode(head, 6);
	addNode(head, 5);
	addNode(head, 3);
	addNode(head, 1);


	print_all(head); //���


	int value;

	while (1)
	{
		printf("*******�����˻����α׷� (Linked list) *******\n");
		printf("����Ϸ��� 1, ���α׷��� �������� 0\n");
		scanf("%d", &con);// ���α׷� ���� ���� �Է� 
		if (con == 0)//0�� �Է� 
		{
			break;//�ݺ��� Ż��
		}
		printf("ã�� ���� ���� �Է��ϼ���:");
		scanf("%d", &value);
		binarySearch(head, value); //����Ž��
	}
	freeNode(head);  //�Ӹ� ��� �޸� ����


	return 0;
}