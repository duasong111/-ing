#include "SqeQueue.h"
#include <stdio.h>
#include <stdlib.h> //对应的malloc分配空间
CycQueue* CycQueueInit()
{
    CycQueue* q; //指针，为了指向地址
    if (q = (CycQueue*)malloc(sizeof(CycQueue)))
    {
        q->head = 0; //使其头和尾开始都为0
        q->tail = 0;
        return q;
    }else
    return NULL;
}
void CycQueueFree(CycQueue* q)
{
    if (q != NULL)
        free(q); //空间的释放
}
 
int CycQueueIsEmpty(CycQueue* q)
{
    return (q->head==q->tail);
}
 
int CycQueueIsFull(CycQueue* q)
{
    return ((q->tail+1)% QUEUEMAX==q->head);
}
 
 
int CycQueueIn(CycQueue* q, DATA data) //入队操作
{
    if ((q->tail+1) % QUEUEMAX==q->head)
    {
        printf("队列已满！\n");
        return 0;
    }
    else {
        q->tail = (q->tail + 1) % QUEUEMAX;
        q->data[q->tail++] = data;
        return 1;
    }
}
 
DATA* CycQueueOut(CycQueue* q)
{
    if (q->head == q->tail)
    {
        printf("\n队列已空！\n");
        return NULL;
    }
    else {
        q->head = (q->head + 1) % QUEUEMAX; //那个求余的方法
        return &(q->data[q->head++]);
    }
}
 
int CycQueueLen(CycQueue* q)
{
    
    int n;
    n = q->tail - q->head;
    if (n < 0)
        n = QUEUEMAX + n;
    return n/2;
}
 
 
DATA* CycQueuePeek(CycQueue* q)
{
    if (q->head==q->tail)
    {
        printf("\n队列为空!\n");
        return NULL;
    }
    else {
        return &(q->data[(q->head+1)%QUEUEMAX]);
    }
    
}
