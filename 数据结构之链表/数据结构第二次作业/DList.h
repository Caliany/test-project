
#pragma once
typedef int DLDataType;


typedef struct DListNode{
	struct DListNode* _pNext;//ָ��ǰ�ڵ����һ���ڵ�
	struct DListNode* _pPre;//ָ��ǰ�ڵ��ǰһ��
	DLDataType _data;
}DLNode, *PDLNode; //PDLNode��struct��ָ������

//�����ļ���
void DListInit(PDLNode* pHead);//�����ʼ��
void DListPushBack(PDLNode pHead, DLDataType data);//����β��
void DListPopBack(PDLNode pHead);//����βɾ�����һ���ڵ�һɾ�Ϳ�����
void DListPushFront(PDLNode pHead, DLDataType data);//ͷ��
void DListPopFront(PDLNode pHead);//ͷɾ
void DListInsert(PDLNode pos, DLDataType data);//����һ��λ��pos������һ��Ԫ��
void DListErase(PDLNode pos);
void DListClear(PDLNode pHead);//�������
void DListDestroy(PDLNode* pHead);//ɾ������

void TestDList();