#pragma once
typedef struct 运行时
{
    unsigned char 工作, 过程, 功能, 菜单;
    unsigned char 前项位, 后项位, 运算类型;  // 200:+ 210:- 220:× 230:÷
    unsigned int 正确题数, 题目数;
} 指令类;

typedef time_t 时间戳;
typedef 时间戳* 时间戳指针;
typedef struct tm 日历时间结构;
typedef 日历时间结构* 日历时间指针;
#define 时间戳功能 1
#define 日历时间功能 2
#define 格式_详细时间 L"%Y年%m月%d日_%H时%M分%S秒"
#define 格式_简单日期 L"%Y%m%d"
#define 格式_日期时间 L"%Y%m%d_%H%M%S"
typedef struct LXSJ
{
    日历时间指针 作答开始时间, 作答结束时间;
}练习用时;
#define 时间指针集失效 0
#define 时间指针集可用 1

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
#define 个位_正整数_ 1
#define 十位_正整数_ 2
#define 百位_正整数_ 3
#define 千位_正整数_ 4
#define 万位_正整数_ 5
#define 除数_正整数_ 6
#define 个位_负整数_ 7
#define 十位_负整数_ 8
#define 百位_负整数_ 9
#define 千位_负整数_ 10
#define 万位_负整数_ 11
#define 除数_负整数_ 12

// 
#define 感谢使用 1
#define 运算数据无效 0
#define 运算数据有效 1