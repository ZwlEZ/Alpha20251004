﻿#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>

//欢迎界面
void Z_A_B(void)
{
	printf(
		"*****======================*****\n"
		"\t*>欢迎使用<*\n"
		"本程序是一个四则运算练习程序\n"
		"你可以选择加减乘除进行练习\n"
		"也可以选择题目的难度和题目数量\n"
		"祝你使用愉快！\n"
		"*****======================*****\n");
	return;
}

//清屏函数
void ClearScreen(void)
{
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
}

//Z_H_A函数清除输入缓冲区
void Z_H_A(void)
{
	int ch = 0;
	while ((ch = getchar()) != '\n' && ch != EOF);
	return;
}

//成绩保存函数
void SaveScore(int total, int correct, int wrong)
{
	FILE* fp = fopen("EXP.txt", "a"); // 追加模式
	if (fp) {
		fprintf(fp, "总题数:%d, 正确:%d, 错误:%d\n", total, correct, wrong);
		fclose(fp);
	}
	else {
		printf("\a\a成绩保存失败！\n");
	}
}

//声明函数Z_F_A
int Z_F_A(int, int, int, int);
//Z_F_B总结函数
void Z_F_B(int i, int E)
{
	int N = i - E;//错误题数
	printf(
		"*****======================*****\n"
		"\t*>总结<*\n"
		"你本次一共做了%d题。\n"
		"你本次答对了%d题。\n"
		"你本次答错了%d题。\n"
		"*****======================*****\n"
		,i , E, N);
	SaveScore(i, E, N);
	return;
}

//Z_C_A项数生成
int Z_C_A(int A)
{
	int q = 0;
	if (A == 1)
	{//生成个位数
		q = rand() % 10;
	}
	else if (A == 2)
	{//生成十位数
		q = rand() % (99 - 10 + 1) + 10;
	}
	else if (A == 3)
	{//生成百位数
		q = rand() % (999 - 100 + 1) + 100;
	}
	else if (A == 4)
	{//生成千位数
		q = rand() % (9999 - 1000 + 1) + 1000;
	}
	else if (A == 5)
	{//生成万位数
		q = rand() % (99999 - 10000 + 1) + 10000;
	}
	return q;
}

//Z_E_A鼓励与表扬
void Z_E_A(int a)
{	
	//1-5随机输出表扬
	if (a == 1)
	{
		printf("  干得漂亮！");
	}
	else if (a == 2)
	{
		printf("  真棒！");
	}
	else if (a == 3)
	{
		printf("  继续加油！");
	}
	else if (a == 4)
	{
		printf("  你是最棒的！");
	}
	else if (a == 5)
	{
		printf("  你真聪明！");
	}
	//鼓励
	if (a == 6)
	{
		printf("  加油，你可以的！");
	}
	else if (a == 7)
	{
		printf("  不要气馁，继续努力！");
	}
	else if (a == 8)
	{
		printf("  失败是成功之母！");
	}
	else if (a == 9)
	{
		printf("  只要努力就会有收获！");
	}
	else if (a == 10)
	{
		printf("  失败乃成功之母！");
	}
	return;
}

//判断整数模块
int Z_D_A(int a, int b)
{
	int E = 0;
	printf("正确答案是：%d  你的答案是：%d", a, b);
	if (a == b)
	{
		++E;
		printf(" √");
		Z_E_A(rand() % 5 + 1);
	}
	else
	{
		printf(" ×");
		Z_E_A(rand() % 5 + 6);
	}
	return E;
}
//判断小数模块
int Z_D_B(float ZDBa, float ZDBb)
{
	float b = (float)((int)(ZDBb * 100 + 0.5)) / 100;
	int E = 0;
	printf("正确答案是：%.2f  你的答案是：%.2f", ZDBa, b);
	if (ZDBa == b)
	{
		++E;
		printf(" √");
		Z_E_A(rand() % 5 + 1);
	}
	else
	{
		printf(" ×");
		Z_E_A(rand() % 5 + 6);
	}
	return E;
}

