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
 * 深拷贝浅拷贝
*/
class A {
 public:
    int* a_;
    string b_;
    A(int a, string b):a_(new int(a)), b_(b) {
        cout << "in constructor" << endl;
    };
    ~A() {
        cout << "in destructor " << b_ << endl;
    }
};


class B {
 public:
    int* a_;
    string b_;
    B(int a, string b):a_(new int(a)), b_(b) {
        cout << "in constructor" << endl;
    };
    ~B() {
        cout << "in destructor " << b_ << endl;
    }
    /**
     * 实现一个深拷贝构造
     */
    B(const B& b) {
        // this->a_ = b->b_;浅拷贝
        cout << "in my deep copy constructor" << b_ << endl;
        this->a_ = new int(*(b.a_)); //深拷贝
        // this->b_ = b.b_;
    }
};

void shallow_copy() {
   A a1 = A(12,"aaa");
   cout << a1.a_ << endl;

   /**
    * 浅拷贝
    */
   A a2 = A(a1);
   cout << a2.a_ << endl;
}

void deep_copy() {

   /**
    * 深拷贝
    */
   B b1 = B(32,"bbb");
   cout << b1.a_ << endl;
   B b2 = B(b1);
   cout << b2.a_ << endl;
   cout << "~~~~~~~~~~~~~~~~~" << endl;
   cout << b1.b_ << endl;
   cout << b2.b_ << endl;
}

int main(int argc, char const *argv[])
{
   shallow_copy();
   cout << "~~~~~~~~~~~~~~~~~" << endl;
   std::this_thread::sleep_for(std::chrono::seconds(2)); // 暂停5秒
   deep_copy();
   
} 
