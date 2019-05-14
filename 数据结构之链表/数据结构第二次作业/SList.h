
#pragma once

typedef int SDataType;
//链表的节点
typedef struct SListNode{
	SDataType _data;
	struct SListNode* _pNext;
}Node,*PNode;

typedef struct SList{
	PNode _pHead;//指向链表里的第一个节点
}SList;

void SListInit(SList* s);//初始化链表
void SListPushBack(SList* s, SDataType data);
void SListPopBack(SList* s, SDataType data);
void SListPushFront(SList* s, SDataType data);
void SListPopFront(SList* s, SDataType data);
void SListInsert(PNode pos, SDataType data);
//void SListErase(PNode pos);
void SListErase(SList* s, PNode pos);
PNode SListFind(SList*s, SDataType data);//查找链表中的元素
int SListize(SList* s);//统计共有多少个节点
int SListEmpty(SList* s);//判空
void TestSList();//测试当前链表
void SListRemove(SList* s, SDataType data);
void SListRemoveAll(SList* s, SDataType data);

//左值和右值的概念
