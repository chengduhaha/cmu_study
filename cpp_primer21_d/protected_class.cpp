
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
 * protected 只能在子类的类内访问，或friend的body中访问
 * 
 * struct 和 class的区别是
 *  struct默认属性都是public，且继承public父类
 *  class默认属性都是private，且继承private父类
*/
class Base {
    friend void bb(Base& base);
 public:
    int a = 10;
 protected:
    int b = 11;
 private:
    int c = 12;
};

void bb(Base& base) {
    cout << base.b << endl;
}

class D : public Base {
 public:
    void f_public() {
        cout << a << endl;
    }
    void f_protected() {
        cout << b << endl;
    }
    void f_private() {
        // cout << c << endl; 无法访问private
    }
};


class E : private Base { //声明了private私有继承 ，则E无法访问Base的所有属性
    // public:
    // void e_public() {
    //     cout << a << endl;
    // }
    // void e_protected() {
    //     cout << b << endl;
    // }
};

int main(int argc, char const *argv[])
{   
    D d1 = D();
    d1.f_public();
    d1.f_protected();
    // d1.f_private(); 无法访问private

    Base b1 = Base();
    bb(b1);

    E e1 = E();
    e1.e_public();
    e1.e_protected();
    return 0;
} 
