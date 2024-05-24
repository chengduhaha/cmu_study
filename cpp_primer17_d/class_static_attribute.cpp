#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::cout;
using std::endl;
using std::string;

/**
 * 静态成员变量和方法
 * static静态属性不随类的创建而创建，而是随程序main()来创建，静态属性一旦赋值就不会改变
 * 
 * 在 C++ 中，静态成员变量和静态成员函数（方法）属于类本身，而不是类的某个对象。
 * 静态成员变量在所有对象间共享，静态成员函数可以直接通过类名调用。
*/
class Test {
 public:
    int id_;
    static string name_; //静态成员变量在类中声明
    Test(int id):id_(id) {};
    static void static_function() { //静态成员函数可以在类内声明，并且可以直接通过类名调用。
        cout << "static function" << endl;
        cout << "static function + " << name_ << endl;
        // cout << "static function" << this->id_ << endl; 静态成员函数不能访问非静态成员变量和成员函数。
    }
};

string Test::name_ = "test"; //static 的属性在类外面进行赋值和实现 静态成员变量在类中声明，但必须在类外定义和初始化。

int main(int argc, char const *argv[])
{
    Test test1(1);
    Test test2(2);
    Test test3(3);
    cout << test1.id_ << endl;
    cout << test2.id_ << endl;
    cout << test3.id_ << endl;

    // cout << test1.static_function() << endl;
    // cout << test2.static_function() << endl;
    // cout << test3.static_function() << endl;

    Test::static_function();

    cout << Test::name_ << endl;

    return 0;
}
