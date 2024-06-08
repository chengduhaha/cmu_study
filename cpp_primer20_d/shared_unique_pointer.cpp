#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>  // 包含std::sort所需的头文件

#include <memory> //shared_pointer

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

/**
 * smart pointer 智能指针 自动回收内存的对象
 * shared pointer 不推荐 对象所属权不清晰
 * unique pointer 推荐
 * 
 * std::unique_ptr是C++中一种智能指针，它拥有它所指向的对象的唯一所有权，并且在其生命周期结束时自动删除该对象，从而帮助防止内存泄漏
*/
void func() {
    std::shared_ptr<int> ptr = std::make_shared<int>(213);
    std::shared_ptr<int> ptr1(ptr); // copy constructor

    cout << ptr.use_count() << endl;
    cout << ptr1.use_count() << endl;

    {
        std::shared_ptr<int> ptr2(ptr);
        cout << ptr.use_count() << endl;
        cout << ptr2.use_count() << endl;
    }

    cout << ptr.use_count() << endl;
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class A{
 public:
    int a_;
    string b_;
    A(int a, string b) : a_(a),b_(b) {
        cout << "in constructor" << endl;
    };

    ~A() {
        cout << "delete constructor" << endl;
    }

};

void fun2() {
    cout << "begin fun2" << endl;
    std::unique_ptr<A> p1 = make_unique<A>(1,"stt");

    
}

int main(int argc, char const *argv[])
{
    func();
    fun2();
    cout << "end fun2" << endl;
}
