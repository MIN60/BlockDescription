//2020 �����ͱ��� ���� 2�� ���� �˻� ���α׷� - Array �̿�
//1914201 �����

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int binarysearch(int data[], int n, int key) {  //����Ž��
	int low, high;
	int mid;

	low = 0;  
	high = n - 1;
	while (low <= high) {
		
		mid = (low + high) / 2;       //�߰���

		printf("�ε���: left= %d mid=%d right=%d ", low, mid, high);
		if (key == data[mid]) {            //�߰����� �Է°��� ������ Ž�� ����
			return mid;
		}
		else if (key < data[mid]) {        //�Է°�<�߰��� �̸� 
			high = mid - 1;                 //Ž�� ������ �Ʒ���(����)���� ��ĭ �̵�
			printf("Ž����\n ���� �߰���: %d\n", data[mid] );
		
		}
		else if (key > data[mid]) {        //�Է°�> �߰��� �̸� 
			low = mid + 1;                 // Ž�� ������ ����(������)���� ��ĭ �̵�
			printf("Ž����\n ���� �߰���: %d\n", data[mid]);
			
		}
	}
	return -1;                            //Ž�� ����
}

int main(int argc, char* argv[])
{
	int a[30] = { 1, 3, 5, 6, 7, 8, 11, 12, 14, 15, 24, 26, 42, 43, 48, 49, 51, 55, 56, 59,66, 67, 69, 70, 71, 73, 75, 80, 96, 99 };    //���ĵ� �ڷ�
	int index;
	int key;
	int con;

	printf("***2020 �����ͱ��� ���� 2�� ���� Ž�� ���α׷�***\n  1.Array�̿�\n");
	for (int i = 0; i < 30; i++) {  //��ü �迭 ���
		printf(" %d ",a[i]);
	}
	printf("\n���� 5���� �����Ͽ� : (1) 3, (2) 96, (3) 15, (4) 66, (5) 99�� ã�� ���ÿ�.\n");
	printf("�ε����� 0���� �����մϴ�.\n");
	printf("���� �Է��ؼ� ã������\n���� ���� ã���� ���� ���ʽÿ�.\n");


	while (1)
	{
		printf("******* �����˻����α׷� (�迭) *******\n");
		printf("����Ϸ��� 1, ���α׷��� �������� 0\n");
		scanf("%d", &con);//���� ���� ���� �Է� 
		if (con == 0)//0�� �Է� 
		{
			break;//�ݺ��� Ż��
		}
		printf("ã�� ���� ���� �Է��ϼ���:");
		scanf("%d", &key);    //����ڿ��� �� �Է¹���
		index = binarysearch(a, 30, key);
		if (index == -1) { //���ϰ��� -1�̸�
			printf("�ڷᰡ �����ϴ�!\n");
		}
		else {
			printf("�ڷᰡ %d��°�� �ֽ��ϴ�.\n", index);
		}
	}
	
	
	return 0;
}
