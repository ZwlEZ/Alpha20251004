#pragma once
void 开始菜单打印(void);
void 继续菜单打印(void);
void ClearScreen(void);
void PrintMITLicense(void);
void ShowWelcomeMessage(void);
void PrintMultiplicationTable(void);
void 加减乘运算练习(指令类*);			// 生成处理
void 加减乘运算练习引导加载器(指令类*);	// 数据初始化与提醒
int 回调函数(指令类*);
int 选择命令(指令类*);
指令类* 初始化运行时(void);
