#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 类的基础
*/
class A {
 public:
    int a_;

    //constructor 构造器
    A (int value) : a_(value) {};

    void f() {
        cout << a_ << endl;
    } 
};

class B {
 public:
    int b_;

    //constructor 构造器 explicit关键字必须显示调研构造函数 不能使用 B b=10来创建实例
    explicit B (int value) : b_(value) {};

    // const A * this , this是一个指针指向这个对象B
    void f() {
        // cout << b_ << endl;
        cout << this->b_ << endl;
    } 

    // const A * const this 用const修饰的this不能进行更改
    void f2() const {
        // cout << b_ << endl;
        // this->b_ = this->b_ * 100;
        cout << this->b_ << endl;
    } 

    B& combine(const B& rhs) {
        this->b_ += rhs.b_;
        return *this; //返回this指针执行的对象B
    }
};

int main(int argc, char const *argv[]){
    //创建A类的实例
    A a1(10);
    a1.f();

    A a2 = A(11);
    a2.f();

    A a3 = 12;
    a3.f();

    //B
    B b1(10);
    b1.f();

    B b2 = B(11);
    b2.f();

    // B b3 = 12;
    // b3.f();

    b2.f2();

    B b3 = B(100);
    b2 = b2.combine(b3);
    b2.f();
}
