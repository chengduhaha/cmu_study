
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
 * 虚指针：不建议使用 无法管理指针的生命周期
 * C++中的虚指针（通常被称为vptr）是实现虚函数机制的基础。虚指针隐藏在类的实例中，
 * 指向一个虚函数表（vtable），这个表存放了类的虚函数的地址。
 * 
 * C++的虚函数和Java中的抽象类的抽象函数在概念上有一定的相似性，都是面向对象编程中用于实现多态（polymorphism）的机制，
 * 但它们之间也存在一些关键的区别。
 * 
    C++的虚函数
    定义：虚函数是在基类中定义的，使用virtual关键字标记的函数。它允许在派生类中被重写（override），
    通过基类指针或引用调用虚函数时，会根据实际对象的类型动态地调用到派生类中的实现。
    用途：主要用来实现运行时多态，使得基类的接口可以在派生类中有不同的实现。
    实现机制：通过虚函数表（vtable）和虚指针（vptr）。每个包含虚函数的类都有一个虚函数表，
    该表中存储了虚函数的地址，对象中包含一个指向虚函数表的指针。

    Java中的抽象函数
    定义：抽象函数是在抽象类中定义的，使用abstract关键字标记的函数，没有具体的实现。
    用途：强制要求继承此类的子类必须提供抽象函数的具体实现。抽象类不能被实例化，
    它的存在主要是为了被继承和提供一个或多个抽象函数的接口规范。
    与接口的关系：在Java中，抽象类可以有抽象函数和非抽象函数，也可以有状态（成员变量），
    而接口（interface）则只能有抽象函数（Java 8后可以有default方法和静态方法），不能有状态。

    关键区别
    实现方式：C++的虚函数通过虚函数表实现动态分派，而Java的抽象函数不涉及虚函数表，它是通过强制子类实现来达到多态的目的。
    存在位置：C++的虚函数可以存在于普通类或抽象类中，而Java的抽象函数只能存在于抽象类或接口中。
    是否必须重写：C++中，虚函数在派生类中可以重写也可以不重写，而Java的抽象函数在非抽象子类中必须被实现。
    语言特性：C++的虚函数是语言层面实现多态的主要机制，而Java中多态的体现不仅限于抽象函数，还包括接口的实现。
    */
class Father {
 public:
    virtual void show() {
        cout << "Father:show" << endl;
    }
    virtual ~Father() {} //析构函数也应该声明为虚函数
};

class Son : public Father {
 public:
    void show() {
        cout << "Son:show" << endl;
    }
};

void doShow(Father* father) {
    father->show(); // 这里调用的是虚函数，实际执行哪个函数取决于fatherPtr实际指向的对象类型
}


int main(int argc, char const *argv[])
{   
    Father* vptr1 = new Father();
    doShow(vptr1);

    Father* vptr2 = new Son();
    doShow(vptr2);
    return 0;
} 
