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
 * 悬空指针：已经没有指针指向某对象，但是内存中还有其空间没有释放，导致内存泄漏。
 * 
 * 悬空指针（dangling pointer）是指指向已经释放或者无效内存区域的指针。
 * 当一个对象被删除或销毁，但仍然存在指向该对象的指针时，这些指针就变成了悬空指针。
 * 访问悬空指针会导致未定义行为，可能引起程序崩溃、数据损坏或者安全漏洞等问题。
 * 
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

int main(int argc, char const *argv[])
{   
    /**
     * new关键字主要用于在运行时动态地从堆上分配内存，并返回这块内存的地址，
     * 使得程序员能够灵活管理对象的生命周期。
     * 
     * 而不使用new时，对象的创建和销毁遵循自动存储的规则，更加自动化且受限于作用域。
     * 
     * 
     * 这里，A* a1声明了一个指向类型为A的对象的指针。
     * new A(100, "aaa")使用了动态内存分配来创建一个A类的新实例，并将其地址返回给指针a1。
     * 这种方式创建的对象位于堆上，生命周期不会随着离开作用域而自动结束，必须手动使用delete a1;来释放内存。
     * new关键字在C++中扮演着动态内存分配的关键角色。当使用new操作符时，
     * 它会在程序的堆内存中为指定的数据类型分配足够的空间，并返回该空间的地址。
     * 这对于创建对象或数组非常有用，尤其是在你想要创建一个生命周期独立于其创建点
     * （例如，在函数外部或需要长期存在的对象）的对象时。
     * 
     * 动态分配: new A(100, "aaa") 这部分代码会：

        在堆上查找足够大的空间来存放一个A类型的对象。
        调用A类的构造函数（带有两个参数：一个int和一个指向char的指针），
        使用传入的参数（100 和 "aaa"）来初始化这个新创建的对象。
        返回新创建对象的内存地址。
     * 指针存储: 
        A* a1 声明了一个指向A类型的指针，然后这个指针被赋予了新创建对象的地址。这
        意味着你可以通过指针a1来访问和操作堆上的那个A对象。   
     */
    A* a1 = new A(100, "aaa");


    /**
     * 这里，A a2声明了一个类型为A的自动存储对象。= A(100, "aaa")
     * 部分使用了拷贝构造函数（或在某些情况下是移动构造函数，取决于编译器优化）
     * 来初始化a2。构造函数同样接收两个参数初始化对象。与第一行不同，
     * 这个对象a2是在栈上创建的，其生命周期与声明它的作用域相关联。当离开作用域时，
     * a2会自动被销毁，无需手动管理内存。
     * 
     * 这里没有使用new关键字，因此过程有所不同：
        自动存储: A a2 直接在栈上创建了一个A类型的对象。接着= A(100, "aaa")
        通过拷贝构造函数（或在某些编译器优化下可能是移动构造函数）来初始化a2，传递相同的构造参数（100 和 "aaa"）。
        生命周期管理: a2对象的生命周期与定义它的作用域绑定。
        当离开该作用域时，编译器会自动销毁a2并释放其占用的栈内存，无需手动干预。
     */
    A a2 = A(100, "aaa");
    {
        std::shared_ptr<A> ptr(a1);
    }
    cout << a1->a_ << endl;
   
} 
