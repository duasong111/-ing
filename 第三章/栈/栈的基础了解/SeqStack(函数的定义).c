//函数的定义
#include "SeqStack.h"
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
SeqStack* SeqStackInit()
{
	SeqStack* p;
	if (p = (SeqStack*)malloc(sizeof(SeqStack)))
	{
		p->top = 0; //设置栈顶为0
		return p;
	}
	return NULL;
}
void SeqStackFree(SeqStack* s)
{
	if (s)
		free(s);//空间的释放
}

int SeqStackIsEmpty(SeqStack* s)
{
	return (s->top==0); //判断栈顶是否为空
}

void SeqStackClear(SeqStack* s)
{
	s->top = 0; //清空栈
}

int SeqStackIsFull(SeqStack* s)
{
	return (s->top== SIZE);
}
int SeqStackPush(SeqStack* s, DATA data)
{    
	if ((s->top + 1) > SIZE)
	{
		printf("栈溢出\n");
		return 0;
	}
	s->data[++s->top] = data;
	return 1;	
}
DATA SeqStackPop(SeqStack* s)
{
	if (s->top == 0)
	{
		printf("栈为空！");
		exit(0);
	}
	return (s->data[s->top--]);
}

DATA SeqStackPeek(SeqStack* s)
{
	if (s->top == 0)
	{
		printf("栈为空！");
		exit(0);
	}
	return(s->data[s->top]);
}
