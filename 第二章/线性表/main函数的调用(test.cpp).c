#include "SqeList.h"
void TestSqueList1()
{
	SL s1;
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);

	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	SeqListPopBack(&s1);
	SeqListPrint(&s1);  //有尾删，但是还要打印

	SeqListDestory(&s1);
}
int main(void)
{
	TestSqueList1();

	return 0;
}
