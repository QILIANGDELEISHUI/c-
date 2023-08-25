#include <iostream>
#include <cmath>

unsigned int roundUpToPowerOf2(unsigned int n) {
    if (n == 0) {
        return 1;  // 特殊情况处理，0的2的幂次方为1
    }
    unsigned int power = static_cast<unsigned int>(std::round(std::log2(n)));
    return static_cast<unsigned int>(std::pow(2, power));
}

int main() {
    unsigned int num = 0;  // 给定的任意正整数
    std::cout << "输入一个大于0的正整数：";
    std::cin >> num;
    unsigned int result = roundUpToPowerOf2(num);

    std::cout << "原始数据: " << num << std::endl;
    std::cout << "向上取整到最接近2的幂: " << result << std::endl;

    return 0;
}