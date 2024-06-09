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
 * 智能指针 可以自动回收没用的指针，不需要手动delete
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

/**
     * 没有in destructor来释放a1的内存空间 需要手动delete
     * [root@hadoop1 cpp_primer20_d]# ./smart_pointer 
        in constructor
        ok
     */
void no_smart_pointer() {
    
   A* a1 = new A(1,"aa");
   if(*(a1->a_) == 1) {
     cout << "ok" << endl;
    //  delete a1;  手动释放a1的内存空间 in destructor aa
     return;
   } else {
     cout << "sss" << endl;
     return;
   }
}

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

/**
 * 使用智能指针，自动回收内存空间
 * 自动调用~A()方法
 */
void smart_pointer() {
//    A* a1 = new A(1,"aa");
   std::unique_ptr<A> p1 = make_unique<A>(2,"p1");
   if(*(p1->a_) == 2) {
     cout << "ok smart" << endl;
    //  delete a1;  手动释放a1的内存空间 in destructor aa
     return;
   } else {
     cout << "sss smart" << endl;
     return;
   }
}

void throw_exception() {
    throw std::bad_exception();
}

/**
 * 当抛异常时，使用智能指针起作用，能够自动释放内存空间
 */
void smart_pointer2() {
//    A* a1 = new A(1,"aa");
   std::unique_ptr<A> p2 = make_unique<A>(3,"p2");
   try
   {
        throw_exception();
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   
}

/**
 * 自定义智能指针的析构函数：调用SelfDesctruction来释放自定义的资源，而不是让智能指针调用默认的~A()函数
 */
void SelfDesctruction(A* a) {
    delete a->a_;
    cout << "SelfDesctruction" << endl;
}
void self_destruction() {
    std::shared_ptr<A> p3(new A(4, "self-destruction"), SelfDesctruction);
}



int main(int argc, char const *argv[])
{
   no_smart_pointer();
   cout << "~~~~~~~~~~~~~~~~~~smart pointer" << endl;
   smart_pointer();
   cout << "~~~~~~~~~~~~~~~~~~smart pointer2" << endl;
   smart_pointer2();
   cout << "~~~~~~~~~~~~~~~~~~自定义desctruction" << endl;
   self_destruction();
   return 0;
   
} 
