
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
 * 析构函数的使用场景：
 * 在 C++ 中，显式地在析构函数中使用 delete 或 delete[] 
 * 主要用于手动管理动态分配的内存。当一个类在其生命周期中分配了动态内存时，
 * 必须在析构函数中释放这些内存，以避免内存泄漏。
*/

/**
 * 需要显示的调用delete
 * 当一个类使用了动态内存分配（如使用 new 或 new[]）时，必须在析构函数中显式释放这些内存。否则会导致内存泄漏。
*/
class A {
 public:
    int* data_;
    int* array_;
    A(int data) {
        data_ = new int;
        array_ = new int(data);
        std::cout << "in constructed A" << std::endl;
    }
    ~A() {
        delete data_;
        delete[] array_;
        std::cout << "in destructed A" << std::endl;
    }
};

void need_delete() {
    A a1 = A(10);
}

/**
 * 不需要显式 delete 的场景
   当一个类只包含自动存储（stack）变量，或者使用了智能指针来管理动态内存时，
   不需要显式地在析构函数中使用 delete。智能指针会自动管理内存，确保在对象不再使用时释放资源。
*/

//不需要显式 delete 的场景1 : 自动存储变量
class B {
 public:
    int data_;
    B(int data) : data_(data) {
        std::cout << "in constructed B" << std::endl;
    };
    ~B() {
        std::cout << "in destructed B" << std::endl;
    }
};
void donnot_need_delete1() {
    B b1 = B(10);
}

//不需要显式 delete 的场景2 : 使用智能指针
class SmartClass {
 public:
    std::unique_ptr<int> data_;
    std::unique_ptr<int[]> array_;
    SmartClass(int size) : data_(new int), array_(new int[size]) {
         std::cout << "in constructed SmartClass" << std::endl;
    }
    ~SmartClass() {
        // 不需要显式delete，智能指针会自动管理
        std::cout << "in destructed SmartClass" << std::endl;
    }
};
void donnot_need_delete2() {
    SmartClass c(10);
}

int main(int argc, char const *argv[])
{
    need_delete();
    std::cout << "~~~~~~~~~~~~~~~" << std::endl;
    donnot_need_delete1();
    std::cout << "~~~~~~~~~~~~~~~" << std::endl;
    donnot_need_delete2();
    return 0;
   
} 
