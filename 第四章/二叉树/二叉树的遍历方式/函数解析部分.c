#include "Bintree.h"

void oper(ChainBinTree* p)
{
    printf("%c ", p->data);
    return;
}

ChainBinTree* BinTreeInit(ChainBinTree* node)
{
    if (node != NULL) //节点不为空
        return node;
    else
    return NULL;
}

int BinTreeAddNode(ChainBinTree* bt, ChainBinTree* node, int n)
{
    if (bt == NULL)
    {
        printf("父节点不存在，请先设置父节点！\n");
        return 0;
    }
    switch (n)
    {
    case 1: if (bt->left) {
        printf("左子树结点不为空！\n");
        return 0;
    }else
        bt->left = node;
        break;
    case 2:  if (bt->right) {
        printf("右子树结点不为空！\n");
        return 0;
    }else
        bt->right = node;
        break;
    default:
        printf("参数错误！\n");
        return 0;
    }
    return 1;
}

ChainBinTree* BinTreeLeft(ChainBinTree* bt)
{
    if (bt)
        return bt->left;
    else
        return NULL;
}

ChainBinTree* BinTreeRight(ChainBinTree* bt)
{
    if (bt)
        return bt->right;
    else
        return NULL;
}

int BinTreeIsEmpty(ChainBinTree* bt)
{
    if (bt)
        return 0;
    else
        return 1;
}

int BinTreeDepth(ChainBinTree* bt)
{
    int dep1, dep2;
    if(bt==NULL)
        return 0;
    else
    {
        dep1 = BinTreeDepth(bt->left);
        dep2 = BinTreeDepth(bt->right);
        if (dep1 > dep2)
            return dep1 + 1;
        else
            return dep2 + 1;
    }
}

ChainBinTree* BinTreeFind(ChainBinTree* bt, DATA data)
{
    ChainBinTree* p;
    if(bt==NULL)
      return NULL;
    else
    {
        if (bt->data == data)
            return bt;
        else {
            if (p = BinTreeFind(bt->left, data))
                return p;
            else if (p = BinTreeFind(bt->left, data))
                return p;
            else
                return NULL;
        }
    }
}

void BinTreeClear(ChainBinTree* bt)
{
    if (bt)
    {
        BinTreeClear(bt->left);
        BinTreeClear(bt->right); //清空左右结点
        free(bt); //释放当前结点
        bt = NULL;
    }
    return;
}

void BinTree_DLR(ChainBinTree* bt, void(*poer)(ChainBinTree* p))
{
    if (bt)
    {
        oper(bt); 
        BinTree_DLR(bt->left, oper);
        BinTree_DLR(bt->right, oper);
    }
    return;
}

void BinTree_LDR(ChainBinTree* bt, void(*poer)(ChainBinTree* p))
{
    if (bt)       //树不为空
    {
        
        BinTree_LDR(bt->left, oper);//中序遍历
        oper(bt);
        BinTree_LDR(bt->right, oper);
    }
    return;
}

void BinTree_LRD(ChainBinTree* bt, void(*poer)(ChainBinTree* p))
{
    if (bt)       //树不为空
    {

        BinTree_LDR(bt->left, oper);//中序遍历
        BinTree_LDR(bt->right, oper);
        oper(bt);
    }
    return;
}

void BinTree_level(ChainBinTree* bt, void(*poer)(ChainBinTree* p))
{
    ChainBinTree* p;
    ChainBinTree* q[QUEUE_MAXSIZE];
    int head = 0, tail = 0;
    if (bt)
    {
        tail = (tail + 1) % QUEUE_MAXSIZE; //上一节的那一套
        q[tail] = bt;
    }
    while (head != tail)
    {
        head = (head + 1) % QUEUE_MAXSIZE;
        p = q[head];
        oper(p);
        if (p->left != NULL)
        {
            tail = (tail + 1) % QUEUE_MAXSIZE;
            q[tail] = p->left;
        }
        if (p->right != NULL)
        {
            tail = (tail + 1) % QUEUE_MAXSIZE;
            q[tail] = p->right;
        }
    }
    return;
}
