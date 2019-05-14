
#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

void SListInit(SList* s){
	assert(s);
	s->_pHead = NULL;
}
//1.买空间
PNode BuySListNode(SDataType data){
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode){
		assert(0);//断言为什么为空
		return NULL;
	}
	pNewNode->_data = data;//申请空间成功
	pNewNode->_pNext = NULL;//下一个节点不知道就为空
	return pNewNode;
}

//2.尾插
void SListPushBack(SList* s,SDataType data){
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (NULL == s->_pHead){
		//空链表
		s->_pHead = pNewNode;//第一个节点指向和新节点
	}
	else{
		//链表非空，找链表最后一个节点；
		PNode pCur = s->_pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;
	}
}
//3.尾删
void SListPopBack(SList* s){
	assert(s);
	if (NULL == s->_pHead)//空链表
		return;
	else if (NULL  == s->_pHead->_pNext){//只有一个节点
		free(s->_pHead);
		s->_pHead = NULL;	
	}
	else{
	//多个节点
		PNode pPre = NULL;
		PNode pCur = s->_pHead;
		while (pCur->_pNext){
			pPre = pCur;//记录下来Cur，在往后走
			pCur = pCur->_pNext;//Next为空了，循环退出
		}
		free(pCur);
		pPre->_pNext = NULL;
	}
}
//4.打印
void PrintSList(SList* s){
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur){
		printf("%d-->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}
//4.头插
void SListPushFront(SList* s, SDataType data){
	assert(s);
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}

//5.头删
void SListPopFront(SList* s){
	PNode pDelNode = NULL;
	assert(s);
	if (NULL == s->_pHead)
		return;
	//找到待删除的节点

	pDelNode = s->_pHead;
	s->_pHead = pDelNode->_pNext;
	free(pDelNode);
}

void SListInsert(PNode pos, SDataType data){
	PNode pNewNode = NULL;//前面声明
	if (NULL == pos)
		return;
	pNewNode = BuySListNode(data);//不能整体定义在前面，万一pos为空，代码就返回了，导致内存就泄露
	pNewNode->_pNext = pos->_pNext;
	pos->_pNext = pNewNode;
}

void SListErase(SList* s, PNode pos){
	assert(s);
	if (NULL == pos || NULL == s->_pHead)
		return;
	if (pos == s->_pHead){
		s->_pHead = pos->_pNext;
		free(pos);
	}
	else {
		PNode pPrePos = s->_pHead;
		while (pPrePos && pPrePos->_pNext != pos)
			pPrePos = pPrePos->_pNext;

		if (pPrePos)
		pPrePos->_pNext = pos->_pNext;
		free(pos);
	}
		free(pos);
	}

PNode SListFind(SList*s, SDataType data){
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur){
		if (pCur->_data == data)
			return pCur;

		pCur = pCur->_pNext;
	}
	return NULL;
}

int SListSize(SList* s){//统计共有多少个字节
	assert(s);
	PNode pCur = s->_pHead;
	int count = 0;
	while (pCur){
		count++;
			pCur = pCur->_pNext;
	}
	return count;
}
int SListEmpty(SList* s){//判空
	assert(s);
	return NULL == s->_pHead;

}
//移除链表中第一个值为data的元素
void SListRemove(SList* s, SDataType data){
	PNode pPre = NULL;
	assert(s);
	PNode pCur = s->_pHead;
	if (NULL == s->_pHead)
		return;
//1.找带该节点的位置
	while (pCur){
		if (pCur->_data == data){
			if (pCur == s->_pHead){
				s->_pHead = pCur->_pNext;
				free(pCur);
			}
			else{
				pPre->_pNext = pCur->_pNext;
				
			}
				free(pCur);
				return;
		}
		else{
			pPre = pCur;//先将pCur先保存起来，再往后走
			pCur = pCur->_pNext;
	}
	}
}
//删除链表中所有值为data的元素
void SListRemoveAll(SList* head, SDataType data){
	if (NULL == head)
		return NULL;

}
//在链表的pos位置后插入值为data的节点

void TestSList1(){
	SList s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	SListPushBack(&s, 4);
	SListPushBack(&s, 5);

	SListInsert(SListFind(&s,2), 5);

	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	SListPopBack(&s);
	PrintSList(&s);
}
void TestSList2(){
	SList s;
	SListInit(&s); 
	SListPushFront(&s, 1);
	SListPushFront(&s, 2);
	SListPushFront(&s, 3);
	SListPushFront(&s, 4);
	SListPushFront(&s, 5);

	SListPopFront(&s);
	PrintSList(&s);

	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	SListPopFront(&s);
	PrintSList(&s);
}
//不带头结点的单链表形式
void PushBack(PNode* pHead, SDataType data){
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if(NULL == *pHead) //解应用，得到实参
		*pHead = pNewNode;
	else{
	//找链表中的最后一个节点
		PNode pCur = pHead;
		while (pCur->_pNext){
			pCur = pCur->_pNext;	
		}
		pCur->_pNext = pNewNode;
	}
}
void TestSList3(){
//不带头结点的单链表
	PNode pHead = NULL;
	PushBack(&pHead, 1);
	PushBack(&pHead, 2);
	PushBack(&pHead, 3);
}
void TestSList(){
	TestSList1();
	TestSList2();
}



