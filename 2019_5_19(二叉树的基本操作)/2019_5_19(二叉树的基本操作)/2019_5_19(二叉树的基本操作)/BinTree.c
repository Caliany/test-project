#include "BinTree.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>

//获取二叉树
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

//二叉树的创建
BTNode* _CreatBinTree(BTDataType* array, int size, int* index, BTDataType invalid){
	BTNode* pRoot = NULL;
	if (*index < size && invalid != array[*index]){
		//创建根节点
		pRoot = BuyBinTreeNode(array[*index]);

		//创建根的左子树
		++(*index);
		pRoot->_pLeft = _CreatBinTree(array, size, index, invalid);

		//创建根的右子树
		++(*index);
		pRoot->_pRight = _CreatBinTree(array, size, index, invalid);
	}
	return pRoot;
}

//重新包装
BTNode* CreatBinTree(BTDataType* array, int size,BTDataType invalid){
	int index = 0;
	return _CreatBinTree(array, size, &index, invalid);
}

//前序遍历
void PreOrder(BTNode* pRoot){
	if (pRoot){
		printf("%c ", pRoot->_data);
		PreOrder(pRoot->_pLeft);
		PreOrder(pRoot->_pRight);
	}
}

//中序遍历
void InOrder(BTNode* pRoot){
	if (pRoot){
		InOrder(pRoot->_pLeft);
		printf("%c ", pRoot->_data);
		InOrder(pRoot->_pRight);
	}
}

//后序遍历
void PosOrder(BTNode* pRoot){
	if (pRoot){
		PosOrder(pRoot->_pLeft);
		PosOrder(pRoot->_pRight);
		printf("%c ", pRoot->_data);
	}
}

//叶子结点个数
int GetLeafCount(BTNode* pRoot){
	if (NULL == pRoot){
		return 0;
	}
	if (NULL == pRoot->_pLeft && NULL == pRoot->_pRight){
		return 1;
	}
	return GetLeafCount(pRoot->_pLeft) + GetLeafCount(pRoot->_pRight);
}

//销毁(后序方法)
void DestroyBinTree(BTNode** pRoot){
	if (*pRoot){
		DestroyBinTree(&(*pRoot)->_pLeft);
		DestroyBinTree(&(*pRoot)->_pRight);
		free(*pRoot);
		*pRoot = NULL;
	}
}

//测试
void TestBinTree(){
	char* str = "ABCDE#F##G#";
	BTNode* pRoot = CreatBinTree(str, strlen(str),'#');
	printf("前序遍历结果: ");
	PreOrder(pRoot);
	printf("\n");

	printf("中序遍历结果: ");
	InOrder(pRoot);
	printf("\n");
	
	printf("后序遍历结果: ");
	PosOrder(pRoot);
	printf("\n");
	DestroyBinTree(&pRoot);
}
