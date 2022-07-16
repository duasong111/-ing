//函数的使用
#include "SeqList.h"
void SeqListInit(SeqListType* SL)
{
	SL->ListLen = 0; //新建链表
}
int SeqListLength(SeqListType* SL)
{

	return (SL->ListLen);//返回链表的长度
}
int SeqListAdd(SeqListType* SL, DATA data)
{
   //先判断链表是否满
	if (SL->ListLen >= MAXSIZE) {
		printf("链表已满，不能再添加\n");
			return 0;
	}
	SL->ListData[++SL->ListLen] = data;//将新的元素添加里边
}
int SeqListInsert(SeqListType* SL, int n, DATA data)
{
	if (SL->ListLen >= MAXSIZE) {
		printf("链表已满，不能再插入\n");
		return 0;
	}
	if (n > SL->ListLen - 1 || n < 1) {
		printf("插入结点的序号错误");
		return 0;
	}
	//成功的条件是
	for (int i = SL->ListLen; i >= n; i--)
		SL->ListData[i + 1] = SL->ListData[i];
	SL->ListData[n] = data;
	SL->ListLen++;
	return 1;
}
int SeqListDelete(SeqListType* SL, int n)
{  //n是指删除的结点
	int i;
	if(n<1 || n>SL->ListLen + 1)
	{
		printf("删除序号错误,不能删除结点:\n");
		return 0;
	}
	for (i = n; i < SL->ListLen; i++)
		SL->ListData[i] = SL->ListData[i + 1];
	SL->ListLen--; //链表的总数减少1
	return 1;
}

DATA* SeqListFindByNum(SeqListType* SL, int n)
{
	if (n<1 || n>SL->ListLen + 1)
	{
		printf("结点序号错误，不能返回结点！\n");
		return NULL;
	}
	return &(SL->ListData[n]);
}
int SeqListFindByCont(SeqListType* SL, char* key)
{
	int i;
	for (i = 1; i <= SL->ListLen; i++)
		if (strcmp(SL->ListData[i].key, key) == 0)//查找结点
			return i;  //返回结点的序号
	return 0;
}
