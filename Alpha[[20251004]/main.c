#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>
#include<stdbool.h>

#include "结构体和宏定义并声明.h"
#include "函数声明.h"
#include "数生成.h"

int main(void)
{
	设置UTF8编码();
	ShowWelcomeMessage();
	srand((unsigned int)time(NULL));// 种子
	// 创建指令实例
	指令类* 执行 = 初始化运行时();
	if (!执行)
	{
		倒计时提醒(L"内存分配失败", 3);
		return -1;
	}
	// 主程序循环
	while (执行->工作)
	{
		switch (执行->工作)
		{
		case 开始: 开始菜单打印(); 执行->菜单 = 开始菜单; break;
		case 继续: 继续菜单打印(执行); 执行->菜单 = 继续菜单; break;
		}
		// 检查是否结束
		if (选择命令(执行) == 0) break;
		回调函数(执行);
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
		case 结束: return 结束;
		case 加法:
		case 减法:
		case 乘法:
		case 除法:
			加减乘除运算练习引导加载器(执行);
			善后工作(执行);
			return 执行->工作 = 继续;
		case 5:
			PrintMultiplicationTable();
			执行->过程 = 完成;
			return 执行->工作 = 开始;
		case 6:
			PrintMITLicense();
			执行->过程 = 完成;
			return 执行->工作 = 开始;
		}
		break;
	case 继续:
		switch (执行->过程)
		{
		case 结束: return 结束;
		case 加法:
		case 减法:
		case 乘法:
		case 除法:
			加减乘除运算练习引导加载器(执行);
			善后工作(执行);
			return 执行->工作 = 继续;
		case 回调加法:
		case 回调减法:
		case 回调乘法:
		case 回调除法:
			加减乘除运算练习引导重载(执行);
			善后工作(执行);
			return 执行->工作 = 继续;
		case 10:
			PrintMultiplicationTable();
			执行->过程 = 完成;
			return 执行->工作 = 继续;
		case 11:
			PrintMITLicense();
			执行->过程 = 完成;
			return 执行->工作 = 继续;
		}
		break;
	default:
		wprintf(
			L"\a——————————————————\n"
			L"请按已有的选项输入\n"
			L"——————————————————\n");
	}
	// 状态机
	if (执行->工作 == 开始)
		return 执行->工作 = 开始;
	else return 执行->工作 = 继续;	
}

int 选择命令(指令类* 执行)
{
	char input[256];
	if ((执行->工作 == 开始) && (执行->菜单 == 开始菜单))
	{
		while (开始菜单)
		{
			if (fgets(input, sizeof(input), stdin) == NULL)
			{
				return -1; // 错误或EOF
			}
			// 去除换行符
			input[strcspn(input, "\n")] = '\0';
			// 热命令
			if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
			{
				free(执行);
				exit(0);
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
					case 0: return 执行->工作 = 0;
					case 1: 执行->过程 = 执行->运算类型 = 加法; 执行->菜单 = 完成; return 加法;
					case 2: 执行->过程 = 执行->运算类型 = 减法; 执行->菜单 = 完成; return 减法;
					case 3: 执行->过程 = 执行->运算类型 = 乘法; 执行->菜单 = 完成; return 乘法;
					case 4:	执行->过程 = 执行->运算类型 = 除法; 执行->菜单 = 完成; return 除法;
					case 5:	执行->菜单 = 完成; return 执行->过程 = 5;
					case 6: 执行->菜单 = 完成; return 执行->过程 = 6;
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
	}
	// 继续菜单处理
	if ((执行->工作 == 继续) && (执行->菜单 == 继续菜单))
	{
		while (继续菜单)
		{
			if (fgets(input, sizeof(input), stdin) == NULL) return -1;
			input[strcspn(input, "\n")] = '\0';
			if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0)
			{
				free(执行);
				exit(0);
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
					switch (choice)
					{
					case 0: return 执行->工作 = 0;
					case 1: 执行->过程 = 执行->运算类型 = 加法; 执行->菜单 = 完成; return 加法;
					case 2: 执行->过程 = 执行->运算类型 = 减法; 执行->菜单 = 完成; return 减法;
					case 3: 执行->过程 = 执行->运算类型 = 乘法; 执行->菜单 = 完成; return 乘法;
					case 4:	执行->过程 = 执行->运算类型 = 除法; 执行->菜单 = 完成; return 除法;
					case 5: 执行->过程 = 回调加法; 执行->运算类型 = 加法; 执行->菜单 = 完成; return 加法;
					case 6: 执行->过程 = 回调减法; 执行->运算类型 = 减法; 执行->菜单 = 完成; return 减法;
					case 7: 执行->过程 = 回调乘法; 执行->运算类型 = 乘法; 执行->菜单 = 完成; return 乘法;
					case 8:	执行->过程 = 回调除法; 执行->运算类型 = 除法; 执行->菜单 = 完成; return 除法;
					case 10: 执行->菜单 = 完成; return 执行->过程 = 10;
					case 11: 执行->菜单 = 完成; return 执行->过程 = 11;
					}
				}
				else wprintf(L"\a选项必须在 0-255 范围内\n");
			}
			else wprintf(L"\a请输入有效的数字选项\n");
			wprintf(L"请重新输入: ");
		}
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
		rt->前项位 = 0;
		rt->后项位 = 0;
		rt->题目数 = 0;
		rt->运算类型 = 0;
		rt->正确题数 = 0;
		/*rt->当前题目 = 0;
		rt->错误题数 = 0;*/
	}
	return rt;
}

