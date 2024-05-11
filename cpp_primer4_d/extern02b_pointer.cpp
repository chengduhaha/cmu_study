#include <iostream>
#include <string>
using namespace std;

/**
 * pointer指针
 * pointer vs reference： 引用需要初始化，指针不需要初始化
*/

int main(int argc, char const *argv[])
{
    int a = 1;
    int *b = &a; //&a 取出a的地址 赋值给b
    cout << "&a 取出 a 地址： "  <<   &a << endl;
    cout << "b 取出 a 地址： "  <<  b << endl;

    cout << "*b 取出 a 的值： "  <<  *b << endl;

    // 通过*b 可以改变 被指针 指向的 a 的值
    *b = 2;
    cout << "a 取出 a 的值： "  <<  a << endl;
    cout << "*b 取出 a 的值： "  <<  *b << endl;


    return 0;
}
