#define QUEUEMAX  15
typedef struct
{
	long time;
	int num;
}DATA;
typedef struct
{
	DATA data[QUEUEMAX];
	int head;
	int tail;
}CycQueue;
CycQueue* CycQueueInit(); //进行初始化
void CycQueueFree(CycQueue* q); //释放空间
int CycQueueIsEmpty(CycQueue* q);//空的
int CycQueueIsFull(CycQueue* q); //满的
int CycQueueLen(CycQueue* q);//长度
int CycQueueIn(CycQueue* q,DATA data);//入队操作
DATA* CycQueueOut(CycQueue* q); //出队
DATA* CycQueuePeek(CycQueue* q);//获取头文件