void 运算类菜单(指令类* 执行)
{
	switch (执行->运算类型)
	{
	case 加法:
		wprintf(
			L"*————————————————————————————————————————————————————————————————————————————————————*\n"
			L" 提示：加法算式生成\n"
			L" 输入：1 2 4 （范例）\n"
			L" 得：前项取值在零到九之间，后项取值在十到九十九之间，题目数量为4道\n"
			L" 前两个数字代表位数，最后一个数字代表题目数量\n"
			L" 根据范例和提示输入即可\n"
			L"*————————————————————————————————————————————————————————————————————————————————————*\n"
			L"\t*>加法运算<*\n"
			L"*——————————————————————————*\n"
			L" 需要输入三个数字\n"
			L" 一次输入用空格隔开\n"
			L" 题目个数不能为0\n"
			L"*——————————————————————————*\n"
			L"+>>——————————————————————————<<+\n"
			L"   退出程序输入：0\n"
			L"   个位项输入：1\n"
			L"   十位项输入：2\n"
			L"   百位项输入：3\n"
			L"   千位项输入：4\n"
			L"   万位项输入：5\n"
			L"+>>——————————————————————————<<+\n");
		break;
	case 减法:
		wprintf(
			L"*————————————————————————————————————————————————————————————————————————————————————*\n"
			L" 提示：减法算式生成\n"
			L" 输入：2 1 5 （范例）\n"
			L" 得：前项取值在十到九十九之间，后项取值在零到九之间，题目数量为5道\n"
			L" 确保结果为非负数，前项≥后项\n"
			L" 前两个数字代表位数，最后一个数字代表题目数量\n"
			L"*————————————————————————————————————————————————————————————————————————————————————*\n"
			L"\t*>减法运算<*\n"
			L"*——————————————————————————*\n"
			L" 需要输入三个数字\n"
			L" 一次输入用空格隔开\n"
			L" 题目个数不能为0\n"
			L"*——————————————————————————*\n"
			L"+>>——————————————————————————<<+\n"
			L"   退出程序输入：0\n"
			L"   个位项输入：1\n"
			L"   十位项输入：2\n"
			L"   百位项输入：3\n"
			L"   千位项输入：4\n"
			L"   万位项输入：5\n"
			L"+>>——————————————————————————<<+\n");
		break;
	case 乘法:
		wprintf(
			L"*————————————————————————————————————————————————————————————————————————————————————*\n"
			L" 提示：乘法算式生成\n"
			L" 输入：2 3 6 （范例）\n"
			L" 得：前项取值在十到九十九之间，后项取值在一百到九百九十九之间，题目数量为6道\n"
			L" 前两个数字代表位数，最后一个数字代表题目数量\n"
			L" 注意控制难度，避免乘积过大\n"
			L"*————————————————————————————————————————————————————————————————————————————————————*\n"
			L"\t*>乘法运算<*\n"
			L"*——————————————————————————*\n"
			L" 需要输入三个数字\n"
			L" 一次输入用空格隔开\n"
			L" 题目个数不能为0\n"
			L"*——————————————————————————*\n"
			L"+>>——————————————————————————<<+\n"
			L"   退出程序输入：0\n"
			L"   个位项输入：1\n"
			L"   十位项输入：2\n"
			L"   百位项输入：3\n"
			L"   千位项输入：4\n"
			L"   万位项输入：5\n"
			L"+>>——————————————————————————<<+\n");
		break;
	case 除法:
		wprintf(
			L"*————————————————————————————————————————————————————————————————————————————————————*\n"
			L" 提示：除法算式生成\n"
			L" 输入：3 1 4 （范例）\n"
			L" 得：前项取值在一百到九百九十九之间，后项取值在一到九之间，题目数量为4道\n"
			L" 前两个数字代表位数，最后一个数字代表题目数量\n"
			L" 结果保留两位小数，使用≈表示近似值\n"
			L"*————————————————————————————————————————————————————————————————————————————————————*\n"
			L"\t*>除法运算<*\n"
			L"*——————————————————————————*\n"
			L" 需要输入三个数字\n"
			L" 一次输入用空格隔开\n"
			L" 题目个数不能为0\n"
			L" 除数不能为0\n"
			L"*——————————————————————————*\n"
			L"+>>——————————————————————————<<+\n"
			L"   退出程序输入：0\n"
			L"   个位项输入：1\n"
			L"   十位项输入：2\n"
			L"   百位项输入：3\n"
			L"   千位项输入：4\n"
			L"   万位项输入：5\n"
			L"+>>——————————————————————————<<+\n");
		break;
	}
	执行->菜单 = 加减乘除菜单;
	return;
	return;
}
void 提示消息(指令类* 执行)
{
	// 位数描述数组
	static const wchar_t 位[][3] = {L"个位", L"十位", L"百位", L"千位", L"万位", L"个位"};
	// 计算索引（从0开始）
	unsigned char 前索引 = 执行->前项位 - 1;
	unsigned char 后索引 = 执行->后项位 - 1;
	// 边界保护
	if (前索引 >= sizeof(位) / sizeof(位[0])) 前索引 = 0;
	if (后索引 >= sizeof(位) / sizeof(位[0])) 后索引 = 0;
	switch (执行->运算类型)
	{
	case 加法:
		wprintf(
			L"加法运算·练习开始\n"
			L"前%ls 后%ls 题数：%u\n"
			, 位[前索引], 位[后索引], 执行->题目数);
		执行->菜单 = 完成;
		return;
	case 减法:
		wprintf(L"减法运算·练习开始\n前%ls 后%ls 题数：%u\n",
			位[前索引], 位[后索引], 执行->题目数);
		执行->菜单 = 完成;
		return;
	case 乘法:
		wprintf(L"乘法运算·练习开始\n前%ls 后%ls 题数：%u\n",
			位[前索引], 位[后索引], 执行->题目数);
		执行->菜单 = 完成;
		return;
	case 除法:
		wprintf(L"除法运算·练习开始\n前%ls 后%ls 题数：%u\n",
			位[前索引], 位[后索引], 执行->题目数);
		执行->菜单 = 完成;
		return;
	}
	return;
}
void 鼓励与表扬(int 话)
{
	// 一到十五随机输出表扬
	// 十六到三十随机输出鼓励
	switch (话)
	{
	case 1: wprintf(L"  干得漂亮！");
		return;
	case 2: wprintf(L"  真棒！");
		return;
	case 3: wprintf(L"  继续加油！");
		return;
	case 4: wprintf(L"  你是最棒的！");
		return;
	case 5: wprintf(L"  你真聪明！");
		return;
	case 6: wprintf(L"  太厉害了！");
		return;
	case 7: wprintf(L"  完美解答！");
		return;
	case 8: wprintf(L"  思路清晰！");
		return;
	case 9: wprintf(L"  反应真快！");
		return;
	case 10: wprintf(L"  计算精准！");
		return;
	case 11: wprintf(L"  进步神速！");
		return;
	case 12: wprintf(L"  理解透彻！");
		return;
	case 13: wprintf(L"  举一反三！");
		return;
	case 14: wprintf(L"  思维敏捷！");
		return;
	case 15: wprintf(L"  表现优秀！");
		return;
	case 16: wprintf(L"  加油，你可以的！");
		return;
	case 17: wprintf(L"  不要气馁，继续努力！");
		return;
	case 18: wprintf(L"  成长的路上需要一点点雨露的滋润！");
		return;
	case 19: wprintf(L"  只要努力就会有收获！");
		return;
	case 20: wprintf(L"  失败乃成功之母！");
		return;
	case 21: wprintf(L"  就差一点点！");
		return;
	case 22: wprintf(L"  再仔细想想！");
		return;
	case 23: wprintf(L"  别着急，慢慢来！");
		return;
	case 24: wprintf(L"  相信你的能力！");
		return;
	case 25: wprintf(L"  下次会更好！");
		return;
	case 26: wprintf(L"  从错误中学习！");
		return;
	case 27: wprintf(L"  坚持就是胜利！");
		return;
	case 28: wprintf(L"  你已经很棒了！");
		return;
	case 29: wprintf(L"  每天进步一点点！");
		return;
	case 30: wprintf(L"  越努力越幸运！");
		return;
	}
	return;
}
void 加减乘除运算练习引导加载器(指令类* 执行)
{
	运算类菜单(执行);
	题目选择项(执行);
	提示消息(执行);
	switch (执行->运算类型)
	{
	case 加法: 加运算练习(执行); return;
	case 减法: 减运算练习(执行); return;
	case 乘法: 乘运算练习(执行); return;
	case 除法: 除运算练习(执行); return;
	}
	return;
}
void 加减乘除运算练习引导重载(指令类* 执行)
{
	提示消息(执行);
	switch (执行->运算类型)
	{
	case 加法: 加运算练习(执行); return;
	case 减法: 减运算练习(执行); return;
	case 乘法: 乘运算练习(执行); return;
	case 除法: 除运算练习(执行); return;
	}
	return;
}
void 题目选择项(指令类* 执行)
{
	char input[256];
	while (加减乘除菜单)
	{
		if (fgets(input, sizeof(input), stdin) == NULL) return;
		input[strcspn(input, "\n")] = '\0';
		if (strcmp(input, "q") == 0 || strcmp(input, "Q") == 0 || strcmp(input, "0") == 0)
		{
			free(执行);
			exit(0);
		}
		if (strlen(input) == 0)
		{
			wprintf(L"请输入选项: ");
			continue;
		}
		unsigned int 题目数;
		unsigned char 前项位, 后项位;
		if (sscanf(input, "%hhu %hhu %u", &前项位, &后项位, &题目数) == 3)
		{
			if ((前项位 >= 1 && 前项位 <= 5) && (后项位 >= 1 && 后项位 <= 5) && (前项位 >= 1 && 前项位 <= 4294967295))
			{
				执行->前项位 = 前项位;
				if ((执行->运算类型 == 除法) && (后项位 == 个位))
					执行->后项位 = 除数;
				else
					执行->后项位 = 后项位;
				执行->题目数 = 题目数;
				return;
			}
			else wprintf(L"\a前项和前项，题目数在1到4294967295之间\n");
		}
		else wprintf(L"\a请输入有效的数字选项\n");
		wprintf(L"请重新输入: ");
	}
	return;
}
void 答题输入处理(void)
{
	wprintf(L"\a输入无效，请输入一个数字。\n");
	ClearInputBuffer();
	return;
}
bool 解答判断(bool 判断, void* 解, void* 答案, 指令类* 执行)
{
	switch (执行->运算类型)
	{
	case 加法:
		if (判断)
		{
			wprintf(L"你的解答正确：%d ✓", *(int*)解);
			鼓励与表扬(rand() % 15 + 1);
			return true;
		}
		else
		{
			wprintf(L"正确答案是：%d  你的解答是：%d ✗", *(int*)答案, *(int*)解);
			鼓励与表扬(rand() % 15 + 16);
			return false;
		}
	/*case 减法:
	case 乘法:
	case 除法:*/
	}
	return false;
}
void 加运算练习(指令类* 执行)
{
	int 前项, 后项, 和;
	unsigned int i, 前 = 执行->前项位, 后 = 执行->后项位;
	int 答;
	for (i = 1; i <= 执行->题目数; i++)
	{
		前项 = 数(前);
		后项 = 数(后);
		和 = 前项 + 后项;
		wprintf(L"第%u题 %d + %d = ", i, 前项, 后项);
		while (scanf("%d", &答) != 1)
		{
			答题输入处理();
			wprintf(L"请继续作答，第%u题 %d + %d = ", i, 前项, 后项);
		}
		if(解答判断(答 == 和, &答, &和, 执行)) 执行->正确题数++;
		if (执行->题目数 ==	i) wprintf(L"  做完了。\n");
		else wprintf(L"  题目剩余数量：%u\n", 执行->题目数  - i);
	}
	return;
}
void 减运算练习(指令类* 执行)
{
	int 前项, 后项, 差;
	unsigned int i, 前 = 执行->前项位, 后 = 执行->后项位;
	for (i = 1; i <= 执行->题目数; i++)
	{
		前项 = 数(前);
		后项 = 数(后);
		差 = 前项 - 后项;
		wprintf(L"第%u题 %d - %d = %d\n", i, 前项, 后项, 差);
	}
	return;
}
void 乘运算练习(指令类* 执行)
{
	int 前项, 后项;
	unsigned int i, 前 = 执行->前项位, 后 = 执行->后项位;
	long long 积;
	for (i = 1; i <= 执行->题目数; i++)
	{
		前项 = 数(前);
		后项 = 数(后);
		积 = (long long)前项 * 后项;
		wprintf(L"第%u题 %d × %d = %lld\n", i, 前项, 后项, 积);
		
	}
	return;
}
void 除运算练习(指令类* 执行)
{
	double 前项, 后项, 商, 比商;
	unsigned int i, 前 = 执行->前项位, 后 = 执行->后项位;
	wchar_t 符号 = 0;
	for (i = 1; i <= 执行->题目数; i++)
	{
		前项 = 数(前);
		后项 = 数(后);
		商 = 前项 / 后项;
		// 四舍五入保留两位小数
		比商 = (double)((int)(商 * 100 + 0.5)) / 100;
		if (商 == 比商)
			符号 = '=';
		else
			符号 = L'≈';
		wprintf(L"第%u题 %.0lf ÷ %.0lf %c %.2lf\n", i, 前项, 后项, 符号, 商);
	}
	return;
}
void 善后工作(指令类* 执行)
{
	执行->运算类型 = 完成;
	执行->正确题数 = 完成;
	if (执行->工作 == 开始) 执行->功能 = 感谢使用;
	return;
}

