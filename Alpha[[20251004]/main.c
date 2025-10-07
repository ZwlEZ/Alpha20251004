#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

//首
void Z_A_A(void)
{
	printf("退出程序输入：0\n加法输入：1\n减法输入：2\n乘法输入：3\n除法输入：4\n");
	int a;
	scanf("%d", &a);
	if (a == 0)
	{
		exit(0);
	}
	else if (a == 1)
	{
		printf("请输入两个数字：\n");
		int b, c;
		scanf("%d%d", &b, &c);
		printf("结果是：%d\n", b + c);
	}
	else if (a == 2)
	{
		printf("请输入两个数字：\n");
		int b, c;
		scanf("%d%d", &b, &c);
		printf("结果是：%d\n", b - c);
	}
	else if (a == 3)
	{
		printf("请输入两个数字：\n");
		int b, c;
		scanf("%d%d", &b, &c);
		printf("结果是：%d\n", b * c);
	}
	else if (a == 4)
	{
		printf("请输入两个数字：\n");
		int b, c;
		scanf("%d%d", &b, &c);
		if (c == 0)
		{
			printf("除数不能为零！\n");
		}
		else
		{
			printf("结果是：%d\n", b / c);
		}
	}
	else
	{
		printf("输入错误，请重新输入！\n");
	}
	return;
}

int main()
{
	printf("欢迎使用。\n");
	Z_A_A();
	return 0;
}