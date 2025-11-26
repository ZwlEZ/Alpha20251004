#pragma once
void 显示历史成绩(void);
void 开始菜单打印(void);
void 题目生成引导加载器(void);
void 倒计时提醒(const wchar_t*, int);	// 思维放开一点点不仅仅用于退出
void ClearScreen(void);
void PrintMITLicense(void);
void ClearInputBuffer(void);
void ShowWelcomeMessage(void);
void PrintMultiplicationTable(void);
bool 善后工作(指令类*, 练习用时);
void 加运算练习(指令类*);
void 减运算练习(指令类*);
void 乘运算练习(指令类*);
void 除运算练习(指令类*);
void 题目选择项(指令类*);
void 继续菜单打印(指令类*);
练习用时 加减乘除运算练习引导重载(指令类*);
练习用时 加减乘除运算练习引导加载器(指令类*);	// 数据初始化与提醒
int 设置UTF8编码(void);
int 数(unsigned int);
int 回调函数(指令类*);
int 选择命令(指令类*);
指令类* 初始化运行时(void);
bool 获取当前时间戳与日历时间(void*, int);
bool 生成格式化的时间文件名(wchar_t*, size_t, const wchar_t* 首, const wchar_t*, const wchar_t*);

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define 等待(秒数) Sleep((秒数) * 1000);
#else
#include <unistd.h>
#define 等待(秒数) usleep((秒数) * 1000000);
#endif
