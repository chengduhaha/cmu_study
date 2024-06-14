
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
 * 模板 相当于java里的泛型
*/

//声明+定义模板
template <typename T>
T add(T a, T b) {
    return a+b;
}

class A {
 public:
    int a_;
    A(int a) : a_(a) {};
    A& operator+(const A& a) {
        this->a_ += a.a_;
        return *this;
    }
};


int main(int argc, char const *argv[])
{   
    int a = 1;
    int b = 2;
    cout << add(a, b) << endl;
    cout << add(1.1, 2.2) << endl;
    string x = "hello";
    string y = " world";
    cout << add(x, y) << endl;

    A a1(1);
    A a2(2);
    a1 = a1 + a2;
    cout << a1.a_ << endl;

    cout << add(a1, a2).a_ << endl;
    return 0;
} 
