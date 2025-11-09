#pragma once
typedef struct 运行时
{
    unsigned char 工作, 过程, 功能;
    unsigned char 前项位, 后项位, 运算类型;  // 200:+ 210:- 220:× 230:÷
    unsigned char 当前题目, 正确题数, 错误题数;
    unsigned int 题目数;
    int 用户答案, 正确答案;
    float 用户答案f, 正确答案f;  // 用于除法
} 指令类;

// 用于切换工作
#define 结束 0
#define 开始 1
#define 继续 2 

// 运算类型
#define 加法 200
#define 减法 210
#define 乘法 220
#define 除法 230