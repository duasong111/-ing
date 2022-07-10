//其实数据结构也是用c语言写的，但是只不过指针运用的稍微多一些而已.
#include <stdio.h>
#define N 20
int main(void)
{
	int a[N];
	int i,n;
	printf("请输入n");
	scanf_s("%d\n", &n);
	puts("输入");
	for (i = 0; i < n; i++) {
		scanf_s("%d", &a[i]);
	}
	for (i = 0; i < n / 2; i++) {
		int t = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = t;
	}
	puts("输出");
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	return 0;

}
