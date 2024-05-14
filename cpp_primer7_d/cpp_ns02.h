#ifndef CPP_NS02_H
#define CPP_NS02_H

//不要在头文件中使用using，会导致函数冲突
namespace ns02 {
    void function1() {
        std::cout << "ns02" << std::endl;
    };
}

void function1() {
    std::cout << "cpp_ns02.h::function1" << std::endl;
}

#endif // CPP_NS02_H