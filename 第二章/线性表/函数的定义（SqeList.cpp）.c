#include "SqeList.h"
void SeqListPrint(SL* ps)
{
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");
} 
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}
void SeqListDestory(SL* ps)
{
	free(ps->a);
	ps->a = NULL;
    //ps->capacity == ps->size = 0;
}
//void SeqListInit(SL* ps);
void SeqListPushBack(SL* ps, SLDaTaType x)
{ //若果没有空间或者说空间不足，那么就开始扩容
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity ==0 ? 4:ps->capacity*2;
		SLDaTaType* tmp = (SLDaTaType*)realloc(ps->a, newcapacity * sizeof(SLDaTaType));
		if (tmp == NULL) 
		{
			printf("realloc fail \n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newcapacity;

	}
	ps->a[ps->size] = x;
	ps->size++; //要扩容一个空间
}
void SeqListPopBack(SL* ps) {
	ps->a[ps->size - 1] = 0;
	ps->size--;//主要
}
void SeqListPushFront(SL* ps, SLDaTaType x);
void SeqListPopFront(SL* ps);
