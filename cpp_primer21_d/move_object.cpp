
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
 * 移动构造
*/

class A {
 public:
    int a_;
    A(int a) : a_(a) {
        cout << "constructor A" << endl;
    };


    //copy constuctor
    A(const A& a) {
        cout << "copy constructor A" << endl;
        this->a_ = a.a_;
    }
    //move constructor ,noexcept声明不会抛异常
    A(const A&& a) noexcept {
        cout << "move constructor A" << endl;
        this->a_ = a.a_;
        // a = nullptr;
    }

    ~A() {
        cout << "deconstructor A" << endl;
    }
};


int main(int argc, char const *argv[])
{
    vector<A> v1;
    //有移动构造优先使用移动构造，将资源移动到vector 不浪费空间，而不走拷贝构造
    v1.push_back(A{1});
    return 0;
   
} 
