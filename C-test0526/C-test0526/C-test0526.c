#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int size){
	int i, j, k, t;
	for (i = 0; i < size - 1; i++){
		printf("\n��%d������\n", i);
		for (j = 0; j < size - 1; j++){
			if (arr[j]>arr[j + 1]){
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
			printf("�����У�");
			for (k = 0; k < size; k++){
				printf("%d", arr[k]);
			}
			printf("\n");
		}
		printf("�����Ľ����");
		for (k = 0; k < size; k++){
			printf("%d", arr[k]);
		}
		printf("\n");
	}
}
int main()
{
	int arr[] = { 4, 3, 5, 2, 6, 1, 9, 7, 8, 0 };
	int length;
	int i, j;
	length = sizeof(arr) / sizeof(arr[0]);//Ԫ�ظ���
	printf("����ǰ��\n");
	for (i = 0; i < length; i++){
		printf("%d", arr[i]);
	}
	BubbleSort(arr, length);
	for (j = 0; j < length; j++){

		printf("%d", arr[j]);
	}
	printf("\n");
	system("pause");
	return 0;
}

