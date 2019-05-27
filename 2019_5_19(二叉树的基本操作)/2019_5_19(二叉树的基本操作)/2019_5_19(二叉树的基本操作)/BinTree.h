#pragma once

//����������ʽ�洢��ʽ--���ӱ�ʾ��
typedef int BTDataType;

typedef struct BTNode{
	struct BTNode* _pLeft;
	struct BTNode* _pRight;
	BTDataType _data;
}BTNode;

//��ȡ������
BTNode* BuyBinTreeNode(BTDataType data);

//�������Ĵ���
BTNode* _CreatBinTree(BTDataType* array, int size, int* index, BTDataType invalid);

//���°�װ
BTNode* CreatBinTree(BTDataType* array, int size, BTDataType invalid);

//�������Ŀ���(��ѯ����)
void* CopyBinTree(BTNode* pRoot);

//ǰ�����
void PreOrder(BTNode* pRoot);

//�������
void InOrder(BTNode* pRoot);

//�������
void PosOrder(BTNode* pRoot);

//��ȡ�������е�k����ĸ���
void GetKLevelNodeCount(BTNode* pRoot, int K);

//��ȡ�������еĽ��
int GetBinTreeSize(BTNode* pRoot);

//Ҷ�ӽ�����
int GetLeafCount(BTNode* pRoot);

//��ȡ���ĸ߶�
void GetBinTreeHeight(BTNode* pRoot);

//Ԫ��������λ�õĲ���
BTNode BinTreeFind(BTNode* pRoot, BTDataType x);

//����
void DestroyBinTree(BTNode** pRoot);
//����
void TestBinTree();