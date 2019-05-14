#include "DList.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>


void DListInit(PDLNode* pHead){ //  pHead��Զ������Ϊ��
	assert(pHead);
	*pHead = (PDLNode)malloc(sizeof(DLNode));//����ͷ���
	if (NULL == *pHead){   //�п�
		assert(0);
		return;
	}
	 //�����õõ��ⲿʵ�ε�ַ
	(*pHead)->_pNext = *pHead;//��һ��Ԫ��ָ�����Լ����������£�
	(*pHead)->_pPre = *pHead;//ǰһ��Ԫ��Ҳָ�����Լ����������£�
}

PDLNode BuyDListNode(DLDataType data){
	PDLNode pNewNode = (PDLNode)malloc(sizeof(DLNode));
	if (NULL == pNewNode){
		assert(0);
		return;
	}

	pNewNode->_pNext = NULL;//�½ڵ����һ���ڵ㲢�����
	pNewNode->_pPre = NULL;
}

void DListPushBack(PDLNode pHead, DLDataType data){
	PDLNode pNewNode = BuyDListNode(data);//�½ڵ㴫��ȥ
	pNewNode->_pNext = pHead;
	pNewNode->_pPre = pHead->_pPre;//head��ǰһ���ڵ����ԭ�������һ���ڵ�
	pHead->_pPre->_pNext = pNewNode;
	pHead->_pPre = pNewNode;
}
void DListPopBack(PDLNode pHead){
	PDLNode pDelNode = NULL;
	assert(pHead);
	if (pHead == pHead->_pNext)//ָ���Լ���ɾ���˾ͷ���
		return;
	PDLNode pDelNode = pHead->_pPre;
	pDelNode->_pPre->_pNext = pHead;
	pHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
}
void DListPushFront(PDLNode pHead, DLDataType data)
{
	PDLNode pNewNode = BuyDListNode(data);//�ȸ�һ����Ԫ��data
	pNewNode->_pNext = pHead->_pNext;
	pNewNode->_pPre = pHead;
	pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;

}

void DListPopFront(PDLNode pHead){
	PDLNode pDelNode = NULL;
	assert(pHead);
	if (pHead->_pNext == pHead)//������ɾ�����ˣ�ֱ�ӷ���
		return;

	PDLNode pDelNode = pHead->_pNext;
	pHead->_pNext = pDelNode->_pNext;
	pDelNode->_pNext->_pPre = pHead;
	free(pHead);
}

void DListInsert(PDLNode pos, DLDataType data){
	PDLNode pNewNode = NULL;
	if (NULL == pos)
		return;

	PDLNode pNewNode = BuyDListNode(data);
	pNewNode->_pNext = pos;
	pNewNode->_pPre = pos->_pPre;
	pos->_pPre = pNewNode;
	pNewNode->_pPre->_pNext = pNewNode;
}

void DListErase(PDLNode pos){
	if (NULL == pos)
		return;

	pos->_pNext->_pPre = pos->_pPre;
	pos->_pPre->_pNext = pos->_pNext;
	free(pos);
}

void DListClear(PDLNode pHead)
{
	PDLNode pCur = pHead->_pNext;

	while (pCur != pHead){
		pHead->_pNext = pCur->_pNext;//ͷɾ
		free(pCur);
		pCur = pHead->_pNext;
	}

	pHead->_pNext = pHead;//������
	pHead->_pPre = pHead;
}
void DListDestroy(PDLNode* pHead){ //�����pHead��һ����ַ
	DListClear(*pHead);//������Ҫ��Ӧ�õõ�
	free(*pHead);
	*pHead = NULL;//ͷָ���
}


void TestDList()
{
	PDLNode pHead = NULL;
	DListInit(&pHead);// &�ɸı��ⲿʵ��
}

