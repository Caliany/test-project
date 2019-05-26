#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int arr[], int size){
	int i, j, k, t;
	for (i = 0; i < size - 1; i++){
		printf("\n第%d趟排序：\n", i);
		for (j = 0; j < size - 1; j++){
			if (arr[j]>arr[j + 1]){
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
			}
			printf("排序中：");
			for (k = 0; k < size; k++){
				printf("%d", arr[k]);
			}
			printf("\n");
		}
		printf("排序后的结果：");
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
	length = sizeof(arr) / sizeof(arr[0]);//元素个数
	printf("排序前：\n");
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

