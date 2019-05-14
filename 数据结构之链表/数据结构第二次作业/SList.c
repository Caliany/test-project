
#include "SList.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

void SListInit(SList* s){
	assert(s);
	s->_pHead = NULL;
}
//1.��ռ�
PNode BuySListNode(SDataType data){
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if (NULL == pNewNode){
		assert(0);//����ΪʲôΪ��
		return NULL;
	}
	pNewNode->_data = data;//����ռ�ɹ�
	pNewNode->_pNext = NULL;//��һ���ڵ㲻֪����Ϊ��
	return pNewNode;
}

//2.β��
void SListPushBack(SList* s,SDataType data){
	assert(s);
	PNode pNewNode = BuySListNode(data);
	if (NULL == s->_pHead){
		//������
		s->_pHead = pNewNode;//��һ���ڵ�ָ����½ڵ�
	}
	else{
		//����ǿգ����������һ���ڵ㣻
		PNode pCur = s->_pHead;
		while (pCur->_pNext)
			pCur = pCur->_pNext;
	}
}
//3.βɾ
void SListPopBack(SList* s){
	assert(s);
	if (NULL == s->_pHead)//������
		return;
	else if (NULL  == s->_pHead->_pNext){//ֻ��һ���ڵ�
		free(s->_pHead);
		s->_pHead = NULL;	
	}
	else{
	//����ڵ�
		PNode pPre = NULL;
		PNode pCur = s->_pHead;
		while (pCur->_pNext){
			pPre = pCur;//��¼����Cur����������
			pCur = pCur->_pNext;//NextΪ���ˣ�ѭ���˳�
		}
		free(pCur);
		pPre->_pNext = NULL;
	}
}
//4.��ӡ
void PrintSList(SList* s){
	assert(s);
	PNode pCur = s->_pHead;
	while (pCur){
		printf("%d-->", pCur->_data);
		pCur = pCur->_pNext;
	}
	printf("NULL\n");
}
//4.ͷ��
void SListPushFront(SList* s, SDataType data){
	assert(s);
	PNode pNewNode = BuySListNode(data);
	pNewNode->_pNext = s->_pHead;
	s->_pHead = pNewNode;
}

//5.ͷɾ
void SListPopFront(SList* s){
	PNode pDelNode = NULL;
	assert(s);
	if (NULL == s->_pHead)
		return;
	//�ҵ���ɾ���Ľڵ�

	pDelNode = s->_pHead;
	s->_pHead = pDelNode->_pNext;
	free(pDelNode);
}

void SListInsert(PNode pos, SDataType data){
	PNode pNewNode = NULL;//ǰ������
	if (NULL == pos)
		return;
	pNewNode = BuySListNode(data);//�������嶨����ǰ�棬��һposΪ�գ�����ͷ����ˣ������ڴ��й¶
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

int SListSize(SList* s){//ͳ�ƹ��ж��ٸ��ֽ�
	assert(s);
	PNode pCur = s->_pHead;
	int count = 0;
	while (pCur){
		count++;
			pCur = pCur->_pNext;
	}
	return count;
}
int SListEmpty(SList* s){//�п�
	assert(s);
	return NULL == s->_pHead;

}
//�Ƴ������е�һ��ֵΪdata��Ԫ��
void SListRemove(SList* s, SDataType data){
	PNode pPre = NULL;
	assert(s);
	PNode pCur = s->_pHead;
	if (NULL == s->_pHead)
		return;
//1.�Ҵ��ýڵ��λ��
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
			pPre = pCur;//�Ƚ�pCur�ȱ�����������������
			pCur = pCur->_pNext;
	}
	}
}
//ɾ������������ֵΪdata��Ԫ��
void SListRemoveAll(SList* head, SDataType data){
	if (NULL == head)
		return NULL;

}
//�������posλ�ú����ֵΪdata�Ľڵ�

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
//����ͷ���ĵ�������ʽ
void PushBack(PNode* pHead, SDataType data){
	PNode pNewNode = (PNode)malloc(sizeof(Node));
	if(NULL == *pHead) //��Ӧ�ã��õ�ʵ��
		*pHead = pNewNode;
	else{
	//�������е����һ���ڵ�
		PNode pCur = pHead;
		while (pCur->_pNext){
			pCur = pCur->_pNext;	
		}
		pCur->_pNext = pNewNode;
	}
}
void TestSList3(){
//����ͷ���ĵ�����
	PNode pHead = NULL;
	PushBack(&pHead, 1);
	PushBack(&pHead, 2);
	PushBack(&pHead, 3);
}
void TestSList(){
	TestSList1();
	TestSList2();
}



