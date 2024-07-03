#include <iostream>
#include <string>

void console_io01() {
    std::string list;
    bool hasInput = false;

    while (true) {
        std::getline(std::cin, list); // 读取一行输入

        if (!std::cin) { // 检查是否到达文件末尾或输入流错误
            break;
        }

        if (list.length() > 0) { // 检查输入字符串是否非空
            hasInput = true;
            break;
        }
    }

    if (hasInput) {
        std::cout << "Received input: " << list << std::endl;
    } else {
        std::cout << "No valid input received." << std::endl;
    }

}


int main() {
    console_io01();
    return 0;
}