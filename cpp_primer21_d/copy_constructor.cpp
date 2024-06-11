
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
 * 拷贝构造 copy costructor
 * 拷贝分配 copy asignment 重载操作符 operator
*/

class A {
 public:
    int a_;
    //直接构造
    A(int a) : a_(a) {
        cout << "in constructor A" << endl;
    }
    //拷贝构造
    A(const A& a) {
        cout << "in copy constructor A" << endl;
    }
    //析构函数
    ~A() {
        cout << "in deconstructor A" << endl;
    }
    //拷贝分配
    A& operator=(const A& a) {
        cout << "in copy assignment A" << endl;
        this->a_ = a.a_;
        return *this;
    }
};

struct ABC {
    int a;
    bool b;
    string c;
};

void copy_constructor_test1(A a) {
    cout << "in copy_constructor_test1" << endl;
}

void copy_constructor_test2(A& a) {
    cout << "in copy_constructor_test2" << endl;
}

void copy_constructor_test3(A* a) {
    cout << "in copy_constructor_test3" << endl;
}

A copy_constructor_test4(A& a) {
    cout << "in copy_constructor_test4" << endl;
    return a;
}

A& copy_constructor_test5(A& a) {
    cout << "in copy_constructor_test5" << endl;
    return a;
}


void func() {
    A a1 = A(1); //直接构造

    A a2(a1); //拷贝构造

    A a3 = a1; //拷贝构造

    copy_constructor_test1(a1); //拷贝构造

    copy_constructor_test2(a1); //直接构造

    A* p1 = &a1;
    copy_constructor_test3(p1); //直接构造

    A aa = copy_constructor_test4(a1); //拷贝构造

    A aa2 = copy_constructor_test5(a1); //拷贝构造

    ABC abc = {1, true, "test"}; //拷贝构造

    a2 = a1; //拷贝分配

}

int main(int argc, char const *argv[])
{
    func();
    return 0;
   
} 
