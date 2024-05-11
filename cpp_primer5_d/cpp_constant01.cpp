#include <iostream>
#include <string>
using namespace std;

/**
 * constant 常量 要进行初始化
*/

const int a = 0;
// const int b;
// b = 2;

void function(const int& value) {
    // value = 123; 不能对常量引用value进行修改
    cout << value << endl;
}


int main(int argc, char** argv) {

    cout << a << endl;
    function(1234);
    //非常量(non-const) 赋值给 常量(const) 没问题
    int i = 12345;
    const int& ir = i;
    const int &ir2 = i;
    /**
     * 第二行：const int& ir = i;
        第三行：const int &ir2 = i;
        在这两行中，ir 和 ir2 都是对整数变量 i 的引用，且因为它们是const引用，
        所以通过这两个引用你都不能修改 i 的值。
        空格的位置（在const和int之间，或者在&符号之前）对于语法是没有影响的，
        它们只是编码风格上的不同，C++编译器会理解这两种写法是等价的。
    */
    cout << ir << endl;
    cout << ir2 << endl;
    //常量(const)不能赋值给 非常量(non-const)
    // const int x = 1234;
    // int& x2 = x; 这行是错误的，不能进行赋值


    //不可以把常量赋值给指针
    // const int v = 123;
    // int *v = &v; 这行是错误的，不能进行赋值
    const int v = 123;
    const int *lv = &v; //常量指针是可以被常量赋值的
    cout << lv << endl;
    cout << *lv << endl;


    /**
     * low-level constant : 指针指向的地址可以被改变
     * const int 中const值修饰了 int 
     * const int *plow 从右往左读： 这是一个plow，指向了一个const int 常量指针，就是说该指针是指向常量的int值的地址，
     * 但没有说不可以换常量的int
    */
    const int low = 123;
    const int low2 = 456;
    const int *plow = &low;
    const int * plow2 = &low;
    /**
     * const int *plow = &low; 和 const int * plow2 = &low;
     * 两者代码在功能上也是没有区别的，它们都声明并初始化了一个指向const int类型的指针，该指针指向变量low。
     * 指针声明的语法允许在星号*周围有空格，这不影响其含义，因此上述两种写法均表示相同的概念：声明一个指针，该指针指向一个常量整数。
     * 
    */
    plow = &low2;
    cout << "*plow : " << *plow << endl;
    cout << "* plow2 : " << *plow2 << endl;
    
    /**
     * top-level constant ： 
     * const int * const ptop  从右往左读：这是一个常量的对象ptop，*指针 指向一个常量的int指针，int不能变
     * low 和 top 的区别是：
     * low的const修饰的基本类型，如int
     * top的const修饰的是符合类型，比如对象
    */
    const int top = 123;
    const int top2 = 456;
    const int * const ptop = &top;
    // ptop = &top2; //改行会报错
    cout << "*ptop : " << *ptop << endl;

    return 0;
}

