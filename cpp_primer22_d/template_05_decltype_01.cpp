
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
 * 在 C++ 中，decltype 关键字用于查询表达式的类型。
 * 它是 C++11 引入的一个特性，用于在编译时获取表达式的类型，而无需明确指定类型。这在泛型编程和模板编程中非常有用
*/

//获取变量的类型
void f1() {
    int a = 10;
    decltype(a) b = 20; // b 的类型与 a 相同，即 int
    std::cout << "Type of b: " << typeid(b).name() << ", Value of b: " << b << std::endl;
}
//获取表达式的类型
void f2() {
    int a = 10;
    float f = 3.14f;
    decltype(a + f) result = a + f; // result 的类型是 a + f 的类型，即 float
    std::cout << "Type of result: " << typeid(result).name() << ", Value of result: " << result << std::endl;
}

//在函数中使用 decltype 推导函数返回类型
template <typename T1, typename T2>
auto add(T1 a, T2 b) -> decltype(a+b) {
    return a+b;
}
void f3() {
    auto res = add(100, 3.1);
    cout << res << endl;
}

//与 decltype(auto) 结合使用  用于函数返回类型 c++14
// int& getReference(int& a) {
//     return a;
// }

// decltype(auto) getRef(int& a) {
//     return getReference(a); // 返回类型是 int&
// }
// void f4() {
//     int x = 10;
//     auto& y = getRef(x);
//     y = 20;
//     std::cout << "Value of x: " << x << std::endl; // 输出 20
// }

template <typename It>
auto func(It begin, It end) -> decltype(*begin){
    return *begin; //reference
}
void f5() {
    vector<int> v1 = {1,2,3};
    int& val = func(v1.begin(), v1.end());
    cout << "f5 val == " << val << endl;
    val = 100;
    cout << "f5 val == " << val << endl;
}


int main(int argc, char const *argv[])
{   
    f1();
    f2();
    f3();
    // f4();
    f5();
    return 0;
} 
