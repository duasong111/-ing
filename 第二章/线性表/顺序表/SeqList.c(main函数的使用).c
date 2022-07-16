//main函数的使用
#include <stdio.h>
#include "SeqList.h"
int SeqListALL(SeqListType* SL)
{
	int i;
	for (i = 1; i <= SL->ListLen; i++)
		printf("(%s,%s,%d)\n", SL->ListData[i].key, SL->ListData[i].name, SL->ListData[i].age);
	return 0;
}
int main()
{
	int i;
	SeqListType SL;
	DATA data, * data1;
	
	char key[15];
	SeqListInit(&SL);

	do {
		printf("请输入添加的结点（学号 姓名 年龄）:");
		fflush(stdin);
		scanf("%s%s%d", &data.key, &data.name, &data.age);
		if (data.age)
		{
			if (!SeqListAdd(&SL, data))
			break;
		}
		else
			break;
	} while (1);
	printf("\n顺序表中的结点顺序为:\n");
	SeqListALL(&SL); //这个是进行结点的打印输出


	//这个是对元素的增加
	do {
		printf("\n插入的结点（学号 姓名 年龄 结点位置）:\n");
		fflush(stdin);
		scanf("%s%s%d%d", &data.key, &data.name, &data.age,&i);
		if (data.age)
		{
			if (!SeqListInsert(&SL,i,data))
				break;
		} //SeqListInsert(SeqListType* SL, int n, DATA data)
		else
			break;
	} while (1);
	//printf("此时的长度%d", SL->ListLen);
	// SeqListInsert(SeqListType * SL, int n, DATA data)
	fflush(stdin);
	printf("\n要取出结点的序号：");
	scanf("%d", &i);

	data1 = SeqListFindByNum(&SL, i);
	if (data1)
		printf("第%d个结点为：(%s,%s,%d)\n", i, data1->key, data1->name, data1->age);
	fflush(stdin);  //还是要请空缓冲区
	printf("\n查找的结点关键字：");
	scanf("%s", key);
	i = SeqListFindByCont(&SL, key);
	data1 = SeqListFindByNum(&SL, i);
	if (data1)
		printf("第%d个结点为：(%s,%s,%d)\n", i, data1->key, data1->name, data1->age);
	getchar();
	return 0;

}
