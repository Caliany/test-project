#include "BinTree.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

//��ȡ������
BTNode* BuyBinTreeNode(BTDataType data){
	BTNode* pNewNode = (BTNode*)malloc(sizeof(BTNode));
	if (NULL == pNewNode){
		assert(0);
		return NULL;
	}
	pNewNode->_data = data;
	pNewNode->_pLeft = NULL;
	pNewNode->_pRight = NULL;
	return pNewNode;
}

//�������Ĵ���
BTNode* _CreatBinTree(BTDataType* array, int size, int* index, BTDataType invalid){
	BTNode* pRoot = NULL;
	if (*index < size && invalid != array[*index]){
		//�������ڵ�
		pRoot = BuyBinTreeNode(array[*index]);

		//��������������
		++(*index);
		pRoot->_pLeft = _CreatBinTree(array, size, index, invalid);

		//��������������
		++(*index);
		pRoot->_pRight = _CreatBinTree(array, size, index, invalid);
	}
	return pRoot;
}

//���°�װ
BTNode* CreatBinTree(BTDataType* array, int size,BTDataType invalid){
	int index = 0;
	return _CreatBinTree(array, size, &index, invalid);
}

//ǰ�����
void PreOrder(BTNode* pRoot){
	if (pRoot){
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

//�������
void InOrder(BTNode* pRoot){
	if (pRoot){
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

//�������
void PosOrder(BTNode* pRoot){
	if (pRoot){
		PosOrder(pRoot->_pLeft);
		PosOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

//Ҷ�ӽ�����
int GetLeafCount(BTNode* pRoot){
	if (NULL == pRoot){
		return 0;
	}
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight){
		return 1;
	}
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

//����(���򷽷�)
void DestroyBinTree(BTNode** pRoot){
	if (*pRoot){
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

//����
void TestBinTree(){
	char* str = "ABCDE#F##G#";
	BTNode* pRoot = CreatBinTree(str, strlen(str),'#');
	printf("ǰ��������: ");
	PreOrder(pRoot);
	printf("\n");

	printf("����������: ");
	InOrder(pRoot);
	printf("\n");
	
	printf("����������: ");
	PosOrder(pRoot);
	printf("\n");
	DestroyBinTree(&pRoot);
}
