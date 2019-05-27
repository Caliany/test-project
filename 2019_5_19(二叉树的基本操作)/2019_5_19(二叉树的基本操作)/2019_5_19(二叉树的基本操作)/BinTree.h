#pragma once

//二叉树的链式存储方式--孩子表示法
typedef int BTDataType;

typedef struct BTNode{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;

//获取二叉树
BTNode* BuyBinTreeNode(BTDataType data);

//二叉树的创建
BTNode* _CreatBinTree(BTDataType* array, int size, int* index, BTDataType invalid);

//重新包装
BTNode* CreatBinTree(BTDataType* array, int size, BTDataType invalid);

//二叉树的拷贝(查询概念)
void* CopyBinTree(BTNode* pRoot);

//前序遍历
void PreOrder(BTNode* pRoot);

//中序遍历
void InOrder(BTNode* pRoot);

//后序遍历
void PosOrder(BTNode* pRoot);

//获取二叉树中第k层结点的个数
void GetKLevelNodeCount(BTNode* pRoot, int K);

//获取二叉树中的结点
int GetBinTreeSize(BTNode* pRoot);

//叶子结点个数
int GetLeafCount(BTNode* pRoot);

//获取树的高度
void GetBinTreeHeight(BTNode* pRoot);

//元素在树中位置的查找
BTNode BinTreeFind(BTNode* pRoot, BTDataType x);

//销毁
void DestroyBinTree(BTNode** pRoot);
//测试
void TestBinTree();