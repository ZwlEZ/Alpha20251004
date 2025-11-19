#include <random>
/*
    给用户提供自行设计大数表达式得
*/
// 生成整数
extern "C" long long int GenerateInteger(long long int min, long long int max)
{
    // 创建随机数引擎和设备
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_int_distribution<long long int> dis(min, max);
    // 生成随机数
    return dis(gen);
}
// 生成小数
extern "C" long double GenerateDecimal(long double min, long double max)
{
    std::random_device rd;
    std::mt19937_64 gen(rd());
    std::uniform_real_distribution<long double> dis(min, max);
    return dis(gen);
}