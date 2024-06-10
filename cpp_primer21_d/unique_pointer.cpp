
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
 * unique pointer:将编译器版本改为-std=c++14，就可以使用std::make_unique方法
 * 升级GCC版本
 * sudo yum install -y centos-release-scl
 * sudo yum install -y devtoolset-8-gcc-c++
 * scl enable devtoolset-8 bash
*/
class A {
 public:
    int* a_;
    string b_;
    A(int a, string b):a_(new int(a)), b_(b) {
        cout << "in constructor " << *a_ << endl;
    };
    ~A() {
        cout << "in destructor " << b_ << endl;
    }
};

std::unique_ptr<A> make_A_pointer() {
    return std::make_unique<A>(100,"lkj");
}

void Desctruction(A* a) {
    cout << "Desctruction " << endl;
    delete a->a_;
}

void unique_pointer1() {
    std::unique_ptr<A> p1 = std::make_unique<A>(12,"sdf");
    A x =  A(13,"sdfg");
    std::unique_ptr<A> p2 = std::make_unique<A>(x);

    //release()后要调用析构函数来释放指针资源
    std::unique_ptr<A> p3 = std::make_unique<A>(14,"xxxx");
    auto p3_r = p3.release();
    p3_r->~A();

    //reset会释放指针
    std::unique_ptr<A> p4 = std::make_unique<A>(15,"yy");
    p4.reset();

    //不能进行拷贝构造
    // std::unique_ptr<A> p5 = std::make_unique<A>(p4);

    //不能进行赋值构造
    // std::unique_ptr<A> p5 = p3;

    //可以通过函数返回值构造
    std::unique_ptr<A> p5 = make_A_pointer();

    
    // 自定义Desctruction释放指针
    std::unique_ptr<A, decltype(Desctruction)*> p6(new A(101, "Desctruction"), Desctruction);

    //另一种构造
    std::unique_ptr<A> p7(new A(102, "sss")); 


}



int main(int argc, char const *argv[])
{
    unique_pointer1();
    return 0;
   
} 
