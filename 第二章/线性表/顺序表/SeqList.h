//这个是头文件
#include <stdio.h>
#include <string.h>
#define MAXSIZE 100
typedef struct
{
	char key[15];
	char name[20];
	int age;
} DATA;
typedef struct
{
	DATA ListData[MAXSIZE + 1];
	int ListLen;
}SeqListType;

void SeqListInit(SeqListType* SL);
int  SeqListLength(SeqListType* SL);
int SeqListAdd(SeqListType* SL,DATA data);
int SeqListInsert(SeqListType* SL,int n, DATA data);
int SeqListDelete(SeqListType* SL, int n);
DATA* SeqListFindByNum(SeqListType* SL, int n);
int SeqListFindByCont(SeqListType* SL, char *key);
int  SeqListALL(SeqListType* SL);
