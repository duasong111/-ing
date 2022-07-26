#include "SqeQueue.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int num;
void add(CycQueue* q)
{
	DATA data;
	if (!CycQueueIsFull(q))
	{
		data.num = num++;
		data.time = time(NULL);
		CycQueueIn(q, data);
	}
	else
		printf("排队的太多，请稍后在排队！\n");
}
void  next(CycQueue* q)
{
	DATA* data;
	if (!CycQueueIsFull(q))
	{
		data = CycQueueOut(q);
		printf("\n正在为编号为%d的顾客办理业务！\n", data->num);
	}
	if (!CycQueueIsFull(q))
	{
		data = CycQueuePeek(q);
		printf("请编号为%d的顾客准备，马上将为您办理业务!\n", data->num);
	}
}
int main()
{
	CycQueue* queue1;
	int i, n,choose;
	int select;
	num = 0;
	queue1 = CycQueueInit(); //初始化队列
	if (queue1 == NULL)
	{
		printf("创建队列出错！\n");
		getchar();
		return 0;
	}
	do {
		
		printf("\n1.新的顾客:\n");
		printf("\n2.next one\n");
		printf("\n0.out\n");
		printf("\n请选择具体的操作:");
		//fflush(stdin); //键盘的输入
		scanf_s("%d", &choose);
		select = choose;
		switch(select)
		{
		case 1:add(queue1); 
			printf("\n现在共有%d为顾客在等候！\n", CycQueueLen(queue1)); break;
		case 2:next(queue1);
			printf("\n现在共有%d为顾客在等候！\n", CycQueueLen(queue1)); break;
		case 0: break;
		}
 
	} while (select != 0);
	CycQueueFree(queue1);
	getchar();
	return 0;
}
