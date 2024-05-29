#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>  // 包含std::sort所需的头文件

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * lambda表达式
 * [capture list] (parameter list) -> retren type {function boly}
 * capture list为函数外的公共参数，如没有则写&
*/

//自定义比较器
bool want_greater(const int& i1,const int& i2) {
    return i1 > i2;
}

//用lambda自定义比较器
auto want_greater_lambda = [&](const int& i1,const int& i2) {
        return i1 > i2;
};

//用lambda自定义比较器2
int a = 1;

auto want_greater_lambda2 = [a](const int& i1,const int& i2) {
        cout << a << ".";
        return i1 > i2;
};

//用lambda自定义比较器3
auto want_greater_lambda3 = [a](const int& i1,const int& i2) -> bool {
        cout << a << ".";
        return i1 > i2;
};





void comparator1() {
    //排序从大到小
    

    cout << "=========排序 从大到小============" << endl;
    vector<int> v1 = {1,3,4,0,100,2,-1};
    std::sort(v1.begin(), v1.end(), want_greater_lambda3);
    for(int e: v1) {
        cout << e << " ";
    }
    cout << "\n" << endl;

    

}

int main(int argc, char const *argv[])
{
    comparator1();

    /**
    * & -> 捕捉引用
    * = -> 捕捉值
    */
    int b = 0;
    auto func1 = [&]() {
        return b;
    };

    auto func2 = [=]() {
        return b;
    };

    b = 1000;
    cout << func1() << endl;
    cout << func2() << endl;

    string x = "x";
    string y = "y";
    string z = "z";
    auto func4 = [&x,&y,z]() -> string {
        return x+y+z;
    };
    cout << func4() << endl;

    //在body中修改捕捉到的值 要加mutable
    int test = 1000;
    auto func5 = [test]() mutable {
        cout << ++test << endl;
    };
    func5();



    return 0;
}