//Z_B_A加法生成
void Z_B_A(int ZBAa, int ZBAb, int ZBAc)
{
	int a = 0, b = 0, c = 0, d, y, z, sum, i, E = 0;//E为正确题数，a位数选择，b位数选择，c题数选择，d用户输入，y前项，z后项，sum正确答案，i循环变量
	if (ZBAa != 0 && ZBAb != 0 && ZBAc != 0)
	{
		a = ZBAa, b = ZBAb, c = ZBAc;
		printf(
			"\t*>加法运算<*\n"
			"生成功：\n"
		);
	}
	if (a == 0 && b == 0 && c == 0)
	{
		printf("\t*>加法运算<*\n*——————————————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n题目个数不能为0\n*——————————————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
		if (scanf("%d%d%d", &a, &b, &c) != 3)
		{
			printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
			Z_H_A();
			Z_B_A(0, 0, 0);
			return;
		}
	}
	if (a == 0 && b == 0 && c == 0)
	{
		exit(0);
	}
	else if(a < 1 || a > 5 || b < 1 || b > 5 || c < 1)
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_B_A(0,0,0);
		return;
	}
	else
	{
		int T = 1;
		for (i = 0; i < c; i++)
		{
			printf("  第%d提：%d + %d = ", T, z = Z_C_A(a), y = Z_C_A(b));
			sum = z + y;
			if (scanf("%d", &d) != 1)
			{
				printf("\a输入无效，请输入一个数字。\n");
				Z_H_A();
				--i; // 保证本题重新输入
				continue;
			}
			E += Z_D_A(sum, d);
			if(T == c)
				printf("  做完了。\n");
			else
				printf("  题目剩余数量：%d\n", c - T);
			T++;
		}
		if (i == c)
		{
			Z_F_B(i, E);
			Z_F_A(a, b, c, 1);//回调与终结
		}
	}
	return;
}
//Z_B_B减法生成
void Z_B_B(int ZBBa, int ZBBb, int ZBBc)
{
	int a = 0, b = 0, c = 0, d, y, z, sum, i, E = 0;
	if (ZBBa != 0 && ZBBb != 0 && ZBBc != 0)
	{
		a = ZBBa, b = ZBBb, c = ZBBc;
		printf(
			"\t*>减法运算<*\n"
			"生成功：\n"
		);
	}
	if (a == 0 && b == 0 && c == 0)
	{
		printf("\t*>减法运算<*\n*——————————————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n题目个数不能为0\n*——————————————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
		if (scanf("%d%d%d", &a, &b, &c) != 3)
		{
			printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
			Z_H_A();
			Z_B_B(0, 0, 0);
			return;
		}
	}
	if (a == 0 && b == 0 && c == 0)
	{
		exit(0);
	}
	else if (a < 1 || a > 5 || b < 1 || b > 5 || c < 1)
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_B_B(0, 0, 0);
		return;
	}
	else
	{
		int T = 1;
		for (i = 0; i < c; i++)
		{
			printf("  第%d提：%d - %d = ", T, z = Z_C_A(a), y = Z_C_A(b));
			sum = z - y;
			if (scanf("%d", &d) != 1) {
				printf("\a输入无效，请输入一个数字。\n");
				Z_H_A();
				--i; // 保证本题重新输入
				continue;
			}
			E += Z_D_A(sum, d);
			if (T == c)
				printf("  做完了。\n");
			else
				printf("  题目剩余数量：%d\n", c - T);
			T++;
		}
		if (i == c)
		{
			Z_F_B(i, E);
			Z_F_A(a, b, c, 1);//回调与终结
		}
	}
	return;
}
//Z_B_C乘法生成
void Z_B_C(int ZBCa, int ZBCb, int ZBCc)
{
	int a = 0, b = 0, c = 0, d, y, z, sum, i, E = 0;
	if (ZBCa != 0 && ZBCb != 0 && ZBCc != 0) a = ZBCa, b = ZBCb, c = ZBCc;
	if (a == 0 && b == 0 && c == 0)
	{
		printf("\t*>乘法运算<*\n*——————————————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n题目个数不能为0\n*——————————————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
		if (scanf("%d%d%d", &a, &b, &c) != 3)
		{
			printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
			Z_H_A();
			Z_B_C(0, 0, 0);
			return;
		}
	}
	if (a == 0 && b == 0 && c == 0)
	{
		exit(0);
	}
	else if (a < 1 || a > 5 || b < 1 || b > 5 || c < 1)
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_B_C(0, 0, 0);
		return;
	}
	else
	{
		int T = 1;
		for (i = 0; i < c; i++)
		{
			printf("  第%d提：%d × %d = ", T, z = Z_C_A(a), y = Z_C_A(b));
			sum = z * y;
			if (scanf("%d", &d) != 1) {
				printf("\a输入无效，请输入一个数字。\n");
				Z_H_A();
				--i; // 保证本题重新输入
				continue;
			}
			E += Z_D_A(sum, d);
			if (T == c)
				printf("  做完了。\n");
			else
				printf("  题目剩余数量：%d\n", c - T);
			T++;
		}
		if (i == c)
		{
			Z_F_B(i, E);
			Z_F_A(a, b, c, 1);//回调与终结
		}
	}
	return;
}
//Z_B_D_A后项为个位数时除法生成
void Z_B_D_A(int a, int b, int c)
{
	int i, E = 0, T = 1;
	float d, e, h, sum, F;
	wchar_t hao = 0;
	for (i = 0; i < c; i++)
	{
		d = (float)Z_C_A(a);//前项
		e = (float)(rand() % 9 + 1);//生成1-9的随机数，防止除数为0
		sum = d / e;//正确答案
		h = (float)((int)(sum * 100 + 0.5)) / 100;//四舍五入保留两位小数
		if (h == sum)
			hao = '=';//等于
		else
			hao = L'≈';//四舍五入
		wprintf(L"  第%d提：%.0f ÷ %.0f %c ", T, d, e, hao);
		if (scanf("%f", &F) != 1) // 输入等号右边并检查返回值
		{
			printf("\a输入无效，请输入一个数字。\n");
			Z_H_A();
			--i; // 保证本题重新输入
			continue;
		}
		E += Z_D_B(h, F);//判断
		if (T == c)
			printf("  做完了。\n");
		else
			printf("  题目剩余数量：%d\n", c - T);
		T++;
	}
	if (i == c)
	{
		Z_F_B(i, E);
		Z_F_A(a, b, c, 1);//回调与终结
	}
	return;
}
//Z_B_D_B后项不为个位数时除法生成
void Z_B_D_B(int a, int b, int c)
{
	int i, E = 0, T = 1;
	float d, e, h ,sum, F;
	wchar_t hao = 0;
	for (i = 0; i < c; i++)
	{
		d = (float)Z_C_A(a);
		e = (float)Z_C_A(b);
		sum = d / e;
		printf("%.3f", sum);
		h = (float)((int)(sum * 100 + 0.5)) / 100;//四舍五入保留两位小数
		if (h == sum)
			hao = '=';//等于
		else
			hao = L'≈';//四舍五入
		wprintf(L"  第%d提：%.0f ÷ %.0f %c ", T, d, e, hao);
		if (scanf("%f", &F) != 1) // 输入等号右边并检查返回值
		{
			printf("\a输入无效，请输入一个数字。\n");
			Z_H_A();
			--i; // 保证本题重新输入
			continue;
		}
		E += Z_D_B(h, F);//判断
		if (T == c)
			printf("  做完了。\n");
		else
			printf("  题目剩余数量：%d\n", c - T);
		T++;
	}
	if (i == c)
	{
		Z_F_B(i, E);
		Z_F_A(a, b, c, 1);//回调与终结
	}
	return;
}
//Z_B_D除法生成选择器
void Z_B_D(int ZBDa, int ZBDb, int ZBDc)
{
	int a = 0, b = 0, c = 0;
	if (ZBDa != 0 && ZBDb != 0 && ZBDc != 0)
	{
		printf(
			"\t*>除法运算<*\n"
			"生成功：\n"
		);
		a = ZBDa, b = ZBDb, c = ZBDc;
	}
	if (a == 0 && b == 0 && c == 0)
	{
		printf("\t*>除法运算<*\n*——————————————————————————*\n需要输入三个数字\n一次输入用空格，隔开\n也可单次输入，输入三次\n题目个数不能为0\n*——————————————————————————*\n退出程序输入：0 0 0\n个位项输入：1\n十位项输入：2\n百位项输入：3\n千位项输入：4\n万位项输入：5\n");
		if (scanf("%d%d%d", &a, &b, &c) != 3)
		{
			printf("\a××××××××××\n输入无效，请输入三个数字。\n××××××××××\n");
			Z_H_A();
			Z_B_D(0, 0, 0);
			return;
		}
	}
	if (a == 0 && b == 0 && c == 0)
	{
		exit(0);
	}
	else if (a < 1 || a > 5 || b < 1 || b > 5 || c < 1)
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_B_D(0, 0, 0);
		return;
	}
	if (b == 1)
	{
		printf("提示：除法结果保留两位小数。\n");
		Z_B_D_A(a, b, c);
	}
	else
	{
		printf("提示：除法结果保留两位小数。\n");
		Z_B_D_B(a, b, c);
	}
	return;
}