int 数(unsigned int 数位)
{
	switch (数位)
	{
	case 个位: return rand() % 10;
	case 除数: return rand() % 9 + 1;
	case 十位: return rand() % 90 + 10;
	case 百位: return rand() % 900 + 100;
	case 千位: return rand() % 9000 + 1000;
	case 万位: return (int)GenerateInteger(10000LL, 99999LL);
	default: return rand() % 99 + 1; 
	}
}

int 设置UTF8编码(void)
{
	// 尝试设置UTF-8 locale
	if (setlocale(LC_ALL, "en_US.UTF-8") == NULL && setlocale(LC_ALL, "C.UTF-8") == NULL && setlocale(LC_ALL, "zh_CN.UTF-8") == NULL)
	{
		// 如果以上都失败，尝试通用设置
		setlocale(LC_ALL, "");
	}
#ifdef _WIN32
	// Windows 额外设置
	SetConsoleOutputCP(CP_UTF8);
	return GetConsoleOutputCP() == CP_UTF8;
#else
	// Unix-like 系统通常不需要额外设置
	return 1;
#endif
}

// 欢迎界面
void ShowWelcomeMessage(void)
{
	wprintf(
		L"本程序由【ZwlLoveCHN1949101】编写，\n"
		//L"  此程序为第三代。\n"
		L"  程序实验中。\n"
		L"*****================================*****\n"
		L"    \t*>欢迎使用<*\n"
		L"    本程序是一个四则运算练习程序\n"
		L"    你可以选择加减乘除进行练习\n"
		L"    也可以选择题目的难度和题目数量\n"
		L"    祝你使用愉快！\n"
		L"*****================================*****\n");
	return;
}

