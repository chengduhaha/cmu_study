#include <iostream>
#include <string>
#include "cpp_ns02.h" //编译器编译时直接把cpp_ns02.h的内容替换到当前文件


using namespace std;

/**
 * namespace 避免变量/函数命名的冲突，通过不同命名空间的相同变量名来进行区分
*/

namespace ns01 {
    void function1() {
        std::cout << "ns01" << std::endl;
    }
}

//无法定义了 因为头文件cpp_ns02.h已经定义了function1，否则编译会报错
// void function1() {
//     std::cout << "cpp_ns01::function1" << std::endl;
// }

int global_val = 123;

int main(int argc, char const *argv[]) {
    ns01::function1();
    //引用其他命令空间的相同函数
    ns02::function1();

    int global_val = 456;
    //打印最近的global_val = 456
    std::cout << global_val << std::endl;
    //加上::后打印命令空间中的global_val = 123
    std::cout << ::global_val << std::endl;

    //都会调用cpp_ns02的function1();
    function1();
    ::function1();

    return 0;
}

