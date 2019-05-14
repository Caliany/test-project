
#pragma once

typedef int SDataType;
//����Ľڵ�
typedef struct SListNode{
	SDataType _data;
	struct SListNode* _pNext;
}Node,*PNode;

typedef struct SList{
	PNode _pHead;//ָ��������ĵ�һ���ڵ�
}SList;

void SListInit(SList* s);//��ʼ������
void SListPushBack(SList* s, SDataType data);
void SListPopBack(SList* s, SDataType data);
void SListPushFront(SList* s, SDataType data);
void SListPopFront(SList* s, SDataType data);
void SListInsert(PNode pos, SDataType data);
//void SListErase(PNode pos);
void SListErase(SList* s, PNode pos);
PNode SListFind(SList*s, SDataType data);//���������е�Ԫ��
int SListize(SList* s);//ͳ�ƹ��ж��ٸ��ڵ�
int SListEmpty(SList* s);//�п�
void TestSList();//���Ե�ǰ����
void SListRemove(SList* s, SDataType data);
void SListRemoveAll(SList* s, SDataType data);

//��ֵ����ֵ�ĸ���
