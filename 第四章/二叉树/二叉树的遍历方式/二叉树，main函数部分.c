#include <stdio.h>
#include "Bintree.h"

ChainBinTree* InitRoot()
{
	ChainBinTree* node;
	
	if (node = (ChainBinTree*)malloc(sizeof(ChainBinTree)))
	{
		printf("\n输入根节点数据：");
		scanf("%s", &node->data);
		node->left = NULL;
		node->right = NULL;
		return NULL;
		
	}
	return NULL;
}
void AddNode(ChainBinTree* bt)
{
	ChainBinTree* node, * parent;
	DATA data;
	char select;
	if (node = (ChainBinTree*)malloc(sizeof(ChainBinTree)))
	{
		printf("\n输入二叉树的结点数据：");
		fflush(stdin);
		scanf("%s", &node->data);
		node->left = NULL;
		node->right = NULL;
		printf("输入父结点数据：");
		fflush(stdin);
		scanf("%s", &data);
		parent = BinTreeFind(bt, data);
		if (!parent)
		{
			printf("未找到父结点！\n");
			free(node);
			return;
		}
		printf("1.添加到左子树\n 2.添加到右子树\n");
		do {
			select = getchar();
			select -= '0';
			if (select == 1 || select == 2)
				BinTreeAddNode(parent, node, select);
		} while (select != 1 && select != 2);
	}
	return;
}
int main()
{
	ChainBinTree* root = NULL;
	char select;
	void (*oper1)(); //指向集体的指针
	oper1 = oper;  //指向具体的操作函数
	do {
		printf("\n1.设置二叉树根元素  2.添加二叉树结点\n");
		printf("3.先序遍历           4.中序遍历\n");
		printf("5.后序遍历           6.按层遍历\n");
		printf("7.二叉树的深度        0.退出\n");
		select = getchar();
		switch (select) {
		case '1': root = InitRoot(); break;
		case '2':AddNode(root); break;
	/*	case '3': 
			printf("\n先遍历的结果：");
			BinTree_DLR(root,oper1);
		case '4':
			printf("\n中序遍历的结果：");
			BinTree_LDR(root, oper1);
			printf("\n");
			break;
		case '5':
			printf("\n中序遍历的结果：");
			BinTree_LRD(root, oper1);
			printf("\n");
			break;
		case '6':
			printf("\n中序遍历的结果：");
			BinTree_level(root, oper1);
			printf("\n");
			break;*/
		case '7': printf("\n二叉树的深度为：%d\n", BinTreeDepth(root)); break;
		case '0': break;
		}
	} while (select != '0');
	BinTreeClear(root);
	root = NULL;
	getchar();
	return 0;

}
