#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 常函数和非常函数
*/
class Test {
 public:
    int a_;
    Test(int a) : a_(a) {};

    Test& setA(int a) {
        this->a_ = a;
        return *this;
    }

    //const Test&表示返回值对象不可改变
    //setA(int a) const { 表式该函数不能改变属性 a_
    const Test& setA(int a) const {
        // this->a_ = a;
        return *this;
    }
};


int main(int argc, char const *argv[])
{
    Test test1 = Test(1);
    test1.setA(100);
    cout << test1.a_ << endl;

    const Test test2 = Test(1);
    test2.setA(200);
    cout << test2.a_ << endl;

    return 0;
}
