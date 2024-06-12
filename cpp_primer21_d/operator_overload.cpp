
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
 * 重载运算符，优先在class内找重载运算符,然后再在class外找
*/

class A {
 public:
    int a_;
    A(int a) : a_(a) {
        cout << "constructor A" << endl;
    };

    A& operator+(/*this*/ const A& a) {
        cout << "operator+ A" << endl;
        this->a_ += a.a_;
        return *this;
    }
};

A operator*(const A& lhs, const A& rhs) {
    A a0(0);
    a0.a_ = + lhs.a_ * rhs.a_;
    return a0;   
}

int main(int argc, char const *argv[])
{
    A a1(3);
    A a2(4);
    a1 = a1 + a2;
    cout << a1.a_ << endl;
    cout << a2.a_ << endl;
    
    A a3 = a1 * a2;
    cout << a3.a_ << endl;
    return 0;
   
} 
