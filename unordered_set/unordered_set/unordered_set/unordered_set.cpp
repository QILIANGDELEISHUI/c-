#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
    std::vector<int> vec = { 1, 2, 3, 4, 5 };  // ��ʼ�� vector
    std::unordered_set<int> mySet(vec.begin(), vec.end());  // �� vector ��ʼ�� unordered_set

    // ��� unordered_set ������
    for (const auto& num : mySet) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}