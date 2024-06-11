
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
 * 使用std::swap进行对象属性的交换
*/
class A{
 public:
    int a_;
    string b_;
    A(int a, string b) : a_(a), b_(b) {};
};

void f() {
    A a1 = A(1, "test1");
    A a2 = A(2, "test2");
    using std::swap;
    swap(a1, a2);
    cout << a1.a_ << " : " << a1.b_ << endl;
    cout << a2.a_ << " : " << a2.b_ << endl;
}


int main(int argc, char const *argv[])
{
    f();
    return 0;
   
} 
