#include <iostream>
#include <string>
#include <utility> // for std::move
/**
 * std::move 是C++11引入的一种实用函数，用于实现移动语义（move semantics），其主要目的是避免不必要的数据拷贝，提高程序的性能。
 * std::move 本质上是一个类型转换，将对象转换为右值引用（rvalue reference）。这使得被转换的对象可以使用移动构造函数或移动赋值运算符，而不是拷贝构造函数或拷贝赋值运算符。
 * 
 * 移动语义的好处
 * 移动语义允许对象的资源（如内存、文件句柄等）被“移动”而不是“拷贝”，这在处理大对象或复杂资源时可以显著提高性能。
*/

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 在C++中，左值（lvalue）和右值（rvalue）是用于区分表达式类型的重要概念。
 * 
*/

void printValue(const int &val) {
    std::cout << "Left value: " << val << std::endl;
}

void printValue(int &&val) {
    std::cout << "Right value: " << val << std::endl;
}

int main(int argc, char const *argv[])
{
    /**
     * 左值（lvalue）
     * 左值是指在表达式中占据内存地址的对象，通常可以出现在赋值操作的左边（即可以被赋值）。
     * 左值表示一个对象或一个可持久存在的存储位置。
     * 
     * 在下面的例子中，x 是一个左值，因为它表示一个内存位置，可以被赋值，也可以被取地址（&x）。
    */
    int x = 10;  // x 是左值
    x = 20;     // 可以将 20 赋值给左值 x
    int *p = &x; // x 是一个可以取地址的对象

    /**
     * 右值（rvalue）
     * 右值是指在表达式中不占据持久存储位置的对象，通常是临时的，不可以出现在赋值操作的左边。
     * 右值表示一个数据值或一个表达式的计算结果。
     * 
     * 在下面的例子中，30、x + 5 和 y * 2 都是右值，因为它们是临时的值或表达式的结果，不能直接赋值给它们。
    */
    int y = 30; // 30 是右值
    y = x + 5;  // x + 5 是右值
    int z = y * 2; // y * 2 是右值

    /**
     * 左值引用
     * 左值引用可以绑定到左值上，用来引用一个变量。
    */
    int a = 10;
    int &ref = a; // ref 是 a 的左值引用
    ref = 20; // 改变 ref 的值也会改变 a 的值

    /**
     * 右值引用（C++11 引入）
     * 右值引用可以绑定到右值上，用来优化移动语义和避免不必要的拷贝。
     * 
     * 右值引用在实现移动语义（move semantics）时非常有用，通过移动而不是拷贝来提高性能。
    */
    int &&rref = 10; // rref 是一个右值引用，绑定到右值 10
    rref = 10;  // 可以通过 rref 修改右值的值

    /**
     * 示例代码
    */
    int test = 10;  // test 是左值
    printValue(test);

    printValue(20); // 传递右值给函数

    int test2 = 30;
    printValue(std::move(test2)); // std::move(y) 将 y 转换为右值
    
    return 0;
}


