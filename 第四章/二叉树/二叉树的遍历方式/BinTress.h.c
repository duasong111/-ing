#include <stdio.h>
#include <stdlib.h>
#define QUEUE_MAXSIZE 50
typedef char DATA;
typedef struct ChainTree
{
	DATA data;
	 ChainTree* left;
	struct ChainTree* right;
}ChainBinTree;
void oper(ChainBinTree* p);
ChainBinTree* BinTreeInit(ChainBinTree* node); //初始化
int BinTreeAddNode(ChainBinTree* bt, ChainBinTree* node, int n); //添加到二叉树
ChainBinTree* BinTreeLeft(ChainBinTree* bt); //返回左子节点
ChainBinTree* BinTreeRight(ChainBinTree* bt); //返回左子节点
int BinTreeIsEmpty(ChainBinTree* bt); //检验是否为空
int BinTreeDepth(ChainBinTree* bt); //求深度
ChainBinTree* BinTreeFind(ChainBinTree* bt, DATA data);
void BinTreeClear(ChainBinTree* bt);
//void BinTree_DLR(BinTree);
void BinTree_DLR(ChainBinTree* bt, void(*poer)(ChainBinTree* p));
void BinTree_LDR(ChainBinTree* bt, void(*poer)(ChainBinTree* p));
void BinTree_LRD(ChainBinTree* bt, void(*poer)(ChainBinTree* p));
void BinTree_level(ChainBinTree* bt, void(*poer)(ChainBinTree* p));
