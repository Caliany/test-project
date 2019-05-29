#pragma once

typedef int HPDataType;

typedef int(*PCOM)(HPDataType, HPDataType);
int Less(HPDataType left, HPDataType right);
int Greater(HPDataType left, HPDataType right);

typedef struct Heap
{
	HPDataType* _array;
	int _capacity;
	int _size;
	PCOM Compare;
}Heap;


//�������ʼ����
void InitHeap(Heap* hp, HPDataType* array, int size, PCOM compare);
//��ʼ��һ���ն�
void InitEmptyHeap(Heap* hp, int capacity, PCOM compare);
//�ڶ��в���ֵΪdata��Ԫ��
void InsertHeap(Heap* hp, HPDataType data);
//ɾ���Ѷ�Ԫ��
void EraseHeap(Heap* hp);
//��ȡ������ЧԪ�صĸ���
int HeapSize(Heap* hp);
//�����Ƿ�Ϊ��
int HeapEmpty(Heap* hp);
//��ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* hp);
//���ٶ�
void DestroyHeap(Heap* hp);


void TestHeap();

void HeapSort(int* array, int size);