#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 函数的参数传递
 * 
 * 1. value 值拷贝 另开辟一个内存空间 将原值拷贝到另一个内存值，无法直接修改原值
 * 2. 自身的引用 引用 &ref 或 指针 *pointer 不会另开辟一个新的空间 是直接引用原值和内存地址，可直接修改原值
 */

//值拷贝
void function1(int value) {
    value  = value * 2;
    cout << "value == " << value << endl;
}

//引用
void function2(int &value) {
    value  = value * 2;
    cout << "value == " << value << endl;
}

//指针
void function3(int *value) {
    cout << *value << endl; 
    cout << value << endl;
    *value = *value + 100;
    cout << *value << endl;
    cout << value << endl;
}

//常量参数 low-level，const修饰的是基本类型int 可以接收变量传递进来 int x = 10; function4(x);
void function4(const int &value) {
    cout << value << endl;
    // value = value++; 这行编译报错，const int修饰后无法修改value的值
}

//常量参数 low-level，const修饰的是基本类型int 可以接收变量传递进来 int x = 10; function4(x);
void function4_2(const int *value) {
    cout << value << endl;
    int test = 123;
    value = &test;
    // value = value++; 这行编译报错，const int修饰后无法修改value的值
}

//常量参数 top-level，const修饰的是复合对象 比如 const a = 100; 无法将一个值123或者一个非常数对象 int a = 100 的参数传递进来
void function5(const int * const value) {
    cout << value << endl;
    // int test = 123; 这行编译报错，const int修饰后无法修改value的值
    // value = &test; 
    // value = value++; 这行编译报错，const int修饰后无法修改value的值
}

int main(int argc, char const *argv[])
{   
    /**回顾指针*/
    int x = 10;
    int *p = &x;
    cout << p << endl;
    cout << *p << endl;


    /**
     * 值拷贝 a 和 value是两个变量
     * 结果：
     * value == 200
     * a == 100
    */
    int a = 100;
    function1(a);
    cout << "a == " << a << endl;

    /**
     * 引用拷贝 a 和 value 是一直变量
     * 结果：
     * value == 200
     * a == 200
    */
    function2(a);
    cout << "a == " << a << endl;

    cout << "pointer !!! " << endl;
    int z = 99;
    function3(&z);
    cout << "z == " << z << endl;


    cout << "const low level !!! " << endl;
    function4(124);
    int test = 123; //可以传一个非const的值 因为function4_2(const int *value)为low level
    function4(test);

    // function4_2(124);
    int test2 = 123; //可以传一个非const的值 因为function4_2(const int *value)为low level
    function4_2(&test2);

    cout << "const top level !!! " << endl;
    // function5(124); 改行会报错 因为124不是一个const的对象 
    const int aa = 100;
    function5(&aa);
    int test3 = 123;
    function5(&test3);
    
    return 0;
}


