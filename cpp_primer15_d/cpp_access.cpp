#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * public
*/
class ParentClass {
 public:
    int a_;
    bool b_;

    ParentClass(int a, bool b) : a_(a), b_(b) {};

    void f1() {
        cout << this->a_ << " + " << this->b_ << endl; 
    }
};

/**
 * private + friend function
*/
void createSon(int &a, bool &b);
class Son {
    friend void createSon(int &a, bool &b);
 private:
    int a_;
    bool b_;
    Son(int a, bool b) : a_(a), b_(b) {};
    void son1() {
        cout << this->a_ << " + " << this->b_ << endl; 
    }
};

void createSon(int &a, bool &b) {
    Son son(a, b);
    son.son1();
}


/**
 * mutable : mutable关键字用于类的成员变量前，
 * 它改变了成员变量的常规“常量性”规则，
 * 允许在常量（const）对象或在常量成员函数中修改这个成员变量的值。
 * 这对于某些特殊场景非常有用，尤其是当成员变量表示某种可变状态，而这种状态的改变不影响对象的逻辑“恒常性”时。
*/
class Mutt {
 private: 
    int a_;
    int b_;
    mutable int c_; // mutable 成员变量
 public:
    Mutt(int a, int b, int c) : a_(a), b_(b), c_(c) {};
    int test() {
        return this->a_ += 1;
    }
    int test2() const {
        // return this->b_ += 1; 不能在这里修改，因为const修饰了 test2()
        return b_;
    }
    int test3() const {
        return this->c_ += 1; 
        // return b_;
    }
};

int main(int argc, char const *argv[])
{
    ParentClass parent(100, true);
    parent.f1();
    cout << parent.a_ << " + " << parent.b_ << endl;
    
    int x = 999;
    bool y = false;
    createSon(x, y);

    Mutt m(100, -199, 9191);
    cout << m.test() << endl;
    cout << m.test2() << endl;
    cout << m.test3() << endl;
    

    return 0;
}
