
#pragma once
typedef int DLDataType;


typedef struct DListNode{
	struct DListNode* _pNext;//指向当前节点的下一个节点
	struct DListNode* _pPre;//指向当前节点的前一个
	DLDataType _data;
}DLNode, *PDLNode; //PDLNode是struct的指针类型

//声明文件名
void DListInit(PDLNode* pHead);//链表初始化
void DListPushBack(PDLNode pHead, DLDataType data);//链表尾插
void DListPopBack(PDLNode pHead);//链表尾删，最后一个节点一删就可以了
void DListPushFront(PDLNode pHead, DLDataType data);//头插
void DListPopFront(PDLNode pHead);//头删
void DListInsert(PDLNode pos, DLDataType data);//给定一个位置pos，插入一个元素
void DListErase(PDLNode pos);
void DListClear(PDLNode pHead);//清空链表
void DListDestroy(PDLNode* pHead);//删除链表

void TestDList();