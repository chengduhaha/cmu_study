
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
 * const      int*          const            ptr
 * |                          |
 * low level                 top level
 * 可以改变值不可以改变地址    值和地址都不可以改变
*/

//low level
template <typename T>
void r1(const T ptr) {
    int b = 100;
    *ptr = b;
}

void f1() {
    int a = 10;
    int* ptr1 = &a;
    r1(ptr1);
    cout << *ptr1 << endl; 
}


template <typename FUNC, typename T1, typename T2>
void flip1(FUNC f, T1 t1, T2 t2) {
    f(t1, t2);
}
void test1(int v1, int v2) {
    cout << "v1 = " << v1 << " ++v2 = " <<  ++v2 << endl;
}

template <typename FUNC, typename T1, typename T2>
void flip2(FUNC f, T1& t1, T2& t2) {
    f(t1, t2);
}
void test2(int& v1, int& v2) {
    cout << "v1 = " << v1 << " ++v2 = " <<  ++v2 << endl;
}

template <typename FUNC, typename T1, typename T2>
void flip3(FUNC f, T1 t1, T2 t2) {
    f(t1, t2);
}
void test3(int& v1, int& v2) {
    cout << "v1 = " << v1 << " ++v2 = " <<  ++v2 << endl;
}


template <typename FUNC, typename T1, typename T2>
void flip4(FUNC f, T1&& t1, T2&& t2) {
    f(t1, t2);
}
void test4(int v1, int& v2) {
    cout << "v1 = " << v1 << " ++v2 = " <<  ++v2 << endl;
}


template <typename FUNC, typename T1, typename T2>
void flip5(FUNC f, T1&& t1, T2&& t2) {
    f(std::forward<T1>(t1) , std::forward<T2>(t2));
}
void test5(int v1, int& v2) {
    cout << "v1 = " << v1 << " ++v2 = " <<  ++v2 << endl;
}


int main(int argc, char const *argv[])
{   
    f1();
    //模板定义的参数和test1的参数都是拷贝变量 所以没有改变v2的值
    int v1 = 10;
    int v2 = 100;
    flip1(test1, v1, v2);
    cout << " v2 = " << v2 << endl;

    cout << "~~~~~~~~~" << endl;
    
    //模板定义的参数和test1的参数都是引用贝变量 所以能改变v2的值
    int v3 = 10;
    int v4 = 100;
    flip2(test2, v3, v4);
    cout << " v2 = " << v4 << endl;
    cout << "~~~~~~~~~" << endl;

    //模板定义的参数没有引用变量而是拷贝变量，test1的参数是引用贝变量 所以不能改变v2的值
    int v5 = 10;
    int v6 = 100;
    flip3(test3, v5, v6);
    cout << " v2 = " << v6 << endl;
    cout << "~~~~~~~~~" << endl;


    //模板定义的右值引用参数，test1的参数是左值引用 所以能改变v2的值
    int v7 = 10;
    int v8 = 100;
    flip4(test4, v7, v8);
    cout << " v2 = " << v8 << endl;
    cout << "~~~~~~~~~" << endl;


    int v9 = 10;
    int v10 = 100;
    flip5(test5, v9, v10);
    cout << " v2 = " << v10 << endl;
    cout << "~~~~~~~~~" << endl;



    return 0;
} 