void 开始菜单打印(void)
{
	wprintf(
		L"\t*>开始<*\n"
		L"+>>————————————————————————————<<+\n"
		L"   退出程序输入：0\n"
		L"   加法运算输入：1\n"
		L"   减法运算输入：2\n"
		L"   乘法运算输入：3\n"
		L"   除法运算输入：4\n"
		L"   查看九九乘法表输入：5\n"
		L"   查看《MIT License》输入：6\n"
		L"+>>————————————————————————————<<+\n"
		L"请输入：");
	return;
}
void 继续菜单打印(指令类* 执行)
{
	if (执行->功能 == 感谢使用)
	{
		wprintf(
			L"**************************************\n"
			L" 感谢使用本程序。\n"
			L" 本程序由【ZwlLoveCHN1949101】编写。\n"
			L"**************************************\n");
		执行->功能 = 完成;
	}
	wprintf(
		L"\t*>继续<*\n"
		L"+>>—————————————————————————————————————————<<+\n"
		L"   退出程序输入：0\n"
		L"   加法运算输入：1\n"
		L"   减法运算输入：2\n"
		L"   乘法运算输入：3\n"
		L"   除法运算输入：4\n"
		L"+>>—————————————————————————————————————————<<+\n"
		L"==>>—————————————————————————————————————————<<=\n"
		L"    按照曾经输入的位数和题数继续出题:\n"
		L"      加法运算输入：5\n"
		L"      减法运算输入：6\n"
		L"      乘法运算输入：7\n"
		L"      除法运算输入：8\n"
		L"==>>—————————————————————————————————————————<<=\n"
		L"!>>——————————————(· ^_^ ·)——————————————<<!\n"
		L"   查看历史成绩输入；9\n"
		L"   查看九九乘法表输入：10\n"
		L"   查看《MIT License》输入：11\n"
		L"!>>——————————————(· ^_^ ·)——————————————<<!\n"
		L"请输入：");
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

// ClearInputBuffer函数清除输入缓冲区
void ClearInputBuffer(void)
{
	int ch = 0;
	while ((ch = getchar()) != '\n' && ch != EOF);
	return;
}

void 倒计时提醒(const wchar_t* 消息, int 秒数)
{
	wprintf(L"%ls - %d秒后退出...\n倒计：", 消息, 秒数);
	int i;
	for (i = 秒数; i > 0; i--)
	{
		wprintf(L" %d", i); // 覆盖是一个字符
		fflush(stdout);
		等待(1)
	}
	return;
}

// 九九乘法表
void PrintMultiplicationTable(void)
{
	ClearScreen();
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