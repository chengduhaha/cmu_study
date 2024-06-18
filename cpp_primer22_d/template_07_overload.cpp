
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
 * 重载模板
 * 
 * 编译器执行同名方法的优先级：非模板方法 > 最符合的模板方法 > 一般符合的模板方法
*/
template <typename T1>
void f(T1& t1) {
    cout << "T1&" << endl;
}

template <typename T1>
void f(T1* t1) {
    cout << "T1*" << endl;
}

void f(string* t1) {
    cout << "string*" << endl;
}

int main(int argc, char const *argv[])
{   
    string s = "hello";
    f(s);
    f(&s);

    cout << "~~~~~~~~~~" << endl;
    int s2 = 102;
    f(s2);
    f(&s2);


    return 0;
} 
