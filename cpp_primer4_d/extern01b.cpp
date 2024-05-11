#include "extern01a.h"
#include <iostream>

/**
 * std::cout << "hello : " << std::endl;
 * 在这段代码中，std::cout 和 std::endl 是通过它们的完全限定名来使用的，即明确指出了它们位于 std 命名空间内。
 * 这是C++标准库中IO流对象和操纵符的标准使用方式。这种做法清晰地表明了cout和endl的来源，
 * 增强了代码的可读性和可维护性，尤其是在大型项目中，当命名冲突可能成为一个问题时。
 * 
 * 这段代码首先通过 using 指令引入了 std 命名空间内的 cout 和 endl 到当前作用域。
 * 这意味着在这段代码之后，可以直接使用 cout 和 endl 而不必再加 std:: 前缀。
 * 这种方式让代码看起来更简洁，但可能会增加命名冲突的风险，尤其是在较复杂的代码库中，如果其他地方也有同名的对象或函数，就可能导致混淆。
*/
using std::cout;
using std::endl;

// 引用exern01a.cpp中的 a变量
extern int a;

int main(int argc, char** argv) {

    /**
     * 在C++中，你应该避免直接在一个cpp文件中包含另一个cpp文件。
     * 通常，如果需要在多个cpp文件之间共享变量或函数声明，
     * 应将这些声明放在一个头文件（.h 或 .hpp）中，然后在需要使用它们的cpp文件中包含这个头文件。
    */
    cout << a << endl;
    return 0;
}
