//main函数的定义
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
#include "SeqStack.h"
int main()
{
	SeqStack* stack;
	DATA data, data1;
	stack = SeqStackInit(); //初始化
	printf("入栈操作：\n");
	printf("输入姓名 年龄 入栈操作：");
	scanf("%s%d", data.name, &data.age);
	SeqStackPush(stack, data);
	printf("输入姓名 年龄 入栈操作");
	scanf("%s%d", data.name, &data.age);
	SeqStackPush(stack, data);
	printf("\n出栈操作：\n 任意键进行出栈操作：");//其实这个没有函数的
	getchar();
	data1 = SeqStackPop(stack);
	printf("出栈的数据是(%s,%d)\n", data.name, &data.age);
	SeqStackPeek(stack);
	getchar();
	return 0;
}   
