#pragma once
#include <stdio.h>
#include <stdlib.h>
#define N 100
typedef int SLDaTaType; //类型可以换（int）
//动态的顺序表
typedef struct SeqList
{
	SLDaTaType *a;
	int size;  //储存了多少数据
	int capacity; //数组的空间容量的大小
}SL;
//接口函数
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);

void SeqListDestory(SL* ps);

void SeqListPushBack(SL* ps, SLDaTaType x);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDaTaType x);
void SeqListPopFront(SL* ps);
