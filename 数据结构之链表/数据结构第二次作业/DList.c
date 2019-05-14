#include "DList.h"
#include <malloc.h>
#include <assert.h>
#include <stdio.h>


void DListInit(PDLNode* pHead){ //  pHead永远不可能为空
	assert(pHead);
	*pHead = (PDLNode)malloc(sizeof(DLNode));//给出头结点
	if (NULL == *pHead){   //判空
		assert(0);
		return;
	}
	 //解引用得到外部实参地址
	(*pHead)->_pNext = *pHead;//下一个元素指向它自己（空链表下）
	(*pHead)->_pPre = *pHead;//前一个元素也指向它自己（空链表下）
}

PDLNode BuyDListNode(DLDataType data){
	PDLNode pNewNode = (PDLNode)malloc(sizeof(DLNode));
	if (NULL == pNewNode){
		assert(0);
		return;
	}

	pNewNode->_pNext = NULL;//新节点的下一个节点并不清楚
	pNewNode->_pPre = NULL;
}

void DListPushBack(PDLNode pHead, DLDataType data){
	PDLNode pNewNode = BuyDListNode(data);//新节点传进去
	pNewNode->_pNext = pHead;
	pNewNode->_pPre = pHead->_pPre;//head的前一个节点就是原来的最后一个节点
	pHead->_pPre->_pNext = pNewNode;
	pHead->_pPre = pNewNode;
}
void DListPopBack(PDLNode pHead){
	PDLNode pDelNode = NULL;
	assert(pHead);
	if (pHead == pHead->_pNext)//指向自己，删不了就返回
		return;
	PDLNode pDelNode = pHead->_pPre;
	pDelNode->_pPre->_pNext = pHead;
	pHead->_pPre = pDelNode->_pPre;
	free(pDelNode);
}
void DListPushFront(PDLNode pHead, DLDataType data)
{
	PDLNode pNewNode = BuyDListNode(data);//先给一个新元素data
	pNewNode->_pNext = pHead->_pNext;
	pNewNode->_pPre = pHead;
	pHead->_pNext = pNewNode;
	pNewNode->_pNext->_pPre = pNewNode;

}

void DListPopFront(PDLNode pHead){
	PDLNode pDelNode = NULL;
	assert(pHead);
	if (pHead->_pNext == pHead)//空链表删出不了，直接返回
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
		pHead->_pNext = pCur->_pNext;//头删
		free(pCur);
		pCur = pHead->_pNext;
	}

	pHead->_pNext = pHead;//空链表
	pHead->_pPre = pHead;
}
void DListDestroy(PDLNode* pHead){ //这里的pHead是一个地址
	DListClear(*pHead);//这里需要解应用得到
	free(*pHead);
	*pHead = NULL;//头指向空
}


void TestDList()
{
	PDLNode pHead = NULL;
	DListInit(&pHead);// &可改变外部实参
}

