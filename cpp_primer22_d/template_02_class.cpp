
#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>  // 包含std::sort所需的头文件

#include <set> // 添加这行来包含set容器的头文件
#include <map> // 添加这行来包含map容器的头文件
#include <unordered_map> // 添加这行来包含map容器的头文件

//sleep
#include <chrono>
#include <thread>

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::set;
using std::map;
using std::unordered_map;

/**
 * class模板
*/

template <typename T>
class A {
    public:
    T a_;
    A(T a) : a_(a) {};
};

template <typename M>
class B {
    public:
    M b_;

    //在类内实现函数可以不显示声明泛型B<M>
    B& f1() {
        cout << "in class f1" << endl;
        return *this;
    }

    B& f2();

    void f3() {
        cout << b_ << endl;
    }

    static int count;
};

//在类外实现函数必须显示声明泛型B<M>
template <typename M>
B<M>& B<M>::f2() {
    cout << "in class f2" << endl;
    return *this;
}

class C{

};

template <typename M>
int B<M>::count = 1;

int main(int argc, char const *argv[])
{   
    //实例化类时必须显示地指定泛型的类型<T>
    A<int> a1 = A<int>(1);
    int aa = a1.a_;
    cout << aa << endl;

    B<long> b1;
    b1.b_ = 100;
    long bb = b1.b_;
    cout << bb << endl;

    // B<M> b2; 报错， 泛型M需要执行具体的类型
    // B b2; 报错，泛型M需要执行具体的类型

    // B<C> b3; error: conversion from ‘int’ to non-scalar type ‘C’ requested
    B<C> b4;
    b4.f1();
    b4.f2();
    //懒加载 lazy loading
    // b4.f3(); //error: cannot bind ‘std::ostream {aka std::basic_ostream<char>}’ lvalue to ‘std::basic_ostream<char>&&’

    //static静态属性规则： 每种模板类型都共享同一个资源 比如所有 B<int>类的对象都共享同一个static资源
    cout << B<long>::count << endl;
    cout << B<C>::count << endl;

    //b1和b1共享B<long>中的static count
    b1.count +=1;
    B<long> b2;
    b2.count +=1;
    cout << B<long>::count << endl;

    

    return 0;
} 
