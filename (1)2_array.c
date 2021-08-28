//2020 데이터구조 과제 2번 이진 검색 프로그램 - Array 이용
//1914201 김민정

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int binarysearch(int data[], int n, int key) {  //이진탐색
	int low, high;
	int mid;

	low = 0;  
	high = n - 1;
	while (low <= high) {
		
		mid = (low + high) / 2;       //중간값

		printf("인덱스: left= %d mid=%d right=%d ", low, mid, high);
		if (key == data[mid]) {            //중간값과 입력값이 같으면 탐색 성공
			return mid;
		}
		else if (key < data[mid]) {        //입력값<중간값 이면 
			high = mid - 1;                 //탐색 범위를 아래쪽(왼쪽)으로 한칸 이동
			printf("탐색중\n 현재 중간값: %d\n", data[mid] );
		
		}
		else if (key > data[mid]) {        //입력값> 중간값 이면 
			low = mid + 1;                 // 탐색 범위를 위쪽(오른쪽)으로 힌칸 이동
			printf("탐색중\n 현재 중간값: %d\n", data[mid]);
			
		}
	}
	return -1;                            //탐색 실패
}

int main(int argc, char* argv[])
{
	int a[30] = { 1, 3, 5, 6, 7, 8, 11, 12, 14, 15, 24, 26, 42, 43, 48, 49, 51, 55, 56, 59,66, 67, 69, 70, 71, 73, 75, 80, 96, 99 };    //정렬된 자료
	int index;
	int key;
	int con;

	printf("***2020 데이터구조 과제 2번 이진 탐색 프로그램***\n  1.Array이용\n");
	for (int i = 0; i < 30; i++) {  //전체 배열 출력
		printf(" %d ",a[i]);
	}
	printf("\n다음 5개를 질문하여 : (1) 3, (2) 96, (3) 15, (4) 66, (5) 99를 찾아 보시오.\n");
	printf("인덱스는 0부터 시작합니다.\n");
	printf("값은 입력해서 찾으세요\n없는 값을 찾으려 하지 마십시오.\n");


	while (1)
	{
		printf("******* 이진검색프로그램 (배열) *******\n");
		printf("계속하려면 1, 프로그램을 끝내려면 0\n");
		scanf("%d", &con);//게임 진행 여부 입력 
		if (con == 0)//0을 입력 
		{
			break;//반복문 탈출
		}
		printf("찾고 싶은 값을 입력하세요:");
		scanf("%d", &key);    //사용자에게 값 입력받음
		index = binarysearch(a, 30, key);
		if (index == -1) { //리턴값이 -1이면
			printf("자료가 없습니다!\n");
		}
		else {
			printf("자료가 %d번째에 있습니다.\n", index);
		}
	}
	
	
	return 0;
}
