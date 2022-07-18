//这个是头文件。
#define SIZE 50
typedef struct
{
	char name[15];
	int age;
}DATA;
typedef struct stack
{
	DATA data[SIZE + 1];
	int top;
	int base;
}SeqStack;
SeqStack* SeqStackInit(); //初始化栈
void SeqStackFree(SeqStack* s);//释放栈
int SeqStackIsEmpty(SeqStack* s);
void SeqStackClear(SeqStack* s);  
int SeqStackIsFull(SeqStack* s); //上边三个都是判断栈的状态
int SeqStackPush(SeqStack* s,DATA data);//入栈操作
DATA SeqStackPop(SeqStack* s); //出栈
DATA SeqStackPeek(SeqStack* s); //栈顶元素
