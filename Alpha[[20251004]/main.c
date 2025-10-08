#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Z_C_A项数生成
int Z_C_A(int A)
{
	int q = 0;
	int* Pq = &q;
	if (A == 1)
	{//生成个位数
		*Pq = rand() % 10;
	}
	else if (A == 2)
	{//生成十位数
		*Pq = rand() % (99 - 10 + 1) + 10;
	}
	else if (A == 3)
	{//生成百位数
		*Pq = rand() % (999 - 100 + 1) + 100;
	}
	else if (A == 4)
	{//生成千位数
		*Pq = rand() % (9999 - 1000 + 1) + 1000;
	}
	else if (A == 5)
	{//生成万位数
		*Pq = rand() % (99999 - 10000 + 1) + 10000;
	}
	return q;
}

//Z_B_A加法生成
void Z_B_A(void)
{
	printf("*>加法运算<*\n*——————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n前两个数字为算式前后两项的位\n后一个数字是题目的倒数\n*——————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
	int a, b, c, i;//a位数选择，b位数选择，c题数选择，i循环变量
	if (scanf("%d%d%d", &a, &b, &c) != 3)
	{
		printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
		//清空输入缓冲区
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);
		Z_B_A();
		return;
	}
	for ( i = 0; i < c; i++)
	{
		printf("%d + %d = \n", Z_C_A(a), Z_C_A(b));

	}
	return;
}
//Z_B_B减法生成
void Z_B_B(void)
{
	return;
}
//Z_B_C乘法生成
void Z_B_C(void)
{
	return;
}
//Z_B_D_A后项为个位数时除法生成
void Z_B_D_A(void)
{
	return;
}
//Z_B_D_B后项不为个位数时除法生成
void Z_B_D_B(void)
{
	return;
}
//Z_B_D除法生成选择器
void Z_B_D(void)
{
	return;
}

//首
void Z_A_A(void)
{
	printf("退出程序输入：0\n加法运算输入：1\n减法运算输入：2\n乘法运算输入：3\n除法运算输入：4\n");
	int a;
	if (scanf("%d", &a) != 1)
	{
		printf("\a××××××××××\n请按已有的选项输入，数字。\n××××××××××\n");
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);
		Z_A_A();
		return;
	}
	if (a == 0)
	{
		exit(0);
	}
	else if (a == 1)
	{
		Z_B_A();
	}
	else if (a == 2)
	{
		Z_B_B();
	}
	else if (a == 3)
	{
		Z_B_C();
	}
	else if (a == 4)
	{
		Z_B_D();
	}
	else
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_A_A();
	}
	return;
}

int main()
{
	printf("欢迎使用。\n");
	Z_A_A();
	srand((unsigned int)time(NULL));
	return 0;
}