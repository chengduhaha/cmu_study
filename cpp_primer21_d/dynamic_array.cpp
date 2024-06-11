
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
 * 在C++中，动态数组通常指的是在程序运行时分配的数组，其大小可以在运行时决定，
 * 而非编译时固定。C++提供了多种方式来实现动态数组，最基础的方式是使用标准库中的new表达式来分配内存，
 * 以及使用delete来释放内存。
*/

void dynamic_array_example() {
    // 1. 动态分配一个整型数组，大小为10
    int* dynamicArray = new int[10]; //使用new关键字后面跟上数据类型和方括号[]以及数组的大小来分配动态数组。

    // 2. 初始化动态数组
    for (size_t i = 0; i < 10; i++)
    {
        dynamicArray[i] = i * 2; // 每个元素初始化为i的两倍
    }

    // 3. 访问和打印动态数组的元素
    for (size_t i = 0; i < 10; i++)
    {
        cout << dynamicArray[i] << " ";
    }

    // 4. 释放动态数组占用的内存
    /**
     * 当不再需要动态数组时，必须使用delete[]来释放内存，以避免内存泄漏。
     * 注意，释放动态数组时使用的是delete[]而非单个delete，
     * 这是因为delete[]会调用数组中每个对象的析构函数（如果有的话），并释放整个数组的内存。
    */
    delete[] dynamicArray; // 注意使用[]，因为是数组
}


void vector_example() {
    vector<int> v1(10);
    for (size_t i = 0; i < 10; i++)
    {
        v1[i] = i * 3;
    }
    for (size_t i = 0; i < 10; i++)
    {
        cout << v1[i] << " ";
    }
    
    
}

int main(int argc, char const *argv[])
{
    dynamic_array_example();
    cout << " " << endl;
    vector_example();
    return 0;
   
} 
