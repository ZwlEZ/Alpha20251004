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

//Z_E_A鼓励与表扬
void Z_E_A(int a)
{
	if (a == 1)
	{
		printf("干得漂亮！\n");
	}
	else if (a == 2)
	{
		printf("真棒！\n");
	}
	else if (a == 3)
	{
		printf("继续加油！\n");
	}
	else if (a == 4)
	{
		printf("你是最棒的！\n");
	}
	else if (a == 5)
	{
		printf("你真聪明！\n");
	}
	return;
}

//判断整数模块
void Z_D_A(int a, int b)
{
	printf("正确答案是：%d", a);
	printf("  你的答案是：%d\n", b);
	if (a == b)
	{

	}
	else
	{

	}
	return;
}
//判断小数模块
void Z_D_B(float a, float b)
{
	printf("正确答案是：%.2f", a);
	printf("  你的答案是：%.2f\n", b);
	return;
}

//Z_B_A加法生成
void Z_B_A(void)
{
	printf("*>加法运算<*\n*——————————————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n前两个数字为算式前后两项的位\n后一个数字是题目的倒数\n题目个数不能为0\n*——————————————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
	int a, b, c, d, y, z, sum, i;//a位数选择，b位数选择，c题数选择，d用户输入，y前项，z后项，sum正确答案，i循环变量
	if (scanf("%d%d%d", &a, &b, &c) != 3)
	{
		printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);
		Z_B_A();
		return;
	}
	if (a == 0 && b == 0 && c == 0)
	{
		exit(0);
	}
	else if(a < 1 || a > 5 || b < 1 || b > 5 || c < 1)
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_B_A();
		return;
	}
	else
	{
		for (i = 0; i < c; i++)
		{
			printf("%d + %d = ", z = Z_C_A(a), y = Z_C_A(b));
			sum = z + y;
			scanf("%d", &d);
			Z_D_A(sum, d);
		}
	}
	return;
}
//Z_B_B减法生成
void Z_B_B(void)
{
	printf("*>减法运算<*\n*——————————————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n前两个数字为算式前后两项的位\n后一个数字是题目的倒数\n题目个数不能为0\n*——————————————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
	int a, b, c, d, y, z, sum, i;
	if (scanf("%d%d%d", &a, &b, &c) != 3)
	{
		printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);
		Z_B_B();
		return;
	}
	if (a == 0 && b == 0 && c == 0)
	{
		exit(0);
	}
	else if (a < 1 || a > 5 || b < 1 || b > 5 || c < 1)
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_B_B();
		return;
	}
	else
	{
		for (i = 0; i < c; i++)
		{
			printf("%d - %d = ", z = Z_C_A(a), y = Z_C_A(b));
			sum = z - y;
			scanf("%d", &d);
			Z_D_A(sum, d);
		}
	}
	return;
}
//Z_B_C乘法生成
void Z_B_C(void)
{
	printf("*>乘法运算<*\n*——————————————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n前两个数字为算式前后两项的位\n后一个数字是题目的倒数\n题目个数不能为0\n*——————————————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
	int a, b, c, d, y, z, sum, i;
	if (scanf("%d%d%d", &a, &b, &c) != 3)
	{
		printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);
		Z_B_C();
		return;
	}
	if (a == 0 && b == 0 && c == 0)
	{
		exit(0);
	}
	else if (a < 1 || a > 5 || b < 1 || b > 5 || c < 1)
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_B_C();
		return;
	}
	else
	{
		for (i = 0; i < c; i++)
		{
			printf("%d × %d = ", z = Z_C_A(a), y = Z_C_A(b));
			sum = z * y;
			scanf("%d", &d);
			Z_D_A(sum, d);
		}
	}
	return;
}
//Z_B_D_A后项为个位数时除法生成
void Z_B_D_A(int a, int b, int c)
{
	for (int i = 0; i < c; i++)
	{
		float d = (float)Z_C_A(a);//前项
		float e = (float)Z_C_A(b);//后项
		float sum = d / e;
		float F;
		if (e == 0)
			++e;//防止除数为0
		printf("%.2f ÷ %.2f = ", d, e);//提示
		scanf("%f", &F);//输入等号右边
		Z_D_B(sum, F);//判断模块
	}
	return;
}
//Z_B_D_B后项不为个位数时除法生成
void Z_B_D_B(int a, int b, int c)
{
	for (int i = 0; i < c; i++)
	{
		float d = (float)Z_C_A(a);
		float e = (float)Z_C_A(b);
		float sum = d / e;
		float F;
		printf("%.2f ÷ %.2f = ",d , e);
		scanf("%f", &F);
		Z_D_B(sum, F);
	}
	return;
}
//Z_B_D除法生成选择器
void Z_B_D(void)
{
	printf("*>除法运算<*\n*——————————————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n前两个数字为算式前后两项的位\n后一个数字是题目的倒数\n题目个数不能为0\n*——————————————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
	int a, b, c;
	if (scanf("%d%d%d", &a, &b, &c) != 3)
	{
		printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
		int ch;
		while ((ch = getchar()) != '\n' && ch != EOF);
		Z_B_D();
		return;
	}
	if (a == 0 && b == 0 && c == 0)
	{
		exit(0);
	}
	else if (a < 1 || a > 5 || b < 1 || b > 5 || c < 1)
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_B_D();
		return;
	}
	if (b == 1)
	{
		Z_B_D_A(a, b, c);
	}
	else
	{
		Z_B_D_B(a, b, c);
	}
	return;
}

//MIT License
void PrintMITLicense(void)
{
	printf(
		"\n-------------------------------------------------------------------------------------------\n"
		"MIT License\n\n"
		"Copyright (c) 2025 ZwlLoveCHN1949101\n\n"
		"Permission is hereby granted, free of charge, to any person obtaining a copy\n"
		"of this software and associated documentation files (the \"Software\"), to deal\n"
		"in the Software without restriction, including without limitation the rights\n"
		"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
		"copies of the Software, and to permit persons to whom the Software is\n"
		"furnished to do so, subject to the following conditions:\n\n"
		"The above copyright notice and this permission notice shall be included in all\n"
		"copies or substantial portions of the Software.\n\n"
		"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
		"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
		"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
		"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
		"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
		"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
		"SOFTWARE.\n"
		"-------------------------------------------------------------------------------------------\n\n"
	);
}

//首
void Z_A_A(void)
{
	printf("退出程序输入：0\n加法运算输入：1\n减法运算输入：2\n乘法运算输入：3\n除法运算输入：4\n查看《MIT License》输入：5\n");
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
	else if (a == 5)
	{
		PrintMITLicense();
		Z_A_A();
	}
	else
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_A_A();
	}
	return;
}

//Z测试函数
char Z_test(float a)
{
	char s[] = { 0 };
	char* p = s;
	
	return s;
}


//主
int main()
{
	printf("欢迎使用。\n");
	printf("本程序由【ZwlLoveCHN1949101】编写。\n");
	srand((unsigned int)time(NULL));
	Z_A_A();
	return 0;
}