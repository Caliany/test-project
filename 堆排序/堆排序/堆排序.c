#include "heap.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void swap(int* data, int* data1)
{
	int temp = *data;
	*data = *data1;
	*data1 = temp;
}
void heapadjust(int* array, int size,int parents)
{
	int child = parents * 2 + 1;

	while (child < size)
	{
		// 找双亲孩子中较小的孩子
		if (child + 1 < size && (array[child + 1]> array[child]))
		{
			child += 1;
		}

		if ((array[child]> array[parents]))
		{
			swap(&array[child], &array[parents]);
			parents = child;
			child = parents * 2 + 1;
		}
		else
		{
			return 0;
        }
	}
}
void heapsort(int* array, int size)
{
	int root = (size - 2) / 2;
	for (; root >= 0; root--)
	{
		heapadjust(array, size, root);
	}
	int end = size - 1;
	while (end)
	{
		swap(&array[0], &array[end]);
		heapadjust(array, end, 0);
		end--;
	}
}
void test()
{
	int array[] = { 2, 3, 8, 0, 9, 1, 7, 4, 6, 5 };
	heapsort(array, sizeof(array) / sizeof(array[0]));
}
