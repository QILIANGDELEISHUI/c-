#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename = "vmware.log"; // 日志文件的路径和名称
    std::string searchKeyword = "lib"; // 要搜索的关键字

    // 打开日志文件
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return 1;
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        if (line.find(searchKeyword) != std::string::npos) {
            // 如果行中包含搜索关键字，则输出行号和内容
            std::cout << "Line " << lineNumber << ": " << line << std::endl;
        }
        lineNumber++;
    }

    file.close(); // 关闭文件

    return 0;
}