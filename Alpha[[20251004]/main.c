#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

#include "结构体和宏定义并声明.h"
#include "函数声明.h"
#include "数生成.h"

int main(void)
{
	setlocale(LC_ALL, "zh_CN.UTF-8");
	ShowWelcomeMessage();
	srand((unsigned int)time(NULL));// 种子
	// 创建指令实例
	指令类* 执行 = 初始化运行时();
	if (!执行)
	{
		wprintf(L"内存分配失败\n");
		return -1;
	}
	// 主程序循环
	while (执行->工作)
	{
		switch (执行->工作)
		{
		case 开始: 开始菜单打印(); break;
		case 继续: 继续菜单打印(); break;
		}
		int choice = 选择命令(执行);
		if (choice == -1)
		{
			wprintf(L"输入错误\n");
			break;
		}
		else if (choice == -2)
		{
			wprintf(L"用户退出\n");
			break;
		}
		执行->过程 = (unsigned char)choice;
		执行->工作 = 回调函数(执行);
	}
	free(执行);
	return 0;
}

int 回调函数(指令类* 执行)
{
	switch (执行->工作)
	{
	case 开始:
		switch (执行->过程)
		{
		case 结束:
			return 结束;
		case 加法:
		case 减法:
		case 乘法:
			加减乘运算练习引导加载器(执行);
			加减乘运算练习(执行);
			return 继续;
		case 5:
			PrintMultiplicationTable();
			执行->过程 = 0;
			return 开始;
		case 6:
			PrintMITLicense();
			执行->过程 = 0;
			return 开始;
		default:
			wprintf(
				L"\a——————————————————\n"
				L"请按已有的选项输入\n"
				L"——————————————————\n");
		}
		break;
	case 继续:
		switch (执行->过程)

		break;
	}
	if (执行->工作 == 开始) // 状态机
		return 开始;
	else
		return 继续;
}

int 选择命令(指令类* 执行)
{
	char input[256];
	switch (执行->工作)
	{
	case 开始:
		while (1)
		{
			if (fgets(input, sizeof(input), stdin) == NULL)
			{
				return -1; // 错误或EOF
			}
			// 去除换行符
			input[strcspn(input, "\n")] = '\0';
			// 检查退出命令
			if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
			{
				return -2;  // 退出信号
			}
			// 检查空输入
			if (strlen(input) == 0)
			{
				wprintf(L"请输入选项: ");
				continue;
			}
			// 解析数字
			int choice;
			if (sscanf(input, "%d", &choice) == 1)
			{
				if (choice >= 0 && choice <= 255)
				{
					switch (choice)
					{
					case 1: return 200;
					}
				}
				else
				{
					wprintf(L"\a选项必须在 0-255 范围内\n");
				}
			}
			else
			{
				wprintf(L"\a请输入有效的数字选项\n");
			}

			wprintf(L"请重新输入: ");
		}
		break;
	case 继续:
		while (1)
		{
			if (fgets(input, sizeof(input), stdin) == NULL)
			{
				return -1;
			}
			input[strcspn(input, "\n")] = '\0';
			if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
			{
				return -2;
			}
			if (strlen(input) == 0)
			{
				wprintf(L"请输入选项: ");
				continue;
			}
			int choice;
			if (sscanf(input, "%d", &choice) == 1)
			{
				if (choice >= 0 && choice <= 255)
				{
					return choice;
				}
				else
				{
					wprintf(L"\a选项必须在 0-255 范围内\n");
				}
			}
			else
			{
				wprintf(L"\a请输入有效的数字选项\n");
			}

			wprintf(L"请重新输入: ");
		}
		break;
	}
	return 0;
}

指令类* 初始化运行时(void)
{
	指令类* rt = (指令类*)malloc(sizeof(指令类));
	if (rt)
	{
		rt->工作 = 1;
		rt->过程 = 0;
		rt->前项位 = 1;  // 默认个位
		rt->后项位 = 1;  // 默认个位
		rt->题目数 = 10; // 默认10题
		rt->当前题目 = 0;
		rt->正确题数 = 0;
		rt->错误题数 = 0;
	}
	return rt;
}

void 加减乘运算练习引导加载器(指令类* 执行)
{
	wprintf(L"导加载器");
	return;
}
void 加减乘运算练习(指令类* 执行)
{
	wprintf(L"运算练习");
	return;
}

// 欢迎界面
void ShowWelcomeMessage(void)
{
	wprintf(
		L"本程序由【ZwlLoveCHN1949101】编写。\n"
		L"*****======================*****\n"
		L"\t*>欢迎使用<*\n"
		L"本程序是一个四则运算练习程序\n"
		L"你可以选择加减乘除进行练习\n"
		L"也可以选择题目的难度和题目数量\n"
		L"祝你使用愉快！\n"
		//L"此程序为第三代\n"
		L"程序实验中\n"
		L"*****======================*****\n");
	return;
}

void 开始菜单打印(void)
{
	wprintf(
		L"\t*>开始<*\n"
		L"退出程序输入：0\n"
		L"加法运算输入：1\n"
		L"减法运算输入：2\n"
		L"乘法运算输入：3\n"
		L"除法运算输入：4\n"
		L"查看九九乘法表输入：5\n"
		L"查看《MIT License》输入：6\n");
	return;
}
void 继续菜单打印(void)
{

	return;
}

// 清屏函数
void ClearScreen(void)
{
#if defined(_WIN32) || defined(_WIN64)
	system("cls");
#else
	system("clear");
#endif
}

// 九九乘法表
void PrintMultiplicationTable(void)
{
	unsigned char row, col;
	wprintf(L"\n*×========================================================================================================================================================×*\n");
	for (row = 1; row <= 9; row++)
	{
		for (col = 1; col <= 9; col++)
		{
			wprintf(L"\t%d × %d = %d", col, row, row * col);
			if (row == col)
			{
				wprintf(L"\n");
				break;
			}
		}
	}
	wprintf(L"*×========================================================================================================================================================×*\n");
	return;
}

// MIT License
void PrintMITLicense(void)
{
	ClearScreen();
	wprintf(
		L"\n————————————————————————————————————————————————————————————————————————————————————————————\n"
		L"\tMIT License\n\n"
		L"\tCopyright (c) 2025 ZwlLoveCHN1949101\n\n"
		L"\tPermission is hereby granted, free of charge, to any person obtaining a copy\n"
		L"\tof this software and associated documentation files (the \"Software\"), to deal\n"
		L"\tin the Software without restriction, including without limitation the rights\n"
		L"\tto use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
		L"\tcopies of the Software, and to permit persons to whom the Software is\n"
		L"\tfurnished to do so, subject to the following conditions:\n\n"
		L"\tThe above copyright notice and this permission notice shall be included in all\n"
		L"\tcopies or substantial portions of the Software.\n\n"
		L"\tTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
		L"\tIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
		L"\tFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
		L"\tAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
		L"\tLIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
		L"\tOUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
		L"\tSOFTWARE.\n"
		L"————————————————————————————————————————————————————————————————————————————————————————————\n\n"
	);
}