//MIT License
void PrintMITLicense(void)
{
	ClearScreen();
	printf(
		"\n——————————————————————————————————————————————————————————————————————————————————\n"
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
		"——————————————————————————————————————————————————————————————————————————————————\n\n"
	);
}

//显示历史成绩
void ShowScores()
{
	FILE* fp = fopen("EXP.txt", "r");
	char line[128];
	if (fp) {
		ClearScreen();
		printf(
			"+++++++++++++++++++++++++++++++++\n"
			"历史成绩：\n");
		while (fgets(line, sizeof(line), fp)) {
			printf("%s", line);
		}
		printf("+++++++++++++++++++++++++++++++++\n");
		fclose(fp);
	}
	else {
		printf("\a暂无历史成绩。\n");
	}
}

//首
void Z_A_A(void)
{
	printf("\t*>开始<*\n退出程序输入：0\n加法运算输入：1\n减法运算输入：2\n乘法运算输入：3\n除法运算输入：4\n查看《MIT License》输入：5\n");
	int a;
	if (scanf("%d", &a) != 1)
	{
		printf("\a××××××××××\n请按已有的选项输入，数字。\n××××××××××\n");
		Z_H_A();
		Z_A_A();
		return;
	}
	if (a == 0) exit(0);
	else if (a == 1)
	{
		printf(
			"*————————————————————————————————————————————————————————————————————————————————————*\n"
			"提示：加法算式生成\n"
			"输入：1 2 4 （范例）"
			"得：前项取值在零到九之间，后项取值在十到九十九之间，题目数量为4道\n"
			"前两个数字代表位数，最后一个数字代表题目数量\n"
			"根据范例和提示输入即可\n"
			"*————————————————————————————————————————————————————————————————————————————————————*\n"
		);
		Z_B_A(0, 0, 0);
	}
	else if (a == 2)
	{
		printf(
			"*————————————————————————————————————————————————————————————————————————————————————*\n"
			"提示：减法算式生成\n"
			"输入：1 2 4 （范例）"
			"得：前项取值在零到九之间，后项取值在十到九十九之间，题目数量为4道\n"
			"前两个数字代表位数，最后一个数字代表题目数量\n"
			"根据范例和提示输入即可\n"
			"*————————————————————————————————————————————————————————————————————————————————————*\n"
		);
		Z_B_B(0, 0, 0);
	}
	else if (a == 3)
	{
		printf(
			"*————————————————————————————————————————————————————————————————————————————————————*\n"
			"提示：乘法算式生成\n"
			"输入：1 2 4 （范例）"
			"得：前项取值在零到九之间，后项取值在十到九十九之间，题目数量为4道\n"
			"前两个数字代表位数，最后一个数字代表题目数量\n"
			"根据范例和提示输入即可\n"
			"*————————————————————————————————————————————————————————————————————————————————————*\n"
		);
		Z_B_C(0, 0, 0);
	}
	else if (a == 4)
	{
		printf(
			"*————————————————————————————————————————————————————————————————————————————————————*\n"
			"提示：除法算式生成\n"
			"输入：3 1 4 （范例）"
			"得：前项取值在一百到九百九十九之间，后项取值在一到九之间，题目数量为4道\n"
			"前两个数字代表位数，最后一个数字代表题目数量\n"
			"根据范例和提示输入即可\n"
			"*————————————————————————————————————————————————————————————————————————————————————*\n"
		);
		Z_B_D(0, 0, 0);
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

//回调与终结Z_F_A
int Z_F_A(int a, int b, int c,int e)
{
	if(e == 1) 
	{
		printf(
		"**************************************\n"
		"感谢使用本程序。\n"
		"本程序由【ZwlLoveCHN1949101】编写。\n"
		"**************************************\n");
		e = 0;
	}
	printf(
		"*=—————————————————————————————————————————=*\n"
		"\t*>继续<*\n退出程序输入：0\n加法运算输入：1\n减法运算输入：2\n乘法运算输入：3\n除法运算输入：4\n查看《MIT License》输入：5\n"
		"*=—————————————————————————————————————————=*\n"
		"*>>—————————————————————————————————————————<<*\n"
		"按照曾经输入的位数和题数继续出题，\n"
		"加法运算输入：6\n减法运算输入：7\n乘法运算输入：8\n除法运算输入：9\n"
		"*>>—————————————————————————————————————————<<*\n"
		"回顾输入；10，查看历史成绩\n"
	);
	int d;
	if (scanf("%d", &d) != 1)
	{
		printf("\a");
		Z_H_A();
	}
	if (d == 0) exit(0);
	else if (d == 1) Z_B_A(0, 0, 0);
	else if (d == 2) Z_B_B(0, 0, 0);
	else if (d == 3) Z_B_C(0, 0, 0);
	else if (d == 4) Z_B_D(0, 0, 0);
	else if (d == 5)
	{
		PrintMITLicense();
		Z_F_A(a, b, c, 0);
	}
	else if (d == 6) Z_B_A(a, b, c);
	else if (d == 7) Z_B_B(a, b, c);
	else if (d == 8) Z_B_C(a, b, c);
	else if (d == 9) Z_B_D(a, b, c);
	else if (d == 10)
	{
		ShowScores();
		Z_F_A(a, b, c, 0);
	}
	else
	{
		printf("\a——————————————————\n请按已有的选项输入\n——————————————————\n");
		Z_F_A(a, b, c, 0);
	}
	return 0;
}

//主
int main()
{
	setlocale(LC_ALL, "");
	printf("本程序由【ZwlLoveCHN1949101】编写。\n");
	Z_A_B();
	srand((unsigned int)time(NULL));
	Z_A_A();
	return 0;
}