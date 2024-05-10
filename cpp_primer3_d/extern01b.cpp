#include "extern01a.h"
#include <iostream>

extern int a;

int main(int argc, char** argv) {

    /**
     * 在C++中，你应该避免直接在一个cpp文件中包含另一个cpp文件。
     * 通常，如果需要在多个cpp文件之间共享变量或函数声明，
     * 应将这些声明放在一个头文件（.h 或 .hpp）中，然后在需要使用它们的cpp文件中包含这个头文件。
    */
    std::cout << a << std::endl;
    return 0;
}
