#pragma once
typedef struct 运行时
{
    unsigned char 工作, 过程, 功能, 菜单;
    unsigned char 前项位, 后项位, 运算类型;  // 200:+ 210:- 220:× 230:÷
    //unsigned char 当前题目, 错误题数;
    unsigned int 正确题数, 题目数;
} 指令类;

// 用于切换工作
#define 结束 0
#define 完成 0
#define 开始 1
#define 继续 2 

// 运算类型
#define 加法 200
#define 减法 210
#define 乘法 220
#define 除法 230

#define 回调加法 100
#define 回调减法 110
#define 回调乘法 120
#define 回调除法 130

// 明确菜单
#define 开始菜单 1
#define 继续菜单 2
#define 加法菜单 100
#define 减法菜单 110
#define 乘法菜单 120
#define 除法菜单 130
#define 加减乘除菜单 140

// 数位
#define 个位 1
#define 十位 2
#define 百位 3
#define 千位 4
#define 万位 5
#define 除数 6

// 
#define 感谢使用 1