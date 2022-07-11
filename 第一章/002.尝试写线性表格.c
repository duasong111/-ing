//很抱歉，我感觉好多东西真的是不是特别的了解，那个先暂停写到这，我会来进行后续的修改的
#include <stdio.h>
#include <stdlib.h>
#include <SeqList.h>
#define MAXSIZE 10000
#define ERROR 0
#define OK 1
#define OVERFLOW -2
Status InitList(SqList &L); //初始化
Status GetElem(Sqlist L,int i,ElemType &e);//取值
int LocateElem(SqList L,ElemType e); //查找
Status ListInsert(SqList L,int i,ElemType e); //插入
Status ListDelete(SqList &L,int i); //删除


typedef struct
{
    char  no[20];
    char name[50];
    float price;
}Book;
typedef struct
{
    Book *elem; //图书基地址
    int length; //图书个数
}SqList ;   //结构体类型
//主函数
int main(void)
{
    SqList L;
    InitList(L);
    GetElem(L,1,2);
    LocateElem(L,2);
    ListInsert(L,1,2);
    ListDelete(L,2,3);
}
//对顺序表的初始化
Status InitList(SqList &L)
{
    L.elem = new EleType(MAXSIZE);//new是分配一个maxsize的空间
    if(!L.elem) exit(OVERFLOW);
    L.length = 0; //空表长度为0
    return OK;
}
//来进行取值
Status GetElem(Sqlist L,int i,ElemType &e)
{
    int i;
    if(i<1||i>L.length)  return ERROR; //判断i是否合法
    e=L.elem[i-1]; //这个就是相当于数组
    return OK;
}
//顺序表的查找
int LocateElem(SqList L,ElemType e)
{ int i;
    for(i=0;i<L.length;i++)
        if(L.elem[i]==e) return i+1; //说明找到了。
    return 0;  //查找失败
}
//顺序表的插入
Status ListInsert(SqList L,int i,ElemType e)
{
 int i,j;
    if((i<1)||(i>L.length+1)) return ERROR;
    if(L.length ==MAXSIZE) return ERROR;
    for(j=L.length-1;j>=i-1;j--)
        L.elem[j+1] = L.elem[j];
    L.elem[i-1] = e; //将元素插到那个位置
    ++L.length; //表长度增加1
    return OK;
}
//数据元素的删除
Status ListDelete(SqList &L,int i)
{
     int i,j;
     if((i<1)||(i>L.length+1)) return ERROR;
     for(j=i;j<=L.length-1;j++)
        L.elem[j-1]=L.elem[j];
     --L.length; //顺序表的长的减少1
     return OK;
}



























