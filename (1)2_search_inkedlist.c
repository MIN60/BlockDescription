//2020 데이터구조 과제 2번 이진 검색 프로그램 - linked list 이용
//1914201 김민정

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> //malloc을 위함

typedef struct NODE {   // 연결 리스트의 노드 구조체
	struct NODE* next;  // 다음 노드의 주소를 저장할 포인터
	int data;      // 데이터를 저장할 멤버
}NODE;

void list_init(struct NODE* head) {  //초기화
	head->data = NULL;
	head->next = NULL;
}

void addNode(struct NODE* targetnode, int data) {  // 기준 노드 뒤에 새 노드를 추가하는 함수
	struct NODE* newNode = (NODE*)malloc(sizeof(NODE));  //새 노드를 생성함

	newNode->next = targetnode->next;  // newNode 다음 노드에 기준 노드의 다음 노드를 지정
	newNode->data = data;    //데이터를 저장함

	targetnode->next = newNode;  // 다음 노드에 새 노드를 지정함
}


int searchNode(struct NODE* head, int data) {  //몇번째에 있는지 찾음
	struct NODE* curr = head->next;  //순회용 노드 생성
	int check = 1;  //순서는 1번째 부터로 설정
	while (curr != NULL) {  // 끝(NULL)이 아닐 때 계속 반복
		struct NODE* next = curr->next;
		if (data == (curr->data)) {  //현재 노드의 데이터와 매개변수로 받은 데이터가 같으면
			printf("%d번째", check - 1);
		}
		check++;
		curr = next;  //못찾았으면 하나 전진
	}
	return check;
}

void print_all(struct NODE* head) {  //전체 연결리스트 출력
	struct NODE* curr = head->next;  // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while (curr != NULL) {   // 끝(NULL)이 아닐 때 계속 반복
		printf("%d ", curr->data);   // 현재 노드의 데이터 출력
		curr = curr->next;   // 포인터에 다음 노드의 주소 저장
	}
	printf("\n");
}

void freeNode(struct NODE* head) {
	struct NODE* curr = head->next;  // 순회용 포인터, 첫 번째 노드 주소 저장
	curr = head->next;      // 포인터에 다음 노드의 주소 저장
	while (curr != NULL) {  // 포인터가 끝(NULL)이 아닐 때 계속 반복
		struct NODE* next = curr->next;  // 현재 노드의 다음 노드 주소를 임시로 저장
		free(curr);    // 현재 노드 메모리 해제
		curr = next;  // 포인터에 다음 노드의 주소 저장
	}
	free(head);  //머리 노드 메모리 해제
}


struct NODE* Searchmiddle(NODE* start, NODE* last)  //중간값을 찾는 함수
{
	if (start == NULL)
		return NULL;

	struct NODE* a = start;
	struct NODE* anext = start->next;  //앞서가는 포인터

	while (anext != last){  //anext가 마지막값이 아닐 동안
		anext = anext->next; //anext한칸 더 이동
		if (anext != last){     //anext가 마지막값이 아니면
			a = a->next;      //a한칸이동
			anext = anext->next;   //anext 한칸 더 이동
		}
	}
	
	return a; //중간값 리턴
}

struct NODE* binarySearch(NODE* head, int value){  //이진 탐색을 하는 함수 
	struct NODE* start = head;
	struct NODE* last = NULL;

	while (last == NULL || last != start) {  //오른쪽(위쪽끝)과 왼쪽(아래쪽)끝이 같지 않고 오른쪽 값이 존재할 경우

		NODE* mid = Searchmiddle(start, last);  // 중간값 찾기

		printf("탐색중\n");
		if (mid == NULL)  //만약 mid가 비어있으면
			return NULL;

		if (mid->data == value) {  // 만약 입력값이 중간값이면
			printf("찾았습니다.\n");
			printf("자료가 ");
			searchNode(head, value);
			printf("에 있습니다.\n");

			return mid;
		}

		else if (mid->data < value) {  //만약 중간값 < 입력값이면
			start = mid->next;  //중간값을 오른쪽으로 한칸이동한 것을 start로 설정
			printf(" 현재 ");
			printf(" 중간값: %d\n", mid->data);
		}

		else {  //만약 입력값 < 중간값이면
			last = mid;  // last를 mid값으로 설정한다. (Searchmiddle에서 mid전까지 탐색하므로 결과적으로는 mid-1을 끝으로 여기고 탐색하게 됨)
			printf(" 현재 ");
			printf(" 중간값: %d\n", mid->data);

		}

	}
	// 값 없으면
	return NULL;
}




int main() {
	int con;

	printf("***2020 데이터구조 과제 2번 이진 탐색 프로그램***\n  2. linked list 이용");
	printf("\n다음 5개를 질문하여 : (1) 3, (2) 96, (3) 15, (4) 66, (5) 99를 찾아 보시오.\n");
	printf("인덱스는 0부터 시작하며, 단계별로 중간값을 탐색하여 알려줍니다.\n");
	printf("값은 입력해서 찾으세요\n");
	printf("리스트에 있는 값만 찾을 수 있습니다.\n없는 값을 찾으려 하지 마십시오.\n");

	struct NODE* head = (NODE*)malloc(sizeof(NODE));  // 머리 노드 생성
	list_init(head);         //머리 노드에는 데이터를 저장하지 않음

	addNode(head, 99);  //머리노드 뒤에 새 노드 추가
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


	print_all(head); //출력


	int value;

	while (1)
	{
		printf("*******이진검색프로그램 (Linked list) *******\n");
		printf("계속하려면 1, 프로그램을 끝내려면 0\n");
		scanf("%d", &con);// 프로그램 진행 여부 입력 
		if (con == 0)//0을 입력 
		{
			break;//반복문 탈출
		}
		printf("찾고 싶은 값을 입력하세요:");
		scanf("%d", &value);
		binarySearch(head, value); //이진탐색
	}
	freeNode(head);  //머리 노드 메모리 해제


	return 0;
}