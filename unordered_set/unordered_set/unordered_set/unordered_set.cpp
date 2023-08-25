#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };  // 初始化 vector
    std::unordered_set<int> mySet(vec.begin(), vec.end());  // 用 vector 初始化 unordered_set

    // 输出 unordered_set 的内容
    for (const auto& num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}